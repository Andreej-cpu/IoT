#include <Arduino.h>

// --- PIN CONFIGURATION ---
const int greenLedPin = 22;  // LED Verde (GPIO 23 - Pin USABLE)
const int yellowLedPin = 21; // LED Giallo (GPIO 22 - Pin USABLE)
const int redLedPin = 23;    // LED Rosso (GPIO 21 - Pin USABLE)

// --- BLINK INTERVALS ---
const unsigned long greenInterval = 2000;  // 2 secondi
const unsigned long yellowInterval = 1000; // 1 secondo
const unsigned long redInterval = 500;     // 500 ms

// --- STATE VARIABLES ---
unsigned long lastGreenTime = 0;
bool greenState = false;

unsigned long lastYellowTime = 0;
bool yellowState = false;

unsigned long lastRedTime = 0;
bool redState = false;

void setup() {
  // Inizializzazione Seriale per il debug
  Serial.begin(115200);

  // Configurazione dei PIN di output
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Stato iniziale (tutti spenti)
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  Serial.println("--- MISSIONE 12: DON'T LED ME DOWN INIZIALIZZATA ---");
  Serial.println("LED Verde (GPIO 23): 2000ms ON / 2000ms OFF");
  Serial.println("LED Giallo (GPIO 22): 1000ms ON / 1000ms OFF");
  Serial.println("LED Rosso (GPIO 21): 500ms ON / 500ms OFF");
  Serial.println("----------------------------------------------------");
}

void loop() {
  unsigned long currentMillis = millis();

  // 1. Gestione LED Verde
  if (currentMillis - lastGreenTime >= greenInterval) {
    lastGreenTime = currentMillis;
    greenState = !greenState;
    digitalWrite(greenLedPin, greenState ? HIGH : LOW);
    Serial.print("[VERDE] Stato cambiato in: ");
    Serial.println(greenState ? "ON" : "OFF");
  }

  // 2. Gestione LED Giallo
  if (currentMillis - lastYellowTime >= yellowInterval) {
    lastYellowTime = currentMillis;
    yellowState = !yellowState;
    digitalWrite(yellowLedPin, yellowState ? HIGH : LOW);
    Serial.print("[GIALLO] Stato cambiato in: ");
    Serial.println(yellowState ? "ON" : "OFF");
  }

  // 3. Gestione LED Rosso
  if (currentMillis - lastRedTime >= redInterval) {
    lastRedTime = currentMillis;
    redState = !redState;
    digitalWrite(redLedPin, redState ? HIGH : LOW);
    Serial.print("[ROSSO] Stato cambiato in: ");
    Serial.println(redState ? "ON" : "OFF");
  }
}
