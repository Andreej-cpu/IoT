# Missione 09: UltraSonic Yo

## Dettagli e Requisiti


### Requisiti
Mantenere il circuito precedente (PIR + LED giallo). Procurarsi un sensore di distanza ultrasonico e un LED rosso.

### Obiettivo
Visualizzare la distanza misurata dal sensore ultrasonico sulla seriale.
Modificare il codice in modo da accendere il LED rosso per segnalare un "evento critico" solo quando si verificano ENTRAMBE le seguenti condizioni:
1. Il sensore PIR sta rilevando un movimento (ovvero il LED giallo è acceso).
2. La distanza misurata dal sensore ultrasonico è inferiore ad una certa soglia stabilita.