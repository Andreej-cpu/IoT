* Diagram Reference
* wokwi-wifi-ap

On this page

# wokwi-wifi-ap Reference

Simulated WiFi access point. Add one or more to your diagram to create custom WiFi networks for ESP32 projects.

![wokwi-wifi-ap](data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSI4MCIgaGVpZ2h0PSI2MCIgdmlld0JveD0iMCAwIDgwIDYwIj48cmVjdCB4PSIxIiB5PSIxIiB3aWR0aD0iNzgiIGhlaWdodD0iNTgiIHJ4PSI2IiByeT0iNiIgZmlsbD0iIzJjM2U1MCIgc3Ryb2tlPSIjMzQ0OTVlIiBzdHJva2Utd2lkdGg9IjEuNSI+PC9yZWN0PjxnIHRyYW5zZm9ybT0idHJhbnNsYXRlKDQwLCAyOCkiIGZpbGw9Im5vbmUiIHN0cm9rZT0iIzM0OThkYiIgc3Ryb2tlLXdpZHRoPSIyIiBzdHJva2UtbGluZWNhcD0icm91bmQiPjxjaXJjbGUgY3g9IjAiIGN5PSIwIiByPSIyLjUiIGZpbGw9IiMzNDk4ZGIiIHN0cm9rZT0ibm9uZSI+PC9jaXJjbGU+PHBhdGggZD0iTS02LC01IEE4LDggMCAwLDEgNiwtNSI+PC9wYXRoPjxwYXRoIGQ9Ik0tMTEsLTkgQTE0LDE0IDAgMCwxIDExLC05Ij48L3BhdGg+PHBhdGggZD0iTS0xNiwtMTMgQTIxLDIxIDAgMCwxIDE2LC0xMyI+PC9wYXRoPjwvZz48ZyB0cmFuc2Zvcm09InRyYW5zbGF0ZSg2NCwgOCkiIGZpbGw9IiNlNjdlMjIiPjxyZWN0IHg9IjEiIHk9IjQiIHdpZHRoPSI4IiBoZWlnaHQ9IjYiIHJ4PSIxIj48L3JlY3Q+PHBhdGggZD0iTTIuNSw0IFYyLjUgQTIuNSwyLjUgMCAwLDEgNy41LDIuNSBWNCIgZmlsbD0ibm9uZSIgc3Ryb2tlPSIjZTY3ZTIyIiBzdHJva2Utd2lkdGg9IjEuMiI+PC9wYXRoPjwvZz48ZyB0cmFuc2Zvcm09InRyYW5zbGF0ZSg2LCA4KSIgZmlsbD0ibm9uZSIgc3Ryb2tlPSIjMmVjYzcxIiBzdHJva2Utd2lkdGg9IjEuMiI+PGNpcmNsZSBjeD0iNSIgY3k9IjUiIHI9IjQuNSI+PC9jaXJjbGU+PGVsbGlwc2UgY3g9IjUiIGN5PSI1IiByeD0iMiIgcnk9IjQuNSI+PC9lbGxpcHNlPjxsaW5lIHgxPSIwLjUiIHkxPSI1IiB4Mj0iOS41IiB5Mj0iNSI+PC9saW5lPjwvZz48dGV4dCB4PSI0MCIgeT0iNDgiIHRleHQtYW5jaG9yPSJtaWRkbGUiIGZpbGw9IndoaXRlIiBmb250LXNpemU9IjEwIiBmb250LWZhbWlseT0ic2Fucy1zZXJpZiI+V29rd2ktV2lGaTwvdGV4dD48L3N2Zz4=)

Paid Feature

Custom WiFi Access Points require a [Wokwi Hobby+ or Pro plan](https://wokwi.com/pricing?ref=docs_wifiap "https://wokwi.com/pricing?ref=docs_wifiap").
Free users can connect to the default **Wokwi-GUEST** open network.

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| ssid | Network name (SSID) | "MyNetwork" |
| password | WPA2-PSK password (empty = open network) | "" |
| channel | WiFi channel (1-13) | "6" |
| internet | Internet access ("0" = disabled) | "" (enabled) |
| bssid | MAC address (auto-generated if omitted) | "" |

## Multiple access points

Add several `wokwi-wifi-ap` parts to simulate environments with multiple networks. This is useful for testing WiFi scanning and network selection UIs.

When the diagram contains custom WiFi access point parts, the default **Wokwi-GUEST** network is not created.

## Internet access

All access points provide internet access by default via the [Wokwi IoT Gateway](guides/esp32-wifi.md#the-private-gateway "../guides/esp32-wifi.md#the-private-gateway"). To create a local-only access point without internet routing, set the `internet` attribute to `"0"`.

## Connecting from Arduino

```cpp
#include <WiFi.h>  
  
void setup() {  
  Serial.begin(115200);  
  WiFi.begin("HomeWiFi", "mypassword");  
  while (WiFi.status() != WL_CONNECTED) {  
    delay(100);  
    Serial.print(".");  
  }  
  Serial.println("Connected!");  
}
```

## Connecting from MicroPython

```text
import network  
import time  
  
sta_if = network.WLAN(network.STA_IF)  
sta_if.active(True)  
sta_if.connect('HomeWiFi', 'mypassword')  
while not sta_if.isconnected():  
    time.sleep(0.1)  
print('Connected!')
```