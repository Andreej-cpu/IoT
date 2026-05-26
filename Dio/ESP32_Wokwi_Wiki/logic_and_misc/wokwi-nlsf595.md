* Diagram Reference
* wokwi-nlsf595

On this page

# wokwi-nlsf595 Reference

Serial (SPI) Tri-Color LED Driver

![NLSF595](data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTkuODEybW0iIGhlaWdodD0iOC4zNW1tIiB2aWV3Qm94PSIwIDAgMTkuODEyIDguMzUiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+CiAgPGRlZnM+CiAgICA8cGF0dGVybiBpZD0icGlucyIgd2lkdGg9IjIuNTQiIGhlaWdodD0iOC40IiBwYXR0ZXJuVW5pdHM9InVzZXJTcGFjZU9uVXNlIj4KICAgICAgPHJlY3QgeD0iLjUiIHdpZHRoPSIxLjIiIGhlaWdodD0iMSIgZmlsbD0iI2NjYyIgcng9Ii4xIi8+CiAgICAgIDxyZWN0IHg9Ii41IiB5PSI3LjM1IiB3aWR0aD0iMS4yIiBoZWlnaHQ9IjEiIGZpbGw9IiNjY2MiIHJ4PSIuMSIvPgogICAgPC9wYXR0ZXJuPgogIDwvZGVmcz4KICA8cGF0aCBmaWxsPSIjMjIyIiBkPSJNMCAxaDE5LjgxMnY2LjM1SDB6Ii8+CiAgPHBhdGggZmlsbD0idXJsKCNwaW5zKSIgZD0iTTAgMGgxOS44MTJ2OC41SDB6Ii8+CiAgPGNpcmNsZSBjeD0iMTcuNTI2IiBjeT0iNC4xNzUiIHI9IjEuMjUiLz4KICA8Y2lyY2xlIGN5PSI0LjE3NSIgcj0iMSIvPgogIDxjaXJjbGUgY3g9IjEuMjUiIGN5PSI2LjE1IiBmaWxsPSIjNDQ0IiByPSIuNSIvPgogIDx0ZXh0IGZpbGw9Im9saXZlIiBmb250LWZhbWlseT0ic2Fucy1zZXJpZiIgZm9udC13ZWlnaHQ9ImJvbGQiIGZvbnQtc2l6ZT0iMiIgdGV4dC1hbmNob3I9Im1pZGRsZSI+CiAgICA8dHNwYW4geD0iOS45IiB5PSIzLjc1Ij5OTFNGPC90c3Bhbj48dHNwYW4geD0iOS45IiB5PSI2LjI1Ij41OTU8L3RzcGFuPgogIDwvdGV4dD4KPC9zdmc+Cg==)

Use the NLSF595 shift register to connect power-hungry RGB LEDs to your microcontroller. A single unit can control two RGB LEDs, and a chain of two units can control up to five RGB LEDs.

## Pin names

| Pin | Description |
| --- | --- |
| SI | Serial input |
| SCK | Serial clock |
| RCK | Storage (latch) pin |
| OE | Output enable, active low. Connect to GND if not used. |
| QA…QH | Parallel output |
| SQH | Serial output* |
| SCLR | Reset (clear), active low. Connect to VCC if not used |
| GND | Ground |
| VCC | Supply voltage |

* Use the Q7S to chain multiple NLSF595 units together. Connect SQH to the SI pin of the next NLSF595 chip in chain.

## Using the NLSF595

You will need to connect at least 3 pins to your microcontroller: SI, SCK, and RCK.

The OE pin can be used to disable the output of the shift register. If you need that functionality,
connect it to your microcontroller. Otherwise, connect it to the ground to permanently enable the output.

The output pins of the shift register, QA through QH, are usually connected to the input pins of common-anode [RGB LEDs](wokwi-rgb-led.html "wokwi-rgb-led.md").