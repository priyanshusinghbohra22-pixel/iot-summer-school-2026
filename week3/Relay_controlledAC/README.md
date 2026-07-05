# Relay Controlled AC Device Simulation

## Project Description -

is used to simulate an AC appliance using an LED as a relay indicator. The system monitors temperature using a DHT22 sensor and automatically controls the relay based on predefined temperature thresholds.

---

## Hardware Required -

- ESP32
- DHT22 Sensor
- LED
- 220Ω Resistor
- Push Button
- Breadboard
- Jumper Wires
- USB Cable

---

## Libraries Used -

Library Name :

DHT sensor library for ESPx

Version :

1.19.0

Author :

beegee_tokyo

Purpose :

is used to interface DHT22 sensors with ESP32 boards for temperature and humidity monitoring.

---

## Circuit Diagram Description -

DHT22

VCC → 3.3V

DATA → GPIO23

GND → GND


Relay Simulation LED

GPIO22 → 220Ω Resistor → LED → GND


Push Button

GPIO17 → Button → GND

(INPUT_PULLUP enabled)

---

## Features -

Temperature > 32°C

Relay turns ON.


Temperature < 28°C

Relay turns OFF.


Temperature between 28°C and 32°C

Previous relay state is maintained.


Push Button

Provides manual override control.


Serial Monitor

Displays temperature readings and relay status.

---

## How to Upload Code -

Step 1 -

Connect ESP32 to the computer.


Step 2 -

Open Arduino IDE.


Step 3 -

Select the ESP32 Board.


Step 4 -

Select the correct COM Port.


Step 5 -

Install the required library.

Library Manager →

Search :

DHT sensor library for ESPx


Step 6 -

Open the sketch file.


Step 7 -

Click Verify.


Step 8 -

Click Upload.


Step 9 -

Open Serial Monitor.

Baud Rate :

115200

---

## Expected Output -

Temperature : 35°C

Relay : ON


Temperature : 27°C

Relay : OFF


Button Pressed

Manual Override Activated

---

## Troubleshooting Tips -

LED not turning ON -

Check resistor value and LED polarity.


Sensor showing NAN -

Verify DHT22 wiring and selected sensor type.


Button not responding -

Ensure INPUT_PULLUP mode is enabled.


Upload failed -

Check board selection and COM port.

---

## Author -

Priyanshu Singh Bohra

IIT Jammu Summer Internship 2026

IoT, Robotics and Drones
