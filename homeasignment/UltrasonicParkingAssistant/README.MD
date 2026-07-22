# Project 3: Ultrasonic Parking Assistant

## Overview

The Ultrasonic Parking Assistant is a distance-based warning system inspired by parking sensors used in modern cars. It uses an HC-SR04 ultrasonic sensor to measure the distance between the sensor and a nearby object.

As an object moves closer to the sensor, different LEDs indicate the proximity zone and the buzzer frequency increases. The measured distance is also displayed on an OLED display along with a proximity bar graph.

---

## Components Required

- Arduino Uno R3
- HC-SR04 Ultrasonic Sensor
- Active Buzzer
- Red LED
- Yellow LED
- Green LED
- 220Ω Resistors
- 0.96" I2C OLED Display
- Breadboard
- Jumper Wires

---

## Wiring Connections

| Component | Arduino Connection |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | Pin 9 |
| HC-SR04 ECHO | Pin 10 |
| Buzzer | Pin 6 |
| OLED SDA | A4 |
| OLED SCL | A5 |
| OLED VCC | 5V |
| OLED GND | GND |

Each LED is connected to its assigned digital output pin through an individual 220Ω resistor to GND.

---

## Working Principle

The HC-SR04 ultrasonic sensor measures distance by transmitting an ultrasonic pulse and measuring the time taken for the reflected echo to return.

The distance is calculated using:

Distance = Duration × 0.034 / 2

Where:

- `Duration` is the time taken by the ultrasonic pulse to travel to the object and return.
- `0.034 cm/µs` is the approximate speed of sound.
- The result is divided by 2 because the measured time includes both the forward and return journey of the sound wave.

To reduce fluctuations and noise, the system takes five distance measurements and calculates their average.

---

## Parking Zones

The system divides the measured distance into four proximity zones.

### SAFE

**Distance: Greater than 60 cm**

- Green LED ON
- Yellow LED OFF
- Red LED OFF
- Buzzer OFF

### CAUTION

**Distance: 30–60 cm**

- Yellow LED ON
- Buzzer beeps approximately every 800 ms

### CLOSE

**Distance: 15–30 cm**

- Yellow and Red LEDs ON
- Buzzer beeps approximately every 300 ms

### DANGER

**Distance: Less than 15 cm**

- Red LED ON
- Continuous buzzer alarm

As the object gets closer to the sensor, the warning becomes more urgent.

---

## Distance Averaging

Five ultrasonic distance readings are taken using a `for` loop.

The readings are added together and divided by five to calculate the average distance.

This helps reduce measurement noise and provides a more stable distance value.

---

## OLED Display

The OLED display shows the measured distance in centimetres.

Example:

```text
42 cm
