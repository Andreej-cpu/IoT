* Diagram Reference
* wokwi-buzzer

On this page

# wokwi-buzzer Reference

A piezoelectric buzzer

## Pin names

| Name | Description |
| --- | --- |
| 1 | Negative(Black) pin |
| 2 | Positive(Red) pin |

## Attributes

| Name | Description | Default value |
| --- | --- | --- |
| mode | Buzzer operation mode: "smooth" or "accurate" | "smooth" |
| volume | Volume (loudness) of the sound, between "0.01" and "1.0" | "1.0" |

### Operation modes

The buzzer can operate in two modes: "smooth" (the default) and "accurate".

"smooth" sounds better and is suitable for simple, single-frequency tones. Use it
when playing a melody or playing tones with Arduino's `tone()` function. Complex and
polyphonic sounds may not play correctly (or not play at all) in "smooth mode"

Use the "accurate" mode when you need to play complex sounds. It will accurately play
the sound you feed in. However, it'll add audible click noises to your sound. These noises
are due to fluctuations in the simulation speed - it's not always able to provide the complete
sound buffer in real time.

## Arduino example

Connect pin 1 of the buzzer to Arduino GND pin, and pin 2 of the buzzer to Arduino pin 8. Then use the `tone()` function to play a sound:

```text
tone(8, 262, 250); // Plays 262Hz tone for 0.250 seconds
```