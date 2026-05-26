#include <Arduino.h>

// --- PIN CONFIGURATION ---
const int ldrPin  = 34; // Sensore di luce (mantenuto dalle missioni precedenti)
const int ledPin  = 21; // LED Cyan (mantenuto dalle missioni precedenti)
const int tempPin = 35; // Pin analogico ADC per il sensore di temperatura TMP36

// Variabili Calibrazione Luce
int sensorMin = 4095;  
int sensorMax = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(tempPin, INPUT); // Configura il pin del sensore di temperatura
  
  digitalWrite(ledPin, LOW); 
  
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
  // --- GESTIONE LUCE AMBIENTE E LED (Missioni 2 & 3) ---
  int currentLight = analogRead(ldrPin);
  int lightPercentage = map(currentLight, sensorMin, sensorMax, 0, 100);
  lightPercentage = constrain(lightPercentage, 0, 100);
  
  int ledPercentage = 100 - lightPercentage;
  int pwmValue = map(ledPercentage, 0, 100, 0, 255);
  analogWrite(ledPin, pwmValue); 
  
  // --- MISSIONE 4: LETTURA E CALCOLO TMP36 ---
  
  // 1. Legge il valore analogico grezzo (0 - 4095)
  int rawADC = analogRead(tempPin);
  
  // 2. Converte il valore grezzo in Volt effettivi (L'ESP32 lavora a 3.3V)
  float voltage = (rawADC / 4095.0) * 3.3;
  
  // 3. Formula specifica per il TMP36 (Offset di 0.5V, pendenza 10mV/°C)
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Stampa dei dati sul Serial Monitor
  Serial.print("[TMP36] Tensione: "); Serial.print(voltage, 3); Serial.print(" V | ");
  Serial.print("Temperatura: "); Serial.print(temperatureC, 1); Serial.print(" °C | ");
  Serial.print("Luce: "); Serial.print(lightPercentage); Serial.println("%");
  
  // Lettura e aggiornamento ogni secondo (come richiesto dalle specifiche)
  delay(1000); 
}