* Diagram Reference
* wokwi-neopixel

On this page

# wokwi-neopixel Reference

WS2812 NeoPixel Compatible Addressable LED.

## Pin names

| Name | Description |
| --- | --- |
| VDD | Positive voltage supply |
| DOUT | Data output |
| VSS | Ground |
| DIN | Data input signal |

### Chaining

You can chain multiple NeoPixels by connecting the DOUT pin of one to the DIN pin of the next. All LEDs share the same data line and are addressed sequentially.

For larger numbers of LEDs, consider using the [LED Strip](wokwi-led-strip.html "wokwi-led-strip.md"), [LED Ring](wokwi-led-ring.html "wokwi-led-ring.md"), or [LED Matrix](wokwi-led-matrix.html "wokwi-led-matrix.md") parts instead.

## Arduino code example

```cpp
#include <Adafruit_NeoPixel.h>  
  
#define LED_PIN 6  
  
Adafruit_NeoPixel pixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);  
  
void setup() {  
  pixel.begin();  
  pixel.setPixelColor(0, pixel.Color(150, 0, 0)); // Red  
  pixel.show();  
}  
  
void loop() {  
  delay(100);  
}
```