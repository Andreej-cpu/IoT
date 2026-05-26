* Diagram Reference
* board-ssd1306

On this page

# board-ssd1306 Reference

Monochrome 128x64 OLED display with I2C interface

![SSD1306](https://raw.githubusercontent.com/wokwi/wokwi-boards/main/boards/ssd1306/board.svg)

The default I2C address of the SSD1306 module is 0x3c (60). Some modules have a different address (0x3d), you can change the address by editing diagram.json and setting the `i2cAddress` attribute to "0x3d".

## Pin names

| Name | Description | Arduino Uno pin |
| --- | --- | --- |
| GND | Ground | GND |
| VCC | Supply voltage | 5V |
| SCL | I2C clock line | A5 |
| SDA | I2C data line | A4 |

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| i2cAddress | I2C address of the display | "0x3c" |

## Using in Arduino

You can choose between several SSD1306 Arduino libraries:

* [Adafruit SSD1306](https://wokwi.com/projects/344892392214626898 "https://wokwi.com/projects/344892392214626898")
* [ssd1306](https://wokwi.com/projects/344894074741850707 "https://wokwi.com/projects/344894074741850707")
* [lcdgfx](https://github.com/lexus2k/lcdgfx "https://github.com/lexus2k/lcdgfx")
* [U8glib](https://github.com/olikraus/u8glib "https://github.com/olikraus/u8glib")
* [U8g2](https://github.com/olikraus/u8g2 "https://github.com/olikraus/u8g2") (also U8x8)
* [SSD1306Ascii](https://github.com/greiman/SSD1306Ascii "https://github.com/greiman/SSD1306Ascii")
* [Tiny4kOLED](https://www.arduino.cc/reference/en/libraries/tiny4koled/ "https://www.arduino.cc/reference/en/libraries/tiny4koled/") - for ATtiny85 users

All the above libraries are available on Wokwi.