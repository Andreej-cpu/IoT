# Schema Pinout ESP32 (Formato per Agente AI)

## 1. Classificazione Generale dei Pin (Legenda)
I pin sono classificati in 4 categorie principali in base alla loro usabilità:
- **[USABLE]**: Pin I/O utilizzabili senza restrizioni particolari.
- **[INPUT_ONLY]**: Pin che possono solo leggere segnali, non possono emetterli.
- **[NOT_RECOMMENDED]**: Pin il cui utilizzo è sconsigliato o altamente condizionato a causa di conflitti di sistema (Boot, SPI Flash, Serial).
- **[NON_GPIO]**: Pin di alimentazione o controllo hardware (GND, 3V3, 5V, EN).

---

## 2. Regole e Restrizioni Critiche (Regole di Inferenza per l'AI)
Prima di assegnare un pin a un compito, l'agente AI DEVE valutare queste regole:

1. **CRITICAL_SPI_FLASH (Pin 6, 7, 8, 9, 10, 11)**: 
   - *Regola*: **NON USARE MAI**. Sono connessi alla memoria SPI flash integrata. L'utilizzo causerà il crash istantaneo della scheda.
2. **STRAPPING_PINS (Pin 0, 2, 5, 12, 15)**: 
   - *Regola*: Il loro stato di tensione al momento dell'accensione determina la modalità di avvio (boot) del chip. Se un sensore forza uno di questi pin in stato HIGH o LOW durante l'avvio, l'ESP32 potrebbe rifiutarsi di avviarsi o fallire l'ingresso in modalità flash. Da usare con estrema cautela e solo conoscendone il comportamento al boot.
3. **ADC_WIFI_CONFLICT (Pin da 4 a 13)**: 
   - *Regola*: Possono essere usati per la lettura analogica (ADC) **SOLO SE** il modulo Wi-Fi non è in uso.
4. **INPUT_ONLY_ADC (Pin 34, 35, 36, 39)**:
   - *Regola*: Possono essere usati esclusivamente come Input. Non hanno resistenze interne di pull-up o pull-down. Sono dedicati primariamente alla lettura analogica (ADC).

---

## 3. Mappatura Completa dei Pin

| Pin Hardware | Categoria AI | Funzione / Restrizione Specifica |
| :--- | :--- | :--- |
| **3V3** | `[NON_GPIO]` | Alimentazione 3.3V |
| **EN** | `[NON_GPIO]` | Enable / Reset (Tirare LOW per resettare) |
| **36** | `[INPUT_ONLY]` | Dedicato Input ADC. Nessun pull-up/pull-down interno. |
| **39** | `[INPUT_ONLY]` | Dedicato Input ADC. Nessun pull-up/pull-down interno. |
| **34** | `[INPUT_ONLY]` | Dedicato Input ADC. Nessun pull-up/pull-down interno. |
| **35** | `[INPUT_ONLY]` | Dedicato Input ADC. Nessun pull-up/pull-down interno. |
| **32** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **33** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **25** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **26** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **27** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **14** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **12** | `[NOT_RECOMMENDED]`| **[STRAPPING_PIN]** Influisce sul boot. **[ADC_WIFI_CONFLICT]** |
| **GND** | `[NON_GPIO]` | Ground / Massa. |
| **13** | `[NOT_RECOMMENDED]`| **[ADC_WIFI_CONFLICT]** Lettura analogica solo senza Wi-Fi. |
| **9** | `[NOT_RECOMMENDED]`| **[CRITICAL_SPI_FLASH]** Crash istantaneo se usato. |
| **10** | `[NOT_RECOMMENDED]`| **[CRITICAL_SPI_FLASH]** Crash istantaneo se usato. |
| **11** | `[NOT_RECOMMENDED]`| **[CRITICAL_SPI_FLASH]** Crash istantaneo se usato. |
| **5V** | `[NON_GPIO]` | Alimentazione 5V (da USB). |
| **23** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **22** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **1** | `[NOT_RECOMMENDED]`| Pin TX0. Usato per la comunicazione Seriale/Flashing. |
| **3** | `[NOT_RECOMMENDED]`| Pin RX0. Usato per la comunicazione Seriale/Flashing. |
| **21** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **19** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **18** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **5** | `[NOT_RECOMMENDED]`| **[STRAPPING_PIN]** Influisce sul boot. |
| **17** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **16** | `[USABLE]` | I/O generico. Utilizzabile liberamente. |
| **4** | `[USABLE]` | I/O generico. **[ADC_WIFI_CONFLICT]** Lettura analogica solo senza Wi-Fi. |
| **0** | `[NOT_RECOMMENDED]`| **[STRAPPING_PIN]** Influisce sul boot. |
| **2** | `[NOT_RECOMMENDED]`| **[STRAPPING_PIN]** Influisce sul boot. |
| **15** | `[NOT_RECOMMENDED]`| **[STRAPPING_PIN]** Influisce sul boot. |
| **8** | `[NOT_RECOMMENDED]`| **[CRITICAL_SPI_FLASH]** Crash istantaneo se usato. |
| **7** | `[NOT_RECOMMENDED]`| **[CRITICAL_SPI_FLASH]** Crash istantaneo se usato. |
| **6** | `[NOT_RECOMMENDED]`| **[CRITICAL_SPI_FLASH]** Crash istantaneo se usato. |

---

## 4. Linee Guida per l'Allocazione (Workflow per Agente AI)
Quando ti viene richiesto di allocare dei pin per un circuito, segui questa logica:

1. **Cerchi un pin per un sensore analogico (es. fotoresistenza)?** - Usa per primi i pin `36, 39, 34, 35`.
2. **Cerchi un pin per un LED o un sensore digitale?** - Usa i pin verdi `[USABLE]` (es. `32, 33, 25, 26, 27, 14, 23, 22, 21, 19, 18, 17, 16, 4`).
3. **Usi il Wi-Fi e ti serve un pin analogico?**
   - **EVITA ASSOLUTAMENTE** i pin tra `4` e `13`.
4. **Ti servono altri pin ma gli USABLE sono finiti?**
   - Usa i pin Strapping (`0, 2, 5, 12, 15`) **solo come OUTPUT** per componenti (come i LED) che non alterano lo stato del pin al momento dell'accensione della scheda.