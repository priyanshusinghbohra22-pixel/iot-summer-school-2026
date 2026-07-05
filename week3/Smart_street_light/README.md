# Smart Street Light using ESP32 (LDR + PIR)

## Overview

This project implements a Smart Street Light system using an ESP32, an LDR sensor, and a PIR motion sensor. The street light automatically responds to ambient light conditions and human movement, helping to conserve energy while ensuring illumination when needed.

## Features

* Automatic day and night detection
* Motion sensing using PIR sensor
* Full brightness illumination when motion is detected at night
* Automatic dimming to 20% brightness after 30 seconds of inactivity
* LED remains OFF during daylight conditions
* Serial Monitor event logging
* PWM-based brightness control

## Components Used

* ESP32 Development Board
* LDR Module
* PIR Motion Sensor
* LED
* Breadboard
* Jumper Wires

## Circuit Connections

| Component | ESP32 Pin |
| --------- | --------- |
| LDR AO    | GPIO27    |
| PIR OUT   | GPIO16    |
| LED       | GPIO22    |
| VCC       | 3.3V / 5V |
| GND       | GND       |

## Working Principle

### Day Mode

When the ambient light intensity indicates daylight conditions, the LED remains OFF.

```cpp
LDR < Threshold → LED OFF
```

### Night Mode

When darkness is detected, motion sensing becomes active.

* Motion detected → LED turns ON at **100% brightness**
* No motion for **30 seconds** → LED dims to **20% brightness**
* PWM is used to control LED intensity

### Brightness Levels

| Condition        | PWM Value | Brightness |
| ---------------- | --------- | ---------- |
| Motion Detected  | 255       | 100%       |
| No Motion (30 s) | 51        | 20%        |
| Daylight         | 0         | OFF        |

## Serial Monitor Output Example

```text
LDR = 3200 PIR = 1
[NIGHT] Motion Detected

LDR = 3250 PIR = 0
[NIGHT] Dim Mode

LDR = 1200 PIR = 0
[DAY] LED OFF
```

## Applications

* Smart Street Lighting
* Energy-Efficient Lighting Systems
* Smart Cities
* Security Monitoring
* Parking Area Lighting
* Campus and Pathway Illumination

## Author

Priyanshu Singh Bohra

Date: 05-07-2026

