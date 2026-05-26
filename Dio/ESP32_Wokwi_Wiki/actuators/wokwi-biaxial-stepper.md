* Diagram Reference
* wokwi-biaxial-stepper

On this page

# wokwi-biaxial-stepper Reference

A concentric biaxial stepper motor, containing two stepper motors packaged in a single enclosure.

## Pin names

| Name | Description |
| --- | --- |
| A1- | Outer shaft motor's coil A negative signal |
| A1+ | Outer shaft motor's coil A positive signal |
| B1+ | Outer shaft motor's coil B positive signal |
| B1- | Outer shaft motor's coil B negative signal |
| A2- | Inner shaft motor's coil A negative signal |
| A2+ | Inner shaft motor's coil A positive signal |
| B2+ | Inner shaft motor's coil B positive signal |
| B2- | Inner shaft motor's coil B negative signal |

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| outerHandLength | The length of the outer shaft's hand, between "20" and "70" | "30" |
| outerHandColor | The color of the outer shaft's hand | "gold" |
| outerHandShape | The shape of the outer shaft's hand: "plain", "arrow", or "ornate" | "plain" |
| innerHandLength | The length of the inner shaft's hand, between "20" and "70" | "30" |
| innerHandColor | The color of the inner shaft's hand | "silver" |
| innerHandShape | The shape of the inner shaft's hand: "plain", "arrow", or "ornate" | "plain" |

## Using the biaxial stepper motor

The biaxial stepper motor is made of two individual stepper motors. Check out the [wokwi-stepper-motor](wokwi-stepper-motor.html#using-the-stepper-motor "wokwi-stepper-motor.md#using-the-stepper-motor") and [wokwi-a4988](wokwi-a4988.html "wokwi-a4988.md") documentation for more information about using stepper motors and their simulation behavior.