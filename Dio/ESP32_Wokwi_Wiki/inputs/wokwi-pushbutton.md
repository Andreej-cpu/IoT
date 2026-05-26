* Diagram Reference
* wokwi-pushbutton

On this page

# wokwi-pushbutton Reference

12mm Tactile Switch Button (momentary push button).

## Pin names

| Name | Description |
| --- | --- |
| 1.l / 1.r | First contact (left / right) |
| 2.l / 2.r | Second contact (left / right) |

The push button has two set of pins (contacts), 1 and 2.
When the push button is pressed, it connects these two contacts, thus closing an electrical circuit.

Each contact has a pin of the left side of the push button, and another pin on the right side of the push button.
So pin `1.l` is the left pin for first contact, and `1.r` is the right pin for the first contact. Since both belong
to the same contact, they are always connected, even when the button is not pressed.

The following diagram illustrates the connections inside the pushbutton:

![Pushbutton connection diagram](data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTU5bW0iIGhlaWdodD0iNzQuNm1tIiB2ZXJzaW9uPSIxLjEiIHZpZXdCb3g9Ii0zIDAgMTU5IDc0LjYiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiPgogPGRlZnM+CiAgPGxpbmVhckdyYWRpZW50IGlkPSJhIiB4MT0iMi4xOCIgeDI9IjkuODIiIHkxPSIyLjE4IiB5Mj0iOS44MiIgZ3JhZGllbnRVbml0cz0idXNlclNwYWNlT25Vc2UiPgogICA8c3RvcCBzdG9wLWNvbG9yPSIjZmZmIiBvZmZzZXQ9IjAiLz4KICAgPHN0b3Agc3RvcC1jb2xvcj0icmVkIiBvZmZzZXQ9Ii4zIi8+CiAgIDxzdG9wIHN0b3AtY29sb3I9InJlZCIgb2Zmc2V0PSIuNSIvPgogICA8c3RvcCBvZmZzZXQ9IjEiLz4KICA8L2xpbmVhckdyYWRpZW50PgogPC9kZWZzPgogPGcgZmlsbD0iIzk5OSIgc3Ryb2tlLXdpZHRoPSIzLjc4Ij4KICA8cGF0aCBkPSJtMzUuMiA5LjEzYy0wLjM2MyAwLTAuNjU2IDAuMjkzLTAuNjU2IDAuNjU2djIuNDFoLTEzLjRjLTAuNzI3IDAtMS4zMSAwLjU4My0xLjMxIDEuMzF2My4xNmMwIDAuNzI3IDAuNTgzIDEuMzEgMS4zMSAxLjMxaDEzLjR2Mi41MWMwIDAuMzYzIDAuMjkzIDAuNjUzIDAuNjU2IDAuNjUzaDc5LjFjMC4zNjMgMCAwLjY1My0wLjI5IDAuNjUzLTAuNjUzdi0yLjUxaDEzLjRjMC43MjcgMCAxLjMxLTAuNTg3IDEuMzEtMS4zMXYtMy4xNmMwLTAuNzI3LTAuNTgzLTEuMzEtMS4zMS0xLjMxaC0xMy40di0yLjQxYy03ZS01IC0wLjM2My0wLjI5LTAuNjU2LTAuNjUzLTAuNjU2aC03N3oiLz4KICA8cGF0aCBkPSJtMzUuMiA1My42Yy0wLjM2MyAwLTAuNjU2IDAuMjkzLTAuNjU2IDAuNjU2djIuNDFoLTEzLjRjLTAuNzI3IDAtMS4zMSAwLjU4Ny0xLjMxIDEuMzF2My4xNmMwIDAuNzI3IDAuNTgzIDEuMzEgMS4zMSAxLjMxaDEzLjR2Mi41MWMwIDAuMzYzIDAuMjkzIDAuNjU2IDAuNjU2IDAuNjU2aDc5LjFjMC4zNjMgMCAwLjY1My0wLjI5MyAwLjY1My0wLjY1NnYtMi41MWgxMy40YzAuNzI3IDAgMS4zMS0wLjU4MyAxLjMxLTEuMzF2LTMuMTZjMC0wLjcyNy0wLjU4My0xLjMxLTEuMzEtMS4zMWgtMTMuNHYtMi40MWMwLTAuMzYzLTAuMjktMC42NTYtMC42NTMtMC42NTZoLTc3eiIvPgogPC9nPgogPHBhdGggZD0ibTQwLjEgMGMtMS41MiAwLTIuNzQgMS4yMi0yLjc0IDIuNzN2NjkuMWMwIDEuNTIgMS4yMiAyLjczIDIuNzQgMi43M2g2OS4xYzEuNTIgMCAyLjc0LTEuMjIgMi43NC0yLjczdi02OS4xYzAtMS41Mi0xLjIyLTIuNzMtMi43NC0yLjczem0zLjI0IDQuNjZoNjIuN2MwLjcyNyAwIDEuMzEgMC41ODcgMS4zMSAxLjMxdjYyLjdjMCAwLjcyNy0wLjU4NCAxLjMxLTEuMzEgMS4zMWgtNjIuN2MtMC43MjcgMC0xLjMxLTAuNTg0LTEuMzEtMS4zMXYtNjIuN2MwLTAuNzI3IDAuNTg0LTEuMzEgMS4zMS0xLjMxeiIgZmlsbD0iIzQ2NDY0NiIgc3Ryb2tlLXdpZHRoPSI2LjIyIi8+CiA8cmVjdCB4PSI0Mi4xIiB5PSI0LjY2IiB3aWR0aD0iNjUuMyIgaGVpZ2h0PSI2NS4zIiByeD0iMS4zMSIgcnk9IjEuMzEiIGZpbGw9IiNlYWVhZWEiIGZpbGwtb3BhY2l0eT0iLjMwMiIgc3Ryb2tlLXdpZHRoPSI2LjIyIi8+CiA8ZyB0cmFuc2Zvcm09Im1hdHJpeCg2LjIyIDAgMCA2LjIyIDM3LjQgMCkiIHN0cm9rZS1saW5lY2FwPSJyb3VuZCI+CiAgPHJlY3QgeD0iNS45NCIgeT0iNy4wMSIgd2lkdGg9Ii4zMzEiIGhlaWdodD0iMS43NyIgc3Ryb2tlLXdpZHRoPSIuMDU2OSIvPgogIDxjaXJjbGUgY3g9IjYuMTEiIGN5PSI2Ljk0IiByPSIuMzE4IiBzdHJva2Utd2lkdGg9Ii4xNCIvPgogIDxyZWN0IHg9IjUuOTQiIHk9IjMuMzEiIHdpZHRoPSIuMzMxIiBoZWlnaHQ9IjEuNzciIHN0cm9rZS13aWR0aD0iLjA1NjkiLz4KICA8cmVjdCB0cmFuc2Zvcm09InJvdGF0ZSgtMzguNCkiIHg9Ii4zMTUiIHk9IjcuMzQiIHdpZHRoPSIuMzMxIiBoZWlnaHQ9IjEuNzciIHN0cm9rZS13aWR0aD0iLjA1NjkiLz4KICA8Y2lyY2xlIGN4PSI2LjA4IiBjeT0iNS4yNSIgcj0iLjMxOCIgc3Ryb2tlLXdpZHRoPSIuMTQiLz4KIDwvZz4KIDxnIHRyYW5zZm9ybT0ibWF0cml4KDYuMjIgMCAwIDYuMjIgMzcuNCAwKSIgb3BhY2l0eT0iLjQyNiI+CiAgPGNpcmNsZSBjbGFzcz0iYnV0dG9uLWNpcmNsZSIgY3g9IjYiIGN5PSI2IiByPSIzLjgyIiBmaWxsPSJ1cmwoI2EpIi8+CiAgPGNpcmNsZSBjeD0iNiIgY3k9IjYiIHI9IjIuOSIgZmlsbD0iI2YwMCIgc3Ryb2tlPSIjMmYyZjJmIiBzdHJva2Utb3BhY2l0eT0iLjQ3IiBzdHJva2Utd2lkdGg9Ii4wOCIvPgogPC9nPgogPGcgZm9udC1mYW1pbHk9InNhbnMtc2VyaWYiIGZvbnQtc2l6ZT0iMTVweCI+CiAgPHRleHQgeD0iLTIiIHk9IjIwIj4xLmw8L3RleHQ+CiAgPHRleHQgeD0iLTIiIHk9IjY1Ij4yLmw8L3RleHQ+CiAgPHRleHQgeD0iMTM1IiB5PSIyMCI+MS5yPC90ZXh0PgogIDx0ZXh0IHg9IjEzNSIgeT0iNjUiPjIucjwvdGV4dD4KIDwvZz4KPC9zdmc+Cg==)

When working with Arduino, you'd usually connect one contact (e.g. `1.r` or `1.l`) to a digital pin and configure
that pin as `INPUT_PULLUP`, and the other contact (e.g. `2.r` or `2.l`) to the ground. The digital pin will read
`LOW` when you press the button, and `HIGH` when the button is not pressed.

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| color | The color of the push button | "red" |
| xray | Show internal wiring: "1" or "" | "" |
| label | Text that appears below the button | "" |
| key | Keyboard shortcut for button |  |
| bounce | Set to "0" to disable bouncing | "" |

### Defining a keyboard shortcut

You can use the "key" attribute to define a keyboard key that will control the button.
The key is only active when the simulation is running and the diagram has focus.

For example, suppose you defined "key" to "Q". Then, when you run the simulation,
pressing *Q* in the keyboard will press the push button. The button will be kept
in pressed state as long as you keep pressing *Q*, and once you release the key,
the button will also be released.

You can define any alphanumerical keyboard shortcut (so English letters and numbers), and for letters,
the value of "key" is case insensitive (so "q" and "Q" mean the same).

You can also target some special keys, such as "Escape", "ArrowUp", "F8", " " (space), or "PageDown", but some keys
could be blocked by the browser (e.g. "F5" that refreshes the page).
The full list of key names can be found [here](https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent/key/Key_Values "https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent/key/Key_Values").
Note the the special key names are case sensitive - so "Escape" will work, "escape" won't.

Firefox users: if the keyboard shortcuts don't work for you, please make sure that the "Search for text when you start typing" setting is disabled.

### Bouncing

When you press physical pushbutton, the circuit opens and closes tens or hundreds of times.
This phenomenon is called Bouncing. This happens because of the mechanical nature of pushbuttons:
when the metal contacts come together, there's a brief period when the contact isn't perfect, which
causes a series of rapid open/close transitions.

Wokwi simulates button bouncing by default. You can disable bouncing simulation by setting the
"bounce" attr to "0":

`{ "bounce": "0" }`

The bouncing simulation follows the behaviour described in "The Art of electronics" by Horowitz & Hill:

> When the switch is closed, the two contacts actually separate and reconnect, typically 10 to 100
> times over a period of about 1ms.

For example, [this project shows the difference between bouncing and non bouncing button](https://wokwi.com/projects/288681423014986248 "https://wokwi.com/projects/288681423014986248"). It has two buttons connected to the same Arduino input pin:

* The blue button does not simulate bouncing. Pressing on it once will only print a single pair of "pressed" and "released" messages.
* The red button simulates bouncing. Pressing on it once will print multiple "pressed" and "released" messages.

### Stickiness

If you want the button to stay pressed, Ctrl-click it (Cmd-click on Mac). It will cause the button to stay pressed until the next click.
This is useful when you need multiple buttons pressed at the same time.

## Automation controls

The pushbutton can be controlled using [Automation Scenarios](wokwi-ci/automation-scenarios.md "../wokwi-ci/automation-scenarios.md"). It exposes the following controls:

| Control | Type | Description |
| --- | --- | --- |
| pressed | int | Set to 1 to press the button, 0 to release it. |

The following example simulates a button press on "btn1" for 200ms:

```yaml
- set-control:  
    part-id: btn1  
    control: pressed  
    value: 1  
- delay: 200ms  
- set-control:  
    part-id: btn1  
    control: pressed  
    value: 0
```