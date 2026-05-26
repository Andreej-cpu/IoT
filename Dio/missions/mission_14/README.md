# Missione 14: Yellow

## Dettagli e Requisiti


### Requisiti
Mantenere il circuito precedente.

### Obiettivo
Scegliere dei valori di soglia (media, max) per la luce (facili da testare andando sopra o sotto di essi). Accendere uno dei LED a seconda del livello di alert:
- Verde: sensore sotto i due livelli di soglia
- Giallo: superata la soglia media
- Rosso: superata anche la soglia max

TIP: Ogni volta che si riavvia il circuito, la calibrazione reimposta il range per il sensore di luce. Per evitare di perdere tempo ad ogni prova, si potrebbe fare la calibrazione bene una volta sola e poi impostare i valori trovati nel codice.

Suggerimento: per evitare problemi di sincronizzazione e performance aggiungere il modificatore IRAM_ATTR alla dichiarazione della funzione chiamata dall'interrupt. Serve a spostare la funzione nella RAM, invece che tenerla nella Flash... E ricordarsi di "volatile".... Esempio: void IRAM_ATTR nome_funzione() { ....
