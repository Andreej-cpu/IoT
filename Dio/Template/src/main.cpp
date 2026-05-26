#include <Arduino.h>

// Definizione del pin del LED (secondo il circuito Wokwi di base, pin 21)
const int ledPin = 21; 

// Array contenente i tempi di accensione e spegnimento in millisecondi
const int delays[] = {100, 250, 500, 1000, 2000, 4000};
const int numSteps = sizeof(delays) / sizeof(delays[0]);

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Ciclo attraverso tutti gli step definiti
  for (int i = 0; i < numSteps; i++) {
    // LED ON
    digitalWrite(ledPin, HIGH);
    delay(delays[i]);
    
    // LED OFF
    digitalWrite(ledPin, LOW);
    delay(delays[i]);
  }
}