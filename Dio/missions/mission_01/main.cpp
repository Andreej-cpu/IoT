#include <Arduino.h>

// Definiamo il pin del LED collegato all'ESP32
const int LED_PIN = 21;

void setup() {
  // Configura il pin 21 come uscita digitale
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Il ciclo parte da 4000 ms (4 secondi) e si dimezza a ogni iterazione
  // Condizione di arresto: quando scende sotto i 125 ms
  for (int t = 4000; t >= 125; t = t / 2) {
    
    // Accende il LED
    digitalWrite(LED_PIN, HIGH);
    delay(t);
    
    // Spegne il LED
    digitalWrite(LED_PIN, LOW);
    delay(t);
    
  }
  // Una volta usciti dal ciclo for, il loop() ricomincia 
  // automaticamente da capo, resettando il tempo a 4 secondi.
}