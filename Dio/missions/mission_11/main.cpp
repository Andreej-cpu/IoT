#include <Arduino.h>

const int ledPin = 23;                 // LED Rosso connesso a GPIO 23 (priorità secondo README)
const unsigned long intervalMs = 182;  // Intervallo di 182 ms per stato (ON/OFF)

unsigned long lastToggleTime = 0;
bool ledState = false;
int toggleCount = 0;                   // Conta le transizioni. 20 cicli ON/OFF = 40 transizioni (20 ON e 20 OFF)
bool isBlinking = true;

void setup() {
  // Inizializzazione Seriale per il debug
  Serial.begin(115200);
  
  // Configurazione PIN
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  Serial.println("--- MISSIONE 11: BLINK AVVIATA ---");
  Serial.println("Parametri: 182ms ON, 182ms OFF. Limite: 20 cicli.");
  
  // Accensione iniziale
  ledState = true;
  digitalWrite(ledPin, HIGH);
  lastToggleTime = millis();
  toggleCount = 1; // Prima transizione (acceso)
  Serial.println("Lampeggiamento 1: ON");
}

void loop() {
  if (isBlinking) {
    unsigned long currentMillis = millis();
    if (currentMillis - lastToggleTime >= intervalMs) {
      lastToggleTime = currentMillis;
      
      // Inverti lo stato del LED
      ledState = !ledState;
      digitalWrite(ledPin, ledState ? HIGH : LOW);
      
      toggleCount++;
      
      // Logica di stampa del ciclo corrente
      if (ledState) {
        int cycle = (toggleCount + 1) / 2;
        Serial.print("Lampeggiamento ");
        Serial.print(cycle);
        Serial.println(": ON");
      } else {
        int cycle = toggleCount / 2;
        Serial.print("Lampeggiamento ");
        Serial.print(cycle);
        Serial.println(": OFF");
      }
      
      // Se abbiamo completato 20 cicli completi (40 transizioni)
      if (toggleCount >= 40) {
        isBlinking = false;
        digitalWrite(ledPin, LOW); // Assicura che si spenga
        Serial.println("Finito! Lampeggiamento terminato con successo dopo 20 ripetizioni.");
      }
    }
  }
}
