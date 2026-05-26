* Diagram Reference
* wokwi-ky-040

On this page

# wokwi-ky-040 Rotary Encoder Reference

KY-040 Rotary Encoder module with 20 steps per revolution.

## Pin names

| Name | Description |
| --- | --- |
| CLK | Rotary encoder pin A |
| DT | Rotary encoder pin B |
| SW | Push button pin. Normally open, shorted to GND on press |
| VCC | Voltage supply |
| GND | Ground |

## Operation

The rotary encoder offers two ways of interaction:

* **Rotation** - You can rotate the knob by clicking on the arrows.
  The upper arrow rotates it one step clockwise, and the lower
  arrow rotates it one step counterclockwise. Rotating the knob
  will produce digital signals on the DT and CLK pins, as
  explained below.
* **Button** - Click on the knob to press the button.
  While pressed, the button connects the SW pin with the GND pin.

Every time the user rotates the knob, it produces a LOW signal
on the DT and CLK pins:

* Rotating clockwise causes the CLK pin to go low first, and then the DT pin
  goes low too.
* Rotating counterclockwise causes the DT pin to go low first, and then the
  CLK pin go low.

Both pins will go back high within a few milliseconds. The following
diagram illustrates this:

![KY-040 Logic Analyzer capture](../assets/images/wokwi-ky-040-timing-cd6fe446378352c1416ef8817f1e5abf.png)

You can experiment with the DT/CLK pin timings by connecting them to the
[Wokwi Logic Analyzer](wokwi-logic-analyzer.html "wokwi-logic-analyzer.md"). Check out the [Logic Analyzer Guide](guides/logic-analyzer.md "../guides/logic-analyzer.md")
to learn how to use the logic analyzer.

### Schematics

The KY-040 module includes two internal pull-up resistors that
pull-up pins CLK and DT to VCC. The simulation always pulls these
pins up, even if you left the VCC pin floating.

![KY-040 Module Schematics](data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iODguMm1tIiBoZWlnaHQ9IjU0bW0iIHZpZXdCb3g9IjAgMCAzMzQgMjA0IiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciPgogIDxwYXRoIGZpbGw9IiNmZmZmYzIiIGZpbGwtb3BhY2l0eT0iLjYiIGQ9Ik0xNjEgODYuNWg4Ny41VjE3NEgxNjF6Ii8+CiAgPGcgc3Ryb2tlPSIjODQwMDAwIiBzdHJva2UtbGluZWNhcD0icm91bmQiIHN0cm9rZS1saW5lam9pbj0icm91bmQiIHN0cm9rZS13aWR0aD0iMi4xOSIgZmlsbD0ibm9uZSI+CiAgICA8cGF0aCBkPSJNMTYxIDg2LjVoODcuNVYxNzRIMTYxek0yMDIgMTU0YTIzLjYgMjMuNiAwIDAwMC00Ny4yIi8+CiAgICA8Y2lyY2xlIGN4PSIxNzIiIGN5PSIxMzAiIHI9IjIuMTkiIGZpbGw9IiM4NDAwMDAiIHN0cm9rZS13aWR0aD0iMS4zMSIvPgogICAgPGNpcmNsZSBjeD0iMjAyIiBjeT0iMTMwIiByPSIxNi40Ii8+CiAgICA8Y2lyY2xlIGN4PSIyNDIiIGN5PSIxMzkiIHI9IjEuMDkiLz4KICAgIDxjaXJjbGUgY3g9IjI0MiIgY3k9IjEyMiIgcj0iMS4wOSIvPgogICAgPHBhdGggZD0iTTE2MSA4Ni41aDg3LjVWMTc0SDE2MXoiLz4KICA8L2c+CiAgPGcgZmlsbD0ibm9uZSIgc3Ryb2tlPSIjODQwMDAwIiBzdHJva2UtbGluZWNhcD0icm91bmQiIHN0cm9rZS1saW5lam9pbj0icm91bmQiPgogICAgPHBhdGggZD0iTTIwMCAxNDZ2LTMwLjZtMiAzMC42di0zMC42bTItLjR2MzAuNm0zNC0xNS42aC0zLjI4bTMuMjgtOHYxNy41IiBzdHJva2Utd2lkdGg9IjIuMTkiLz4KICAgIDxwYXRoIGQ9Ik0xNjEgMTUyaDEwLjl2LTQuMzdNMTYxIDEwOGgxMC45djQuMzciIHN0cm9rZS13aWR0aD0iMS4zMSIvPgogICAgPHBhdGggZD0iTTIwNyAxNTdsLTYuNTYtMi4xOSA1LjQ3LTMuMjhNMjA3IDEwNWwtNi41NiAyLjE5IDUuNDcgMy4yOE0yNDkgMTUyaC02LjU2di0xMy4xTTI0OSAxMDhoLTYuNTZ2MTMuMSIgc3Ryb2tlLXdpZHRoPSIyLjE5Ii8+CiAgICA8cGF0aCBkPSJNMTYxIDEzMGgxMC45djguNzVsNC4zNyA4Ljc1TTE2OCAxMzBoNC4zN3YtOC43NWw0LjM3LTguNzUiIHN0cm9rZS13aWR0aD0iMS4zMSIvPgogIDwvZz4KICA8ZyBzdHJva2UtbGluZWNhcD0icm91bmQiIHN0cm9rZS1saW5lam9pbj0icm91bmQiPgogICAgPHBhdGggZD0iTTE2MSAxMDhoLTIxLjkiIHN0cm9rZT0iIzg0MDAwMCIgc3Ryb2tlLXdpZHRoPSIxLjMxIiBmaWxsPSJub25lIi8+CiAgICA8dGV4dCBmaWxsPSIjODQwMDAwIiBmb250LXNpemU9IjE0LjQ1NCIgc3Ryb2tlLXdpZHRoPSIxLjMxNCIgdGV4dC1hbmNob3I9Im1pZGRsZSI+CiAgICAgIDx0c3BhbiB4PSIxNTEuNTUiIHk9IjEwNiI+QTwvdHNwYW4+CiAgICAgIDx0c3BhbiB4PSIxNTEuNTUiIHk9IjE1MCI+QjwvdHNwYW4+CiAgICAgIDx0c3BhbiB4PSIxNTEuNTUiIHk9IjEyOCI+QzwvdHNwYW4+CiAgICAgIDx0c3BhbiB4PSIyNjMuMDUiIHk9IjEwNiI+UzE8L3RzcGFuPgogICAgICA8dHNwYW4geD0iMjYzLjA1IiB5PSIxNDkiPlMyPC90c3Bhbj4KICAgIDwvdGV4dD4KICAgIDxwYXRoIGQ9Ik0xNjEgMTUyaC0yMS45TTE2MSAxMzBoLTIxLjlNMjQ5IDEwOGgyMS45TTI0OSAxNTJoMjEuOSIgc3Ryb2tlPSIjODQwMDAwIiBzdHJva2Utd2lkdGg9IjEuMzEiIGZpbGw9Im5vbmUiLz4KICA8L2c+CiAgPGcgZmlsbD0ibm9uZSIgc3Ryb2tlPSIjODQwMDAwIiBzdHJva2Utd2lkdGg9IjEuMzEiIHN0cm9rZS1saW5lY2FwPSJyb3VuZCIgc3Ryb2tlLWxpbmVqb2luPSJyb3VuZCI+CiAgICA8cGF0aCBkPSJNMTE3Ljk3NSA4NC4zNXYyLjE5bTAtNDEuNnYtMi4xOW0wIDI4LjVsOC43NiAzLjI4LTE3LjUgNi41NyA4Ljc2IDMuMjhtMC0yNi4zbDguNzYgMy4yOC0xNy41IDYuNTcgOC43NiAzLjI4Ii8+CiAgICA8cGF0aCBkPSJNMTE3Ljk3NSA0NC45NWw4Ljc2IDMuMjgtMTcuNSA2LjU3IDguNzYgMy4yOG0wLTE1LjN2LTExbTAgNTQuOHYxMU04NC43NzUgODQuNDV2Mi4xOW0wLTQxLjZ2LTIuMTltMCAyOC41bDguNzYgMy4yOC0xNy41IDYuNTcgOC43NiAzLjI4bTAtMjYuM2w4Ljc2IDMuMjgtMTcuNSA2LjU3IDguNzYgMy4yOCIvPgogICAgPHBhdGggZD0iTTg0Ljc3NSA0NS4wNWw4Ljc2IDMuMjgtMTcuNSA2LjU3IDguNzYgMy4yOG0wLTE1LjN2LTExbTAgNTQuOHYxMSIvPgogIDwvZz4KICA8cGF0aCBkPSJNMTE4IDk3LjV2MTAuOU04NC44IDIwLjloMzIuOG0tMzIuOCAxMVYyMW0zMy4yLS4xdjEwLjlNOC4yMiAyMC45aDc2LjVNODQuOCAxNTJIOC4zbTc2LjUtNTQuNXY1NC43bTU0LjItLjJIODQuM20zMy43LTQ0SDltMTMwIDBoLTIxLjltLTU0LjIgMjJIOC4ybTU0LjcgNjZ2LTY1LjZNMjcxIDE5Nkg2M20yMDgtNDR2NDMuN20wLTg3LjdoNTQuN00xMzkgMTMwSDYyLjUiIHN0cm9rZT0iIzAwODQwMCIgc3Ryb2tlLWxpbmVjYXA9InJvdW5kIiBzdHJva2UtbGluZWpvaW49InJvdW5kIiBzdHJva2Utd2lkdGg9IjEuMzEiIGZpbGw9Im5vbmUiLz4KICA8dGV4dCBmb250LXNpemU9IjE0LjQ1NCIgc3Ryb2tlPSIjZmZmIiBzdHJva2UtbGluZWNhcD0icm91bmQiIHN0cm9rZS1saW5lam9pbj0icm91bmQiIHBhaW50LW9yZGVyPSJzdHJva2UiPgogICAgPHRzcGFuIHg9IjkuMiIgeT0iMTA2Ij5DTEs8L3RzcGFuPgogICAgPHRzcGFuIHg9IjkuMiIgeT0iMTUwIj5EVDwvdHNwYW4+CiAgICA8dHNwYW4geD0iOS4yIiB5PSIxOSI+VkNDPC90c3Bhbj4KICAgIDx0c3BhbiB4PSIzMzAiIHk9IjEwNiIgdGV4dC1hbmNob3I9ImVuZCI+U1c8L3RzcGFuPgogICAgPHRzcGFuIHg9IjkuMiIgeT0iMTI4Ij5HTkQ8L3RzcGFuPgogIDwvdGV4dD4KICA8ZyBmaWxsPSIjMDA4NDAwIiBzdHJva2U9IiMwMDg0MDAiIHN0cm9rZS1saW5lY2FwPSJyb3VuZCIgc3Ryb2tlLWxpbmVqb2luPSJyb3VuZCIgc3Ryb2tlLXdpZHRoPSIyLjE5Ij4KICAgIDxjaXJjbGUgY3g9IjExOCIgY3k9IjEwOCIgcj0iNC4zNyIvPgogICAgPGNpcmNsZSBjeD0iNjIuOSIgY3k9IjEzMCIgcj0iNC4zNyIvPgogICAgPGNpcmNsZSBjeD0iODQuOCIgY3k9IjE1MiIgcj0iNC4zNyIvPgogICAgPGNpcmNsZSBjeD0iODQuOCIgY3k9IjIwLjkiIHI9IjQuMzciLz4KICA8L2c+Cjwvc3ZnPgo=)

## Using the Rotary Encoder in Arduino

### Reading the rotation

You can read the rotation by checking the status of the CLK pin. Whenever it goes LOW, read the
value of the DT pin to determine the direction: HIGH means clockwise rotation, LOW means
counterclockwise rotation. Code example:

```cpp
#define ENCODER_CLK 2  
#define ENCODER_DT  3  
  
void setup() {  
  Serial.begin(115200);  
  pinMode(ENCODER_CLK, INPUT);  
  pinMode(ENCODER_DT, INPUT);  
}  
  
int lastClk = HIGH;  
  
void loop() {  
  int newClk = digitalRead(ENCODER_CLK);  
  if (newClk != lastClk) {  
    // There was a change on the CLK pin  
    lastClk = newClk;  
    int dtValue = digitalRead(ENCODER_DT);  
    if (newClk == LOW && dtValue == HIGH) {  
      Serial.println("Rotated clockwise ⏩");  
    }  
    if (newClk == LOW && dtValue == LOW) {  
      Serial.println("Rotated counterclockwise ⏪");  
    }  
  }  
}
```

You can also [run this example on Wokwi](https://wokwi.com/projects/304184298969236032 "https://wokwi.com/projects/304184298969236032").

Note: your code will need to read the state of the pins frequently in order to detect the rotations
correctly.
If your `loop()` takes too long (e.g. you use `delay()` in your code), we recommend using [attachInterrupt()](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/ "https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/") to listen for changes in the CLK pin. Assuming CLK is connected to pin 2, and DT to pin 3 (as before):

```cpp
#define ENCODER_CLK 2  
#define ENCODER_DT  3  
  
void setup() {  
  pinMode(ENCODER_CLK, INPUT);  
  pinMode(ENCODER_DT, INPUT);  
  attachInterrupt(digitalPinToInterrupt(ENCODER_CLK), readEncoder, FALLING);  
}  
  
void readEncoder() {  
  int dtValue = digitalRead(ENCODER_DT);  
  if (dtValue == HIGH) {  
    Serial.println("Rotated clockwise ⏩");  
  }  
  if (dtValue == LOW) {  
    Serial.println("Rotated counterclockwise ⏪");  
  }  
}  
  
void loop() {  
  // Do whatever  
}
```

### Using the button

To read the state of the encoder's button, connect to to any Arduino IO pin and initialize this pin as `INPUT_PULLUP`. Then read the state of the button using `digitalRead()`.
It'll read LOW as long the the button is pressed.

The following code example will turn on Arduino's built-in LED (13) as long as the button is pressed.
It assumes you connected the SW to Arduino pin 4.
You also need to connect the GND pin to one of the Arduino's GND pins.

```cpp
#define ENCODER_BTN 4  
  
void setup() {  
  pinMode(ENCODER_BTN, INPUT_PULLUP);  
  pinMode(LED_BUILTIN, OUTPUT);  
}  
  
void loop() {  
  if (digitalRead(ENCODER_BTN) == LOW) {  
    digitalWrite(LED_BUILTIN, HIGH);  
  } else {  
    digitalWrite(LED_BUILTIN, LOW);  
  }  
}
```

## Keyboard control

To control the rotary encoder with the keyboard, first click on it, then use the following keys:

| Key | Function |
| --- | --- |
| Right / Up | Rotate one step clockwise* |
| Left / Down | Rotate one step counterclockwise* |
| Spacebar | Press the button |

* Hold down the arrow keys to continuously rotate the encoder,
generating a series of pulses on the CLK/DT pins.