#include <Arduino.h>

// Definizione dei PIN basata sul diagramma precedente
const int ldrPin = 34; 
const int ledPin = 21; 

// Variabili per la calibrazione dinamica
int sensorMin = 4095;  
int sensorMax = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(ledPin, LOW); 
  
  Serial.println("--- INIZIO FASE DI CALIBRAZIONE (5 SECONDI) ---");
  Serial.println(">> Sposta lo slider della luce su Wokwi per registrare i limiti! <<");

  unsigned long startTime = millis();
  
  while (millis() - startTime < 5000) {
    int sensorValue = analogRead(ldrPin);
    
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
    delay(10); 
  }
  
  Serial.println("--- CALIBRAZIONE COMPLETATA ---");
}

void loop() {
  // 1. Leggiamo la luce e calcoliamo la percentuale ambientale (0-100%)
  int currentValue = analogRead(ldrPin);
  // Nel caso di contrario invertire sensorMin e sensorMax
  int lightPercentage = map(currentValue, sensorMax, sensorMin, 0, 100);
  lightPercentage = constrain(lightPercentage, 0, 100);
  
  // ---------------------------------------------------------
  // 2. MISSIONE 3: Calcoliamo la luminosità inversa per il LED
  // ---------------------------------------------------------
  
  // Se la luce esterna è 90%, il LED sarà 10% (100 - 90 = 10)
  int ledPercentage = 100 - lightPercentage;
  
  // L'uscita PWM (analogWrite) richiede un valore da 0 (spento) a 255 (luminosità massima)
  // Mappiamo la percentuale (0-100) nella scala PWM (0-255)
  int pwmValue = map(ledPercentage, 0, 100, 0, 255);
  
  // Scriviamo il valore calcolato sul pin del LED per regolarne l'intensità
  analogWrite(ledPin, pwmValue); 
  
  // Mostriamo i dati sulla Seriale per verificare che i calcoli siano corretti
  Serial.print("Luce Ambiente: ");
  Serial.print(lightPercentage);
  Serial.print("%  |  Luce LED: ");
  Serial.print(ledPercentage);
  Serial.println("%");
  
  // Ho ridotto il delay a 100ms (1 decimo di secondo) per rendere 
  // la transizione della luce del LED molto più fluida e reattiva
  delay(100); 
}