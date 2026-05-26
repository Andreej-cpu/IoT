* Diagram Reference
* wokwi-dht22

On this page

# wokwi-dht22 Reference

Digital Humidity and Temperature sensor.

## Pin names

| Name | Description |
| --- | --- |
| VCC | Positive voltage |
| SDA | Digital data pin (input/output) |
| NC | Not connected |
| GND | Ground |

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| temperature | Initial temperature value (celsius) | "24" |
| humidity | Initial relative humidity value (percentage) | "40" |

## Controlling the temperature

You can change the temperature and humidity values while the simulation is running.
Click on the DHT22 sensor and a small popup window will open. Use the temperature and
humidity sliders to change the values. Click "Hide" to close the popup window.

warning

If you are trying to read this sensor from the ESP32, use the "DHT sensor library for ESPx" library. Other DHT22 libraries may not work reliably on the ESP32. You can use this [example project](https://wokwi.com/projects/322410731508073042 "https://wokwi.com/projects/322410731508073042") as a starting point.