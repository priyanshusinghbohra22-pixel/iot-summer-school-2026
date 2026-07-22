# Project 2: Gas & Fire Safety Alert System

## Overview

This project is a dual-sensor safety system designed to detect gas leakage and fire. It uses an MQ-2 gas sensor and a flame sensor to monitor potentially dangerous conditions.

The system provides three alert levels:

- SAFE — Green LED
- WARNING — Yellow LED with slow buzzer beeps
- DANGER — Red LED with continuous alarm

Gas and flame conditions are monitored to provide appropriate safety alerts.

## Components Required

- Arduino Uno R3
- MQ-2 Gas Sensor
- Flame Sensor
- Active Buzzer
- Green LED
- Yellow LED
- Red LED
- 220Ω Resistors
- Breadboard
- Jumper Wires

## Wiring Connections

| Component | Arduino Connection |
|---|---|
| MQ-2 VCC | 5V |
| MQ-2 GND | GND |
| MQ-2 AOUT | A0 |
| Flame Sensor VCC | 5V |
| Flame Sensor GND | GND |
| Flame Sensor DO | Pin 7 |
| Flame Sensor AO | A1 |
| Buzzer (+) | Pin 9 |
| Buzzer (-) | GND |
| Green LED | Pin 10 through 220Ω resistor |
| Yellow LED | Pin 11 through 220Ω resistor |
| Red LED | Pin 12 through 220Ω resistor |

## Working Principle

The MQ-2 sensor provides an analog gas reading between 0 and 1023. The program maps this value to a percentage between 0% and 100%.

The gas alert levels are:

- Below 30%: SAFE
- 30% to 60%: WARNING
- Above 60%: DANGER

The flame sensor uses an active-low digital output. This means:

- HIGH = No flame detected
- LOW = Flame detected

The system continuously checks both sensors and activates the appropriate LEDs and buzzer pattern.

## Alert States

### SAFE

When the gas level is below 30% and no flame is detected:

- Green LED turns ON
- Yellow and Red LEDs remain OFF
- Buzzer remains OFF

### WARNING

When the gas level is between 30% and 60% and no flame is detected:

- Yellow LED turns ON
- Buzzer produces approximately one beep per second
- Green and Red LEDs remain OFF

### DANGER

When the gas level exceeds 60% or a flame is detected:

- Red LED turns ON
- Continuous alarm is activated
- Green and Yellow LEDs remain OFF

The system can also distinguish between gas detection, flame detection, and simultaneous gas and flame conditions.

## Non-Blocking Buzzer

The warning buzzer timing is implemented using `millis()` instead of `delay()`.

This allows the Arduino to continue reading the gas and flame sensors while controlling the buzzer timing.

## MQ-2 Warm-Up Requirement

The MQ-2 sensor contains a heating element and requires time to stabilize after being powered on. A warm-up period of approximately 1–2 minutes should be allowed before relying on its readings.

Without sufficient warm-up time, the sensor readings may fluctuate and may not accurately represent the gas concentration.

## Why the Flame Sensor is Active-Low

The digital output of the flame sensor used in this project is active-low. Therefore, the sensor outputs `LOW` when a flame is detected and `HIGH` when no flame is detected.

The program detects a flame using:

`flameDetected = (digitalRead(7) == LOW);`

## Serial Monitor Output

The system prints a formatted status log every second.

Example:

GAS: 15% | FLAME: NONE | STATUS: SAFE

GAS: 45% | FLAME: NONE | STATUS: WARNING

GAS: 75% | FLAME: NONE | STATUS: DANGER

GAS: 25% | FLAME: DETECTED | STATUS: DANGER

## Features

- Gas leakage detection using MQ-2
- Flame detection
- Three-level safety indication
- Green, Yellow, and Red LED indicators
- Warning beep pattern
- Continuous danger alarm
- Non-blocking timing using `millis()`
- Real-time Serial Monitor status
- Independent gas and flame monitoring

## Applications

- Kitchen safety systems
- Gas leakage warning systems
- Basic fire detection systems
- Home safety monitoring
- Industrial safety prototypes

## Conclusion

The Gas & Fire Safety Alert System demonstrates how multiple sensors can be combined to monitor hazardous conditions. The MQ-2 sensor monitors gas levels while the flame sensor detects fire. LEDs, buzzer patterns, and Serial Monitor logs provide clear information about the current safety condition.
