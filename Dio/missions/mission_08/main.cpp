#include <Arduino.h>

// --- PIN CONFIGURATION ---
const int pirPin = 12;  // Pin di input per il sensore PIR (GPIO 12)
const int ledPin = 14;  // Pin di output per il LED Giallo (GPIO 14)

// --- STATE VARIABLES (volatile for Interrupts) ---
volatile bool motionDetected = false;
volatile bool stateChanged = false;

// --- ISR FOR PIR MOTION SENSOR ---
// Questa ISR viene chiamata su ogni variazione (CHANGE) del pin OUT del sensore PIR
void IRAM_ATTR handlePirChange() {
  motionDetected = digitalRead(pirPin);
  stateChanged = true;
}

void setup() {
  // Inizializzazione Seriale per il debug
  Serial.begin(115200);
  
  // Configurazione dei PIN
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  
  // Stato di partenza
  motionDetected = digitalRead(pirPin);
  digitalWrite(ledPin, motionDetected ? HIGH : LOW);
  
  // Associazione dell'interrupt hardware sul pin del PIR su evento CHANGE
  attachInterrupt(digitalPinToInterrupt(pirPin), handlePirChange, CHANGE);
  
  Serial.println("--- MISSIONE 08: L'INTRUSO ---");
  Serial.print("Stato iniziale sensore PIR: ");
  Serial.println(motionDetected ? "Movimento rilevato!" : "Nessun movimento");
  Serial.println("Pronto a rilevare intrusi.");
}

void loop() {
  // Gestione dell'evento in maniera non bloccante
  if (stateChanged) {
    stateChanged = false; // Reset del flag di stato
    
    // Leggi in sicurezza la variabile volatile
    bool isMoving = motionDetected;
    
    if (isMoving) {
      digitalWrite(ledPin, HIGH);
      Serial.println("[ALLERTA] Intruso rilevato! Sensore PIR attivo, LED giallo acceso.");
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("[RIPRISTINO] Nessun movimento. LED giallo spento.");
    }
  }
}
