* Diagram Reference
* wokwi-max7219-matrix

On this page

# wokwi-max7219-matrix Dot Matrix Reference

8x8 LED Dot Matrix with MAX7219 Controller

![MAX7219 LED Dot Matrix](data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAzMCAyMCIgaGVpZ2h0PSIyMG1tIiB3aWR0aD0iMzBtbSIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiPgogIDxzdHlsZSB0eXBlPSJ0ZXh0L2NzcyI+CiAgICAubGVkIHsKICAgICAgZmlsbDogdmFyKC0tcGl4ZWwtY29sb3IsIHJlZCk7CiAgICAgIGFuaW1hdGlvbjogbGVkLW9mZnNldCAycyBzdGVwcygyMCwganVtcC1lbmQpIGluZmluaXRlOwogICAgICBvZmZzZXQtcGF0aDogcGF0aCgnTTcuNSAyLjVIMjBNMjIuNSAyLjVWMTVNMjIuNSAxNy41SDEwTTcuNSAxNy41VjUnKTsKICAgICAgb2Zmc2V0LWRpc3RhbmNlOiAwJTsKICAgIH0KCiAgICBAa2V5ZnJhbWVzIGxlZC1vZmZzZXQgewogICAgICBmcm9tIHsKICAgICAgICBvZmZzZXQtZGlzdGFuY2U6IDAlOwogICAgICB9CiAgICAgIHRvIHsKICAgICAgICBvZmZzZXQtZGlzdGFuY2U6IDEwMCU7CiAgICAgIH0KICAgIH0KICA8L3N0eWxlPgogIDxkZWZzPgogICAgPHBhdHRlcm4gaWQ9ImJhY2tncm91bmQiIHdpZHRoPSIyLjUiIGhlaWdodD0iMi41IiBwYXR0ZXJuVW5pdHM9InVzZXJTcGFjZU9uVXNlIj4KICAgICAgPHJlY3Qgd2lkdGg9IjIuNSIgaGVpZ2h0PSIyLjUiIC8+CiAgICAgIDxjaXJjbGUgY3g9IjEuMjUiIGN5PSIxLjI1IiByPSIwLjkiIGZpbGw9IiM0NDQiIC8+CiAgICA8L3BhdHRlcm4+CiAgICA8cGF0aAogICAgICBpZD0icGlubCIKICAgICAgZmlsbD0iI2M2YmY5NSIKICAgICAgZD0ibTcuMDItMC4zOWgtNy4wMmEwLjM5IDAuMzkgMCAwIDAtMC4zNyAwLjM5IDAuMzkgMC4zOSAwIDAgMCAwLjM3IDAuMzl2MGg3LjAyeiIKICAgIC8+CiAgICA8cGF0aAogICAgICBpZD0icGluciIKICAgICAgZmlsbD0iI2M2YmY5NSIKICAgICAgZD0ibS03LjAyLTAuMzloNy4wMmEwLjM5IDAuMzkgMCAwIDEgMC4zNyAwLjM5IDAuMzkgMC4zOSAwIDAgMS0wLjM3IDAuMzl2MGgtNy4wMnoiCiAgICAvPgogIDwvZGVmcz4KICA8dXNlIHhsaW5rOmhyZWY9IiNwaW5sIiB4PSIwLjUzIiB5PSI0LjkyIiAvPgogIDx1c2UgeGxpbms6aHJlZj0iI3BpbmwiIHg9IjAuNTMiIHk9IjcuNDYiIC8+CiAgPHVzZSB4bGluazpocmVmPSIjcGlubCIgeD0iMC41MyIgeT0iMTAiIC8+CiAgPHVzZSB4bGluazpocmVmPSIjcGlubCIgeD0iMC41MyIgeT0iMTIuNTQiIC8+CiAgPHVzZSB4bGluazpocmVmPSIjcGlubCIgeD0iMC41MyIgeT0iMTUuMDgiIC8+CiAgPHVzZSB4bGluazpocmVmPSIjcGluciIgeD0iMjkuNDciIHk9IjQuOTIiIC8+CiAgPHVzZSB4bGluazpocmVmPSIjcGluciIgeD0iMjkuNDciIHk9IjcuNDYiIC8+CiAgPHVzZSB4bGluazpocmVmPSIjcGluciIgeD0iMjkuNDciIHk9IjEwIiAvPgogIDx1c2UgeGxpbms6aHJlZj0iI3BpbnIiIHg9IjI5LjQ3IiB5PSIxMi41NCIgLz4KICA8dXNlIHhsaW5rOmhyZWY9IiNwaW5yIiB4PSIyOS40NyIgeT0iMTUuMDgiIC8+CiAgPHJlY3QgeD0iNSIgd2lkdGg9IjIwIiBoZWlnaHQ9IjIwIiBmaWxsPSJ1cmwoI2JhY2tncm91bmQpIiAvPgogIDxjaXJjbGUgY3g9IjEuMjUiIGN5PSIxLjI1IiByPSIwLjkiIGZpbGw9InJlZCIgY2xhc3M9ImxlZCIgLz4KPC9zdmc+Cg==)

## Pin names

| Name | Description |
| --- | --- |
| VCC | Voltage supply |
| GND | Ground |
| DIN | Data input |
| CS | Chip Select |
| CLK | Clock input |
| DOUT | Data output |

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| chain | How many units to chain together | "1" |
| color | LED color (when lit) | "red" |
| layout | Matrix connection layout: "parola" or "fc16" | "parola" |

### Chaining

Each dot matrix units is an 8x8 LED matrix. All the LEDs in the matrix have the same color. You can make the display wider by setting the "chain" attribute. For example, setting "chain" to 4 will chain four dot matrix units horizontally, resulting in 32x8 matrix (four times 8x8 matrix).

If you want to chain units in a custom way (e.g. select a different pixel color for each unit, chain them vertically, etc), connect the DOUT pin of one unit to the DIN pin of the next unit. You also need to connect the CLK / CS pins of the units together. See [32x32 LED Matrix Tunnel](https://wokwi.com/projects/318864638990090834 "https://wokwi.com/projects/318864638990090834") for an example.

### Matrix layout

There are several type of matrix layout, based on the commonly available modules. You can set the "layout" property to choose the desired pixel layout:

* "parola" - See the [Parola documentation](https://majicdesigns.github.io/MD_MAX72XX/page_parola.html "https://majicdesigns.github.io/MD_MAX72XX/page_parola.md") for information about the layout of these modules
* "fc16" - The FC-16 modules are available from EBay and AliExpress. They usually come in a chain of four 8x8 matrices, so they have 32x8 pixels in total.

Choosing the wrong layout will cause your text / drawing to be rotated and / or mirrored.