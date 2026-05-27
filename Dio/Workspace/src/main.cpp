#include <Arduino.h>

// Definizione dei pin forniti
const int greenLedPin = 23;  // LED Verde
const int yellowLedPin = 22; // LED Giallo
const int redLedPin = 21;    // LED Rosso
const int pinLDR = 34;       // Fotoresistore (GPIO 34)

// Pin per l'interrupt (es. un pulsante di reset o switch di sicurezza)
const int pinInterrupt = 19; 

// --- CONFIGURAZIONE SOGLIE FISSE (Dal TIP della traccia) ---
// Modifica questi valori in base alle letture reali del tuo ambiente
const int SOGLIA_MEDIA = 1500;   
const int SOGLIA_MASSIMA = 3000; 

// Variabile condivisa con l'interrupt: DEVE essere "volatile"
volatile bool interruptRilevato = false;

// Funzione ISR (Interrupt Service Routine) salvata nella RAM veloce
void IRAM_ATTR gestioneInterrupt() {
  interruptRilevato = true; 
}

void setup() {
  Serial.begin(115200);

  // Configurazione pin LED come uscite digitali standard
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  
  // Configurazione pin Interrupt con pull-up interno
  pinMode(pinInterrupt, INPUT_PULLUP);
  
  // Aggancio dell'interrupt sul fronte di discesa (pressione del pulsante)
  attachInterrupt(digitalPinToInterrupt(pinInterrupt), gestioneInterrupt, FALLING);

  Serial.println("--- Sistema Alert Pronto (Soglie Fisse) ---");
  Serial.print("Soglia Media impostata a: "); Serial.println(SOGLIA_MEDIA);
  Serial.print("Soglia Massima impostata a: "); Serial.println(SOGLIA_MASSIMA);
  Serial.println("----------------------------------------");
}

void loop() {
  // Gestione immediata dell'evento scatenato dall'interrupt
  if (interruptRilevato) {
    Serial.println("⚠️ [INTERRUPT] Rilevato evento critico hardware!");
    // Inserire qui eventuale logica di reset o sicurezza
    interruptRilevato = false; // Resetta il flag
  }

  // Legge il valore attuale del fotoresistore (0 - 4095)
  int luceAmbiente = analogRead(pinLDR);
  
  // Stampa il valore per aiutarti a tarare le soglie definitive
  Serial.print("Valore LDR: ");
  Serial.println(luceAmbiente);

  // --- LOGICA DEI LIVELLI DI ALERT ---
  if (luceAmbiente > SOGLIA_MASSIMA) {
    // ROSSO: Superata anche la soglia massima
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  } 
  else if (luceAmbiente > SOGLIA_MEDIA) {
    // GIALLO: Superata la soglia media ma sotto la massima
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  } 
  else {
    // VERDE: Al di sotto di entrambe le soglie
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }

  delay(150); // Mantiene il sistema reattivo senza intasare il monitor seriale
}