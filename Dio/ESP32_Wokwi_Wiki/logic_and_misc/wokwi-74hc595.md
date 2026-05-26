* Diagram Reference
* wokwi-74hc595

On this page

# wokwi-74hc595 Reference

8-bit Serial-In Parallel-Out (SIPO) Shift Register

![74HC595](data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTkuODEybW0iIGhlaWdodD0iOC4zNW1tIiB2aWV3Qm94PSIwIDAgMTkuODEyIDguMzUiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+CiAgPGRlZnM+CiAgICA8cGF0dGVybiBpZD0icGlucyIgd2lkdGg9IjIuNTQiIGhlaWdodD0iOC40IiBwYXR0ZXJuVW5pdHM9InVzZXJTcGFjZU9uVXNlIj4KICAgICAgPHJlY3QgeD0iLjUiIHdpZHRoPSIxLjIiIGhlaWdodD0iMSIgZmlsbD0iI2NjYyIgcng9Ii4xIi8+CiAgICAgIDxyZWN0IHg9Ii41IiB5PSI3LjM1IiB3aWR0aD0iMS4yIiBoZWlnaHQ9IjEiIGZpbGw9IiNjY2MiIHJ4PSIuMSIvPgogICAgPC9wYXR0ZXJuPgogIDwvZGVmcz4KICA8cGF0aCBmaWxsPSIjMjIyIiBkPSJNMCAxaDE5LjgxMnY2LjM1SDB6Ii8+CiAgPHBhdGggZmlsbD0idXJsKCNwaW5zKSIgZD0iTTAgMGgxOS44MTJ2OC41SDB6Ii8+CiAgPGNpcmNsZSBjeD0iMTcuNTI2IiBjeT0iNC4xNzUiIHI9IjEuMjUiLz4KICA8Y2lyY2xlIGN5PSI0LjE3NSIgcj0iMSIvPgogIDxjaXJjbGUgY3g9IjEuMjUiIGN5PSI2LjE1IiBmaWxsPSIjNDQ0IiByPSIuNSIvPgogIDx0ZXh0IGZpbGw9Im9saXZlIiBmb250LWZhbWlseT0ic2Fucy1zZXJpZiIgZm9udC13ZWlnaHQ9ImJvbGQiIGZvbnQtc2l6ZT0iMiIgdGV4dC1hbmNob3I9Im1pZGRsZSI+CiAgICA8dHNwYW4geD0iOS45IiB5PSIzLjc1Ij43NEhDPC90c3Bhbj48dHNwYW4geD0iOS45IiB5PSI2LjI1Ij41OTU8L3RzcGFuPgogIDwvdGV4dD4KPC9zdmc+Cg==)

Use the 74HC595 shift register to expand the number of *output* pins on your microcontroller. For input shift register (e.g. reading multiple buttons with a single input pin), please see the [wokwi-74hc165](wokwi-74hc165.html "wokwi-74hc165.md").

## Pin names

| Pin | Description |
| --- | --- |
| DS | Serial input |
| SHCP | Serial clock |
| STCP | Storage (latch) pin |
| OE | Output enable, active low. Connect to GND if not used. |
| Q0…Q7 | Parallel output |
| Q7S | Serial output* |
| MR | Reset (clear), active low. Connect to VCC if not used |
| GND | Ground |
| VCC | Supply voltage |

* Use the Q7S to chain multiple 74HC595 units together. Connect Q7S to the DS pin of the next 74HC595 chip in chain.

## Connecting to Arduino

You will need to connect at least 3 pins to your microcontroller: DS, SHCP, and STCP.

The OE pin can be used to disable the output of the shift register. If you need that functionality,
connect it to your microcontroller. Otherwise, connect it to the ground to permanently enable the output.

The output pins of the shift register, Q0 through Q7, are usually connected to [LEDs](wokwi-led.html "wokwi-led.md") or a 7-segment display.

The following code example assumes that you connected DS to Arduino pin 2, SHCP to Arduino pin 3, and
STCP to Arduino pin 4. It outputs an 8-bit pattern that inverts two times a second:

```cpp
const int dataPin = 2;   /* DS */  
const int clockPin = 3;  /* SHCP */  
const int latchPin = 4;  /* STCP */  
  
void setup() {  
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);  
  pinMode(latchPin, OUTPUT);  
}  
  
int pattern = 0b10101010;  
void loop() {  
  digitalWrite(latchPin, LOW);  
  shiftOut(dataPin, clockPin, LSBFIRST, pattern);  
  digitalWrite(latchPin, HIGH);  
  delay(500);  
  pattern = ~pattern; // Invert the pattern  
}
```

You can also [run this example on Wokwi](https://wokwi.com/projects/301192672203244042 "https://wokwi.com/projects/301192672203244042").