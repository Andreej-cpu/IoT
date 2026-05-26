* Diagram Reference
* wokwi-7segment

On this page

# wokwi-7segment Reference

Seven segment LED display

## Pin names

| Name | Description |
| --- | --- |
| A | Top segment |
| B | Top-right segment |
| C | Bottom-right segment |
| D | Bottom segment |
| E | Bottom-left segment |
| F | Top-left segment |
| G | Middle segment |
| DP | Dot LED |
| COM | Common pin* |
| DIG1 | Digit 1 pin* |
| DIG2 | Digit 2 pin* |
| DIG3 | Digit 3 pin* |
| DIG4 | Digit 4 pin* |
| CLN | Colon pin (optional) |

* COM is the common pin for a single digit 7-segment display. For multi digit displays, use DIG1…DIG4.

With the default `common` attribute setting of `anode`, the segment pins (A…G, DP, CLN) are connected to the cathode (negative side) of the LEDS, and the common pins (COM, DIG1…DIG4) are connected to the anode (positive side) of the LEDs. Segments are lit by driving their pins low. Setting `common` to `cathode` reverses this behavior, with the segment pins turning on when high.

The segment mapping is as follows:

![7-segment display segment mapping](data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iNTIuOW1tIiBoZWlnaHQ9Ijc2LjZtbSIgdmlld0JveD0iMCAwIDUyLjkgNzYuNiIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KICA8ZyBmaWxsPSIjNDQ0Ij4KICAgIDxjaXJjbGUgY3g9IjQ4LjQiIGN5PSI3MS42IiByPSI0LjQ5Ii8+CiAgICA8cGF0aCBkPSJNMTIuOTE2IDQuMDggMTcuNTcgMGgyNC40OGwzLjUwNiA0LjA4LTQuNjU0IDQuMDhoLTI0LjQ4ek00NS42ODYgNC44NDJsMy41MDYgNC4wOC0zLjQ0NCAyNC40OC00LjY1NCA0LjA4LTMuNTA2LTQuMDggMy40NDQtMjQuNDh6TTQxLjE1NCAzOS4xOGwzLjUwNiA0LjA4LTMuNDQ0IDI0LjQ4LTQuNjU0IDQuMDgtMy41MDYtNC4wOEwzNi41IDQzLjI2ek0zNi4zNzIgNzIuNDVsLTQuNjU0IDQuMDhINy4yMzhsLTMuNTA2LTQuMDggNC42NTQtNC4wOGgyNC40OHpNMy41MDIgNzEuODJsLTMuNTA2LTQuMDhMMy40NCA0My4yNmw0LjY1NC00LjA4IDMuNTA2IDQuMDgtMy40NDQgMjQuNDh6TTguMTc0IDM3LjQ4MmwtMy41MDYtNC4wOCAzLjQ0NC0yNC40OCA0LjY1NC00LjA4IDMuNTA2IDQuMDgtMy40NDQgMjQuNDh6TTQwLjk2NCAzOC4zM2wtNC42NTQgNC4wOEgxMS44M2wtMy41MDYtNC4wOCA0LjY1NC00LjA4aDI0LjQ4eiIvPgogIDwvZz4KICA8dGV4dCBmaWxsPSIjZmZmIiBmb250LWZhbWlseT0ic2Fucy1zZXJpZiIgZm9udC1zaXplPSI4LjkiIGZvbnQtd2VpZ2h0PSJib2xkIj4KICAgIDx0c3BhbiB4PSIyNS44MDciIHk9IjcuMzE4Ij5BPC90c3Bhbj4KICAgIDx0c3BhbiB4PSIzOS44NCIgeT0iMjQuNDE4Ij5CPC90c3Bhbj4KICAgIDx0c3BhbiB4PSIzNS42NTQiIHk9IjU4Ljc5OSI+QzwvdHNwYW4+CiAgICA8dHNwYW4geD0iMTYuMTk1IiB5PSI3NS43NjUiPkQ8L3RzcGFuPgogICAgPHRzcGFuIHg9IjIuNjQzIiB5PSI1OC43OTkiPkU8L3RzcGFuPgogICAgPHRzcGFuIHg9IjIxLjE3MiIgeT0iNDEuNjA0Ij5HPC90c3Bhbj4KICAgIDx0c3BhbiB4PSI3LjMzNCIgeT0iMjQuNDE4Ij5GPC90c3Bhbj4KICAgIDx0c3BhbiB4PSI0NC4xMTciIHk9IjczLjU0IiBmb250LXNpemU9IjUuMzQiPkRQPC90c3Bhbj4KICA8L3RleHQ+Cjwvc3ZnPgo=)

And the digit mapping:

![7-segment display digit mapping](data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTIybW0iIGhlaWdodD0iNTIuOW1tIiB2aWV3Qm94PSIwIDAgMTIyIDUyLjkiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiPgogPHJlY3Qgd2lkdGg9IjEyMiIgaGVpZ2h0PSI1Mi45Ii8+CiAgPGcgaWQ9ImRpZ2l0IiBmaWxsPSIjNDQ0IiB0cmFuc2Zvcm09InNjYWxlKDAuNSkgdHJhbnNsYXRlKDIgMjQpIj4KICAgIDxjaXJjbGUgY3g9IjQ4LjQiIGN5PSI3MS42IiByPSI0LjQ5Ii8+CiAgICA8cGF0aCBkPSJNMTIuOTE2IDQuMDggMTcuNTcgMGgyNC40OGwzLjUwNiA0LjA4LTQuNjU0IDQuMDhoLTI0LjQ4ek00NS42ODYgNC44NDJsMy41MDYgNC4wOC0zLjQ0NCAyNC40OC00LjY1NCA0LjA4LTMuNTA2LTQuMDggMy40NDQtMjQuNDh6TTQxLjE1NCAzOS4xOGwzLjUwNiA0LjA4LTMuNDQ0IDI0LjQ4LTQuNjU0IDQuMDgtMy41MDYtNC4wOEwzNi41IDQzLjI2ek0zNi4zNzIgNzIuNDVsLTQuNjU0IDQuMDhINy4yMzhsLTMuNTA2LTQuMDggNC42NTQtNC4wOGgyNC40OHpNMy41MDIgNzEuODJsLTMuNTA2LTQuMDhMMy40NCA0My4yNmw0LjY1NC00LjA4IDMuNTA2IDQuMDgtMy40NDQgMjQuNDh6TTguMTc0IDM3LjQ4MmwtMy41MDYtNC4wOCAzLjQ0NC0yNC40OCA0LjY1NC00LjA4IDMuNTA2IDQuMDgtMy40NDQgMjQuNDh6TTQwLjk2NCAzOC4zM2wtNC42NTQgNC4wOEgxMS44M2wtMy41MDYtNC4wOCA0LjY1NC00LjA4aDI0LjQ4eiIvPgogIDwvZz4KICA8dXNlIHhsaW5rOmhyZWY9IiNkaWdpdCIgeD0iMzAuNzQiIC8+CiAgPHVzZSB4bGluazpocmVmPSIjZGlnaXQiIHg9IjYxLjU0IiAvPgogIDx1c2UgeGxpbms6aHJlZj0iI2RpZ2l0IiB4PSI5Mi4zNCIgLz4KICA8dGV4dCBmaWxsPSIjZTZlNmU2IiBmb250LWZhbWlseT0ic2Fucy1zZXJpZiIgZm9udC1zaXplPSI4LjU1Ij4KICAgIDx0c3BhbiB4PSI0LjgxNSIgeT0iOS40MjMiPkRJRzE8L3RzcGFuPiA8dHNwYW4geD0iMzUuNDE1IiB5PSI5LjMxNCI+RElHMjwvdHNwYW4+IDx0c3BhbiB4PSI2Ni4yMzUiIHk9IjkuMzE0Ij5ESUczPC90c3Bhbj4gPHRzcGFuIHg9Ijk2Ljg5NyIgeT0iOS4wOTUiPkRJRzQ8L3RzcGFuPgogIDwvdGV4dD4KPC9zdmc+Cg==)

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| common | The common pin: "cathode" or "anode" | "anode" |
| digits | Number of digits: "1", "2", "3" or "4" | "1" |
| colon | Set to "1" to show the colon (clock mode) | "" |
| color | The color of the segment LEDs | "red" |

## Using the 7-segment display

For a single digit, you'll need 8 microcontroller GPIO pins. Each pin should be connected to a single segment through a resistor,
and the common pin should be connected to 5V (or GND if you are using the common cathode variant). You can spare one pin (DP) if you don't use the dot LED. Turn a segment on by driving the corresponding segment on (or HIGH for the common cathode variant).

For multiple digits, you'll need 8 microcontroller pins for the segments and the dot plus one extra microcontroller pin for each digit. So if you have 4 digits, you'll need 12 microcontroller pins in total. Controlling the display in this mode is a bit tricky, as you'll need to continuously alternate between the different digits.

Luckily, there are libraries that can help:

* On Arduino: Use the [SevSeg library](https://wokwi.com/projects/344891439152366164 "https://wokwi.com/projects/344891439152366164").
* On the Raspberry Pi Pico: The PIO peripheral can take care of refreshing the display for you. See the [examples](wokwi-7segment.html#simulator-examples "wokwi-7segment.md#simulator-examples") below.

If you are out of microcontroller pins, consider using a [74HC595 Shift Register](wokwi-74hc595.html "wokwi-74hc595.md") to drive the display.