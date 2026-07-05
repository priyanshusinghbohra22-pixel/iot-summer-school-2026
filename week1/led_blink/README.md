# LED Blink Program

## Description
This project demonstrates a basic LED blinking application using an ESP32. The LED connected to GPIO13 turns ON for one second and then turns OFF for one second repeatedly.

## Objective
- Learn basic GPIO programming on ESP32.
- Understand digital output control.
- Practice using `pinMode()` and `digitalWrite()` functions.

## Components Required
- ESP32 Development Board
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

## Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| LED Anode (+) | GPIO13 |
| LED Cathode (-) | GND (through 220Ω resistor) |

## Working Principle
The program configures GPIO13 as an output pin inside the `setup()` function. Inside the `loop()` function:

1. The LED is turned ON.
2. The program waits for 1 second.
3. The LED is turned OFF.
4. The program waits for another second.
5. This process repeats continuously.

## Code Functions Used

### `pinMode()`
Configures a pin as INPUT or OUTPUT.

### `digitalWrite()`
Sets the output pin HIGH or LOW.

### `delay()`
Pauses program execution for a specified duration in milliseconds.

## Expected Output
The LED connected to GPIO13 blinks continuously with:

- ON Time = 1 second
- OFF Time = 1 second

## Author
Priyanshu Singh Bohra

## Date
05-07-2026
