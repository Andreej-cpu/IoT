#include <Arduino.h>

// --- PIN CONFIGURATION ---
const int ledPin = 21;    // PIN del LED
const int buttonPin = 4;  // PIN del Pulsante (Userà l'Interrupt)

// --- VARIABILI DI STATO (Volatili perché usate dentro l'Interrupt) ---
volatile unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 250; // 250 millisecondi per evitare il bouncing

// Array con i tempi di semipresenza (metà periodo) in millisecondi:
// 4s = 4000ms, 2s = 2000ms, 1s = 1000ms, 0.5s = 500ms, 0.25s = 250ms, 0.125s = 125ms
const unsigned long intervalli[] = {4000, 2000, 1000, 500, 250, 125};
const int numeroStati = 6;
volatile int statoAttuale = 0; // Indice dell'intervallo corrente

// --- VARIABILI GESTIONE LAMPEGGIO (Non bloccante nel Loop) ---
unsigned long previousMillis = 0;
bool ledState = LOW;

// --- FUNZIONE INTERRUPT (ISR) ---
// Viene eseguita istantaneamente quando si preme il tasto
void IRAM_ATTR handleButtonPress() {
  unsigned long currentTime = millis();
  
  // Gestione del bouncing: ignora i click troppo vicini tra loro
  if ((currentTime - lastDebounceTime) > debounceDelay) {
    statoAttuale++; // Passa all'intervallo successivo (dimezza il tempo)
    
    // Se superiamo l'ultimo stato (0.125s), ricomincia da 4 secondi (indice 0)
    if (statoAttuale >= numeroStati) {
      statoAttuale = 0;
    }
    
    lastDebounceTime = currentTime; // Aggiorna il tempo dell'ultimo click valido
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(ledPin, OUTPUT);
  
  // Configura il pulsante in INPUT_PULLUP: 
  // - Non premuto = HIGH
  // - Premuto = LOW (Cortocircuito verso GND)
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Collega l'Interrupt sul fronte di discesa (FALLING: da HIGH a LOW, ovvero quando premi)
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
  
  Serial.println("--- MISSIONE 6 AVVIATA ---");
  Serial.println("Il LED lampeggia. Premi il tasto per accelerare!");
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Recupera l'intervallo di tempo corrente in modo sicuro
  unsigned long intervalloCorrente = intervalli[statoAttuale];
  
  // Gestione del lampeggio senza usare delay()
  if (currentMillis - previousMillis >= intervalloCorrente) {
    previousMillis = currentMillis; // Salva l'ultimo cambio di stato
    
    // Inverte lo stato del LED
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    
    // Stampa di controllo sulla seriale ad ogni lampeggio
    Serial.print("Lampeggio attivo - Intervallo: ");
    Serial.print((float)intervalloCorrente / 1000.0, 3);
    Serial.println(" secondi.");
  }
}