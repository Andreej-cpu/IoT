# Missione 06: Click ammazza -

## Dettagli e Requisiti


### Requisiti
Disconnettere il circuito precedente. Connettere un tasto (pulsante) e un LED.

### Obiettivo
All'inizio il LED lampeggia lentamente (On 4 sec, off 4 sec). Ad ogni click del tasto, il LED dimezza il tempo di lampeggiamento (4, 2, 1, 0.5, 0.25, 0.125).
Arrivati a 0.125, alla successiva pressione il ciclo ricomincia con 4 secondi.
Requisito Tecnico Fondamentale: Gestire il bouncing del pulsante. Usare gli Interrupt, la funzione millis() per evitare blocchi temporali e variabili con modificatore volatile. Non usare delay().