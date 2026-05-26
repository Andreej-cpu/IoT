#include <Arduino.h>
#include <DHT.h>

// --- PIN MISSIONI PRECEDENTI ---
const int ldrPin = 34; // Sensore di luce (Pin VP nel JSON precedente, qui impostato su 34)
const int ledPin = 21; // LED Cyan

// --- PIN E CONFIGURAZIONE MISSIONE 4 (DHT11) ---
const int dhtPin = 23;      // Il sensore DHT11 è connesso al GPIO 23 dell'ESP32
#define DHTTYPE DHT11       // Specifichiamo il tipo di sensore (DHT11)

// Inizializziamo l'oggetto DHT passandogli il PIN e il Tipo
DHT dht(dhtPin, DHTTYPE);

// Variabili Calibrazione Luce
int sensorMin = 4095;  
int sensorMax = 0;

void setup() {
  Serial.begin(115200);
  
  // Configurazione PIN standard
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); 
  
  // Inizializza il sensore DHT11
  dht.begin();
  
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
  // ==========================================
  // MISSIONE 2 & 3: Gestione Luce Ambiente e LED
  // ==========================================
  int currentLight = analogRead(ldrPin);
  int lightPercentage = map(currentLight, sensorMin, sensorMax, 0, 100);
  lightPercentage = constrain(lightPercentage, 0, 100);
  
  int ledPercentage = 100 - lightPercentage;
  int pwmValue = map(ledPercentage, 0, 100, 0, 255);
  analogWrite(ledPin, pwmValue); 
  
  // ==========================================
  // MISSIONE 4: Lettura Temperatura Digitale DHT11
  // ==========================================
  
  // Leggiamo la temperatura in gradi Celsius (il sensore impiega circa 250 millisecondi)
  float temperatureC = dht.readTemperature();
  
  // Opzionale: Il DHT11 legge anche l'umidità! Se serve, decommenta la riga sotto
  // float humidity = dht.readHumidity();
  
  // Controllo di sicurezza: se il sensore fallisce la lettura (es. cavo scollegato) restituisce NaN (Not a Number)
  if (isnan(temperatureC)) {
    Serial.println("Errore: Impossibile leggere dal sensore DHT11! Controlla i collegamenti.");
  } else {
    // Stampa tutti i dati combinati sul Serial Monitor ogni secondo
    Serial.print("Luce Ambiente: "); Serial.print(lightPercentage); Serial.print("% | ");
    Serial.print("LED: "); Serial.print(ledPercentage); Serial.print("% | ");
    Serial.print("Temperatura: "); Serial.print(temperatureC); Serial.println(" °C");
    
    // Se hai decommentato l'umidità e vuoi stamparla:
    // Serial.print(" | Umidità: "); Serial.print(humidity); Serial.println("%");
  }
  
  // Pausa di 1 secondo prima del prossimo ciclo (come richiesto dalla slide)
  delay(1000); 
}