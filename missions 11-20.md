Missione 11: Blink 
- Implementare un led lampeggiante.
- Tempi: 182 millisecondi ON poi 182 ms OFF.
- Interrompere il lampeggiamento e spegnere dopo 20 ripetizioni di ON OFF.
- NB: dato che ogni lampeggiamento dura nel complesso 182+182 ms, si dovrebbe osservare uno spegnimento dopo circa 7 secondi (364ms x 20).


Missione 12: Don't LED Me Down 
- Aggiungere altri due LED in modo da avere 3 LED, rosso, giallo, verde.
- Obiettivo: devono essere lampeggianti, ma ognuno con velocità diverse: 
  - LED VERDE: 2 sec ON, 2 sec OFF 
  - LED GIALLO: 1 sec ON, 1 sec OFF 
  - LED ROSSO: 500ms ON, 500ms OFF 



  Missione 13: Just Light Heaven 
- Aggiungere un fotoresistore, mantenere LED.
- Implementare una fase di calibrazione della durata di 5 secondi, in modo da individuare i valori che corrispondono alle condizioni di buio e luce.
- Durante i 5 secondi di calibrazione deve essere mostrato un messaggio fisso: "Calibrazione in corso...".
- Aggiungere codice in modo che tutti i 3 LED si accendano ad una luminosità che dipende dal livello di luce misurata.
- Meno luce ambiente più luce LED. Esempio: 90% luce ambiente -> 10% luce LED; 20% luce ambiente -> 80% luce LED.


Missione 14: Yellow 
- Mantenere il circuito precedente.
- Scegliere dei valori di soglia (media, max) per la luce.
- NB: scegliere valori che siano facili da testare andando sopra o sotto di essi.
- Accendere uno dei LED a seconda del livello di alert: 
  - Verde: sensore sotto i due livelli di soglia 
  - Giallo: superata la soglia media 
  - Rosso: superata anche la soglia max 
- TIP: Ogni volta che si riavvia il circuito, la calibrazione reimposta il range per il sensore di luce. Per evitare di perdere tempo ad ogni prova, si potrebbe fare la calibrazione bene una volta sola e poi impostare i valori trovati nel codice.
- Suggerimento: per evitare problemi di sincronizzazione e performance aggiungere il modificatore IRAM_ATTR alla dichiarazione della funzione chiamata dall'interrupt. Serve a spostare la funzione nella RAM, invece che tenerla nella Flash... E ricordarsi di "volatile"....  Esempio: void IRAM_ATTR nome_funzione() { .... 


Missione 15: Cliccando contro il tempo 
- Disconnettere circuito precedente.
- Connettere un tasto. Connettere un LED.
- All'inizio il LED lampeggia lentamente (On 4 sec, off 4 sec).
- Ad ogni click del tasto, il LED dimezza il tempo di lampeggiamento (4, 2, 1, 0.5, 0.25, 0.125).
- Arrivati a 0.125, alla successiva pressione ricomincia con 4 secondi.
- Gestire il bouncing del pulsante.

Missione 16: Another one Clicks the Tast 
- Mantenere il circuito precedente col tasto.
- Aggiungere un secondo tasto (pulsante B).
- Chiameremo "pulsante A" quello della missione precedente.
- Si parte col funzionamento normale della missione 5.
- Quando si clicca B: il lampeggiamento si interrompe  e l'altro tasto (A) non ha più effetto, ossia non modifica gli intervalli.
- Poi cliccando di nuovo il sistema riparte, usando l'intervallo iniziale di 4 secondi per il lampeggiamento , come previsto dalla missione precedente.
- In pratica il pulsante B fa accendi e spegni della Missione 5.


Missione 17: Under Pressure 
- Tutto come la missione precedente.
- Tranne che... l'effetto "disattivante" del secondo tasto (pulsante B) non avviene semplicemente cliccando, ma solo se si tiene premuto il tasto per più di 3 secondi.


Missione 18: Dancing PIR 
- Eliminare il circuito precedente. Procurarsi un sensore di movimento PIR.
- Un LED giallo si accende ogni qual volta il sensore rileva un movimento e si spegne quando il sensore non indica più movimento.
- TIP: controllare la logica del pin di uscita del sensore, come si comporta? 


Missione 19: Distance Oddity 
- Mantenere il circuito precedente.
- Procurarsi un sensore di distanza ultrasonico.
- Visualizzare la distanza misurata sulla seriale.
- Modificare il codice precedente in modo da gestire un ulteriore LED rosso che rappresenta un "evento critico", ossia quando si verificano ENTRAMBE le due seguenti condizioni: 
  - il sensore PIR sta rilevando un movimento (LED giallo è acceso) 
  - la distanza misurata è inferiore ad una certa soglia 


Missione 20:
- Mantenere il circuito precedente con i LED e il sensore PIR e sensore ultrasonico.
- Utilizzare la piattaforma blynk io per creare una dashboard Web per interagire a distanza col sistema di allarme.
- In particolare, l'interfaccia avrà: 
  - Uno switch per abilitare/disabilitare gli allarmi LED generati dei sensori.
  - Un elemento che visualizzi l'attuale stato del LED rosso.
  - Un elemento che visualizza il numero di volte che si sono verificati eventi critici.