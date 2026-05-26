* Diagram Reference
* wokwi-stepper-motor

On this page

# wokwi-stepper-motor Reference

A bipolar stepper motor

## Pin names

| Name | Description |
| --- | --- |
| A- | Coil A negative signal |
| A+ | Coil A positive signal |
| B+ | Coil B positive signal |
| B- | Coil B negative signal |

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| arrow | Displays an arrow to indicate the position of the stepper. Set to the color of the arrow, e.g. "orange" | "" |
| display | What number to display on the stepper? Valid values "steps", "angle" (in degrees), "none" | "steps" |
| gearRatio | The gear ratio of the motor. set to "1:1" for 200 steps/revolution, "2:1" for 400 steps/revolution, etc. | "1:1" |
| size | The NEMA standard size of the motor. Valid values: "8", "11", "14", "17", "23", "34" | "23" |

## Using the stepper motor

When using a stepper motor you need a driver chip that can supply large amounts of current to the motor's coils. Wokwi supports the common [A4988 driver board](wokwi-a4988.html "wokwi-a4988.md"). You can also wire the stepper motor directly to your microcontroller. Wokwi uses a digital simulation engine, so the coil current is not taken into account.

You can use a variety of Arduino libraries to control the stepper motor: Stepper, AccelStepper, etc.

### Simulation Behavior

The stepper motor moves 1.8 degrees per step (200 steps per revolution). The motor also supports half-stepping (0.9 degrees per step / 400 steps per revolution). You can even use smaller microsteps (e.g. 1/4 or 1/8 step), but the simulated motor only displays the angle in half-step resolution. For more information, check out the [A4988 microstepping configuration table](wokwi-a4988.html#microstepping-configuration "wokwi-a4988.md#microstepping-configuration").