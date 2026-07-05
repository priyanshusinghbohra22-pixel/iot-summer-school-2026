# Ultrasonic Parking Sensor using ESP32

## Overview

This project implements an **Ultrasonic Parking Assistance System** using an ESP32 and an HC-SR04 ultrasonic sensor. The system measures the distance between a vehicle and an obstacle and provides visual and audible feedback through LEDs and a buzzer.

## Features

* Real-time distance measurement
* Multi-level parking assistance alerts
* LED-based status indication
* Variable buzzer warning frequency
* Continuous alarm for critical distance
* Non-blocking implementation using `millis()`
* No `delay()` function used
* Serial Monitor logging

## Components Used

* ESP32 Development Board
* HC-SR04 Ultrasonic Sensor
* Red LED
* Yellow LED
* Green LED
* Passive Buzzer
* 3 × 220Ω Resistors
* Breadboard
* Jumper Wires

## Circuit Connections

| Component    | ESP32 Pin |
| ------------ | --------- |
| HC-SR04 TRIG | GPIO25    |
| HC-SR04 ECHO | GPIO26    |
| Red LED      | GPIO23    |
| Yellow LED   | GPIO22    |
| Green LED    | GPIO21    |
| Buzzer (+)   | GPIO16    |
| Buzzer (-)   | GND       |

## Working Principle

The HC-SR04 sensor sends ultrasonic pulses and measures the echo return time to calculate distance.

Distance is calculated using:

```cpp
distance = (duration × 0.034) / 2;
```

## Alert Conditions

| Distance Range | Status   | LED Indication | Buzzer            |
| -------------- | -------- | -------------- | ----------------- |
| > 50 cm        | SAFE     | Green LED ON   | OFF               |
| 20–50 cm       | Warning  | Yellow LED ON  | Beep every 500 ms |
| 10–20 cm       | Danger   | Red LED ON     | Beep every 200 ms |
| < 10 cm        | Critical | All LEDs Blink | Continuous Sound  |

## Advanced Feature

This project uses **millis() based timing** instead of `delay()` for non-blocking execution, allowing continuous sensor monitoring and responsive alerts.

## Serial Monitor Output Example

```text
Distance: 72.5 cm
SAFE

Distance: 35.2 cm

Distance: 15.4 cm

Distance: 8.1 cm
```

## Applications

* Smart Parking Systems
* Vehicle Reverse Assistance
* Obstacle Detection
* Industrial Safety Systems
* Robotics Navigation
* Autonomous Vehicle Prototypes

## Author

**Priyanshu Singh Bohra**

Date: 05-07-2026

