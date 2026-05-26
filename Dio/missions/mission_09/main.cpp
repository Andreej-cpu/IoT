#include <Arduino.h>

// --- PIN CONFIGURATION ---
const int pirPin = 12;       // Sensore PIR (GPIO 12)
const int yellowLedPin = 14; // LED Giallo (GPIO 14)
const int redLedPin = 27;    // LED Rosso (GPIO 27)
const int trigPin = 26;      // HC-SR04 TRIG (GPIO 26)
const int echoPin = 25;      // HC-SR04 ECHO (GPIO 25)

// --- CONSTANTS ---
const float thresholdDistanceCm = 100.0; // Soglia critica di distanza (100 cm)

// --- STATE VARIABLES (volatile for Interrupts) ---
volatile bool motionDetected = false;
volatile bool motionStateChanged = false;

volatile unsigned long echoStart = 0;
volatile unsigned long echoEnd = 0;
volatile bool newDistanceAvailable = false;

// --- TIMER VARIABLES ---
unsigned long lastTriggerTime = 0;
const unsigned long triggerIntervalMs = 500; // Misurazione ogni 500ms

// --- APP STATE ---
float lastDistanceCm = 400.0; // Distanza di default iniziale (fuori soglia)

// --- ISR FOR PIR MOTION SENSOR ---
void IRAM_ATTR handlePirChange() {
  motionDetected = digitalRead(pirPin);
  motionStateChanged = true;
}

// --- ISR FOR ULTRASONIC SENSOR ECHO ---
void IRAM_ATTR handleEchoChange() {
  unsigned long timeMicros = micros();
  if (digitalRead(echoPin) == HIGH) {
    echoStart = timeMicros;
  } else {
    if (echoStart != 0) {
      echoEnd = timeMicros;
      newDistanceAvailable = true;
    }
  }
}

void setup() {
  // Inizializzazione della porta Seriale per il debug
  Serial.begin(115200);

  // Configurazione dei PIN di output
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(trigPin, OUTPUT);

  // Configurazione dei PIN di input
  pinMode(pirPin, INPUT);
  pinMode(echoPin, INPUT);

  // Assicuraimoci che i trigger partano bassi e i LED siano spenti
  digitalWrite(trigPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  // Stato iniziale dei sensori
  motionDetected = digitalRead(pirPin);
  digitalWrite(yellowLedPin, motionDetected ? HIGH : LOW);

  // Associazione degli Interrupt Hardware
  attachInterrupt(digitalPinToInterrupt(pirPin), handlePirChange, CHANGE);
  attachInterrupt(digitalPinToInterrupt(echoPin), handleEchoChange, CHANGE);

  Serial.println("--- MISSIONE 09: ULTRASONIC YO INIZIALIZZATA ---");
  Serial.print("Stato iniziale PIR: ");
  Serial.println(motionDetected ? "Movimento!" : "Nessun movimento");
  Serial.print("Soglia di allerta critica impostata a: ");
  Serial.print(thresholdDistanceCm);
  Serial.println(" cm");
  Serial.println("-------------------------------------------------");
}

void loop() {
  unsigned long currentMillis = millis();

  // 1. Invio del trigger per la misurazione a ultrasuoni ogni 500ms (non bloccante)
  if (currentMillis - lastTriggerTime >= triggerIntervalMs) {
    lastTriggerTime = currentMillis;
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Impulso di trigger standard da 10us
    digitalWrite(trigPin, LOW);
  }

  // 2. Lettura e calcolo della distanza quando disponibile (non bloccante tramite ISR)
  if (newDistanceAvailable) {
    unsigned long duration = 0;

    // Sezione critica per leggere in sicurezza le variabili volatili
    noInterrupts();
    if (echoEnd > echoStart) {
      duration = echoEnd - echoStart;
    }
    echoStart = 0; // Resettiamo lo start per la misurazione successiva
    newDistanceAvailable = false;
    interrupts();

    if (duration > 0) {
      // Calcolo della distanza: tempo di volo diviso 58 (velocità del suono)
      lastDistanceCm = (float)duration / 58.0;

      // Stampa la distanza rilevata
      Serial.print("Distanza misurata: ");
      Serial.print(lastDistanceCm, 1);
      Serial.println(" cm");
    }
  }

  // 3. Gestione dello stato del sensore PIR e del LED giallo
  if (motionStateChanged) {
    motionStateChanged = false;
    bool isMoving = motionDetected;

    if (isMoving) {
      digitalWrite(yellowLedPin, HIGH);
      Serial.println("[PIR] Movimento rilevato! LED giallo ACCESO.");
    } else {
      digitalWrite(yellowLedPin, LOW);
      Serial.println("[PIR] Nessun movimento. LED giallo SPENTO.");
    }
  }

  // 4. Verifica e gestione della condizione critica (PIR attivo AND distanza < soglia)
  bool isMoving = motionDetected; // Lettura sicura della variabile volatile
  bool isCritical = isMoving && (lastDistanceCm < thresholdDistanceCm);

  static bool lastCriticalState = false;
  if (isCritical != lastCriticalState) {
    lastCriticalState = isCritical;
    if (isCritical) {
      digitalWrite(redLedPin, HIGH);
      Serial.print("[ALLERTA CRITICA] Movimento rilevato entro la soglia di sicurezza! Distanza: ");
      Serial.print(lastDistanceCm, 1);
      Serial.println(" cm. LED rosso ACCESO.");
    } else {
      digitalWrite(redLedPin, LOW);
      Serial.println("[RIPRISTINO] Condizione critica rientrata. LED rosso SPENTO.");
    }
  }
}
