#include <Arduino.h>

// --- PIN SENSORI ---
const int ldrPin  = 34; // Sensore di luce
const int tempPin = 35; // Sensore di temperatura LM35

// --- PIN LED SEMAFORO ---
const int ledGreen  = 18; // GPIO 18 -> LED Verde
const int ledYellow = 21; // GPIO 21 -> LED Giallo
const int ledRed    = 19; // GPIO 19 -> LED Rosso

// --- SOGLIE ALERT ---
const float SOGLIA_TEMP = 30.0; // Soglia Temperatura in °C
const int SOGLIA_LUCE   = 60;   // Soglia Luce in %

// Variabili Calibrazione Luce
int sensorMin = 4095;  
int sensorMax = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(ldrPin, INPUT);
  pinMode(tempPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  
  // FASE DI CALIBRAZIONE LUCE (5 Secondi)
  Serial.println("--- INIZIO CALIBRAZIONE LUCE (5 SECONDI) ---");
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    int sensorValue = analogRead(ldrPin);
    if (sensorValue > sensorMax) sensorMax = sensorValue;
    if (sensorValue < sensorMin) sensorMin = sensorValue;
    delay(10); 
  }
  Serial.println("--- CALIBRAZIONE COMPLETATA ---");
  Serial.println("----------------------------------------------");
}

void loop() {
  // 1. Elaborazione Luce Ambiente
  int currentLight = analogRead(ldrPin);
  int lightPercentage = map(currentLight, sensorMin, sensorMax, 0, 100);
  lightPercentage = constrain(lightPercentage, 0, 100);
  
  // 2. Elaborazione Temperatura LM35
  int rawADC = analogRead(tempPin);
  float voltage = (rawADC / 4095.0) * 3.3;
  float temperatureC = voltage * 100.0; // Formula LM35
  
  // 3. Verifica delle soglie
  bool troppaLuce = (lightPercentage > SOGLIA_LUCE);
  bool troppoCaldo = (temperatureC > SOGLIA_TEMP);
  
  // Reset LED
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  
  // 4. Logica del Semaforo
  if (troppaLuce && troppoCaldo) {
    digitalWrite(ledRed, HIGH);
    Serial.print("[ALERT ROSSO] ");
  } 
  else if (troppaLuce || troppoCaldo) {
    digitalWrite(ledYellow, HIGH);
    Serial.print("[WARNING GIALLO] ");
  } 
  else {
    digitalWrite(ledGreen, HIGH);
    Serial.print("[STATUS OK VERDE] ");
  }
  
  // Stampa riepilogativa
  Serial.print("Luce: "); Serial.print(lightPercentage); Serial.print("% | ");
  Serial.print("Temp [LM35]: "); Serial.print(temperatureC, 1); Serial.println(" °C");
  
  delay(1000); 
}