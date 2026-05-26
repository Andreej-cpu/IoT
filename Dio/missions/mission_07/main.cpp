#include <Arduino.h>

// --- PIN CONFIGURATION ---
const int ledPin = 21;       // PIN del LED
const int buttonAPin = 4;    // Pulsante A (Dimezza il tempo)
const int buttonBPin = 5;    // Pulsante B (On/Off - Interrompe tutto)

// --- VARIABILI DI STATO (Volatili per Interrupt) ---
volatile unsigned long lastDebounceA = 0;
volatile unsigned long lastDebounceB = 0;
const unsigned long debounceDelay = 250; // Debounce di 250ms

// Array dei tempi di lampeggio (semoperiodo)
const unsigned long intervalli[] = {4000, 2000, 1000, 500, 250, 125};
const int numeroStati = 6;
volatile int statoAttuale = 0; 

// Flag booleano per tracciare lo stato del sistema (true = funzionante, false = interrotto)
volatile bool sistemaAttivo = true; 

// --- VARIABILI GESTIONE LAMPEGGIO ---
unsigned long previousMillis = 0;
bool ledState = LOW;

// --- ISR PULSANTE A (Dimezza il tempo) ---
void IRAM_ATTR handleButtonAPress() {
  unsigned long currentTime = millis();
  
  // Il pulsante A ha effetto SOLO SE il sistema è attivo
  if (sistemaAttivo && (currentTime - lastDebounceA > debounceDelay)) {
    statoAttuale++;
    if (statoAttuale >= numeroStati) {
      statoAttuale = 0; // Ricomincia da 4s se supera il limite minimo
    }
    lastDebounceA = currentTime;
  }
}

// --- ISR PULSANTE B (Attiva / Disattiva tutto) ---
void IRAM_ATTR handleButtonBPress() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastDebounceB > debounceDelay) {
    sistemaAttivo = !sistemaAttivo; // Inverte lo stato del sistema
    
    // Specifica della slide: quando si riattiva, ricomincia dall'intervallo iniziale di 4 secondi
    if (sistemaAttivo) {
      statoAttuale = 0; 
    }
    
    lastDebounceB = currentTime;
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(ledPin, OUTPUT);
  
  // Configurazione dei pulsanti in INPUT_PULLUP (GND comune)
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
  
  // Collegamento degli Interrupt ad entrambi i pulsanti sul fronte di discesa
  attachInterrupt(digitalPinToInterrupt(buttonAPin), handleButtonAPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonBPin), handleButtonBPress, FALLING);
  
  Serial.println("--- MISSIONE 7 AVVIATA ---");
  Serial.println("Sistema partitò in modalità ATTIVA (Lampeggio 4s).");
}

void loop() {
  // Se il sistema è stato disattivato dal Pulsante B
  if (!sistemaAttivo) {
    if (ledState != LOW) {
      ledState = LOW;
      digitalWrite(ledPin, ledState); // Assicuriamoci che il LED rimanga spento durante l'interruzione
      Serial.println("[SISTEMA FERMO] Lampeggio interrotto. Pulsante A disabilitato.");
    }
    delay(100); // Riduce il carico sulla CPU quando il loop è in attesa
    return;     // Salta il resto del codice del loop
  }

  // --- Gestione normale del lampeggio (Se il sistema è attivo) ---
  unsigned long currentMillis = millis();
  unsigned long intervalloCorrente = intervalli[statoAttuale];
  
  if (currentMillis - previousMillis >= intervalloCorrente) {
    previousMillis = currentMillis;
    
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    
    // Stampa i dati correnti per il debug
    Serial.print("Lampeggio Attivo | Intervallo corrente: ");
    Serial.print((float)intervalloCorrente / 1000.0, 3);
    Serial.println(" s");
  }
}