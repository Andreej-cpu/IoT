# Missione 19: Distance Oddity

## Dettagli e Requisiti


### Requisiti
Mantenere il circuito precedente. Procurarsi un sensore di distanza ultrasonico.

### Obiettivo
Visualizzare la distanza misurata sulla seriale. Modificare il codice precedente in modo da gestire un ulteriore LED rosso che rappresenta un "evento critico", ossia quando si verificano ENTRAMBE le due seguenti condizioni:
- il sensore PIR sta rilevando un movimento (LED giallo è acceso)
- la distanza misurata è inferiore ad una certa soglia
