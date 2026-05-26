#include <Arduino.h>

// Definizione dei PIN basata sul diagramma
const int ldrPin = 34; // Pin collegato all'analog out del fotoresistore (GPIO 34)
const int ledPin = 21; // Pin del LED Cyan (configurato ma non usato per il lampeggio)

// Variabili per la calibrazione dinamica
int sensorMin = 4095;  // L'ADC dell'ESP32 ha una risoluzione a 12-bit (valori da 0 a 4095)
int sensorMax = 0;

void setup() {
  // Inizializzazione della comunicazione seriale a 115200 baud
  Serial.begin(115200);
  
  // Configurazione dei PIN
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Manteniamo il LED spento come da specifiche della consegna
  digitalWrite(ledPin, LOW); 
  
  Serial.println("--- INIZIO FASE DI CALIBRAZIONE (5 SECONDI) ---");
  Serial.println(">> Clicca sul fotoresistore e muovi lo slider per catturare Buio e Luce! <<");

  // Salva il millisecondo di partenza
  unsigned long startTime = millis();
  
  // Ciclo di calibrazione che dura esattamente 5 secondi
  while (millis() - startTime < 5000) {
    int sensorValue = analogRead(ldrPin);
    
    // Registra il valore massimo letto (Buio)
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    
    // Registra il valore minimo letto (Luce)
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
    
    delay(10); // Breve pausa per stabilizzare le letture del convertitore ADC
  }
  
  Serial.println("--- CALIBRAZIONE COMPLETATA ---");
  Serial.print("Valore minimo registrato (Luce/Min): "); Serial.println(sensorMin);
  Serial.print("Valore massimo registrato (Buio/Max): "); Serial.println(sensorMax);
  Serial.println("----------------------------------------------");
}

void loop() {
  // Leggi il valore analogico attuale dal fotoresistore
  int currentValue = analogRead(ldrPin);
  
  // Mappa il valore letto sulla scala percentuale 0% - 100%
  // NOTA: Con la nostra configurazione, sensorMax rappresenta il Buio (0%) e sensorMin la Luce (100%)
  int lightPercentage = map(currentValue, sensorMax, sensorMin, 0, 100);
  
  // Vincola il valore nel range 0-100 per evitare sbalzi oltre i limiti calibrati
  lightPercentage = constrain(lightPercentage, 0, 100);
  
  // Mostra il livello di luce sulla Serial Monitor di Wokwi
  Serial.print("Livello di luce attuale: ");
  Serial.print(lightPercentage);
  Serial.println("%");
  
  delay(500); // Aggiorna la lettura ogni 500 millisecondi
}