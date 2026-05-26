# Missione 13: Just Light Heaven

## Dettagli e Requisiti


### Requisiti
Aggiungere un fotoresistore, mantenere i LED.

### Obiettivo
Implementare una fase di calibrazione della durata di 5 secondi, in modo da individuare i valori che corrispondono alle condizioni di buio e luce.
- Durante i 5 secondi di calibrazione deve essere mostrato un messaggio fisso: "Calibrazione in corso...".
- Aggiungere codice in modo che tutti i 3 LED si accendano ad una luminosità che dipende dal livello di luce misurata.
- Meno luce ambiente più luce LED. Esempio: 90% luce ambiente -> 10% luce LED; 20% luce ambiente -> 80% luce LED.
