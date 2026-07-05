# LED Blink with Potentiometer Control

Tinkercad link-
https://www.tinkercad.com/things/1iCxPJQKa3m-potentiometer?sharecode=aUW8fjXe2XdUgTx44Izi57uoDKwkyqhskV9TIUPJd3I


## Description
This project demonstrates LED blinking using an ESP32 with speed control through a potentiometer.

The potentiometer value is read using an analog input pin and mapped to control the LED blinking delay.

## Features
- LED blinking
- Potentiometer-based speed control
- Adjustable blinking interval
- Analog input processing

## Components Required
- ESP32 Development Board
- LED
- 220Ω Resistor
- Potentiometer
- Breadboard
- Jumper Wires

## Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| LED | GPIO13 |
| Potentiometer Output | A0 |
| Potentiometer VCC | 3.3V |
| Potentiometer GND | GND |

## Working Principle

1. The potentiometer value is read using `analogRead()`.
2. The value is mapped between 100 ms and 1000 ms.
3. The LED turns ON for the mapped delay period.
4. The LED turns OFF for the same delay period.
5. Changing the potentiometer position changes the blinking speed.

## Code Functions Used

### analogRead()
Reads the potentiometer value.

### map()
Converts the ADC value into a delay range.

### digitalWrite()
Controls LED state.

### delay()
Creates the blinking interval.

## Expected Output

- Rotating the potentiometer changes the LED blinking speed.
- Higher potentiometer values produce slower blinking.
- Lower potentiometer values produce faster blinking.

## Author
Priyanshu Singh Bohra

## Date
05 July 2026
fix: improve potentiometer mapping logic (Fixes #2)
