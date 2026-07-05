# LED Blink with Potentiometer Control

Tinkercad link-
https://www.tinkercad.com/things/1iCxPJQKa3m-potentiometer?sharecode=aUW8fjXe2XdUgTx44Izi57uoDKwkyqhskV9TIUPJd3I

# LED Blink with Potentiometer Control

## Project Description
This project demonstrates LED blinking using Arduino with potentiometer-based speed control. The potentiometer adjusts the blinking interval dynamically.

---

## Hardware Required

- Arduino UNO / ESP32
- LED
- 220Ω Resistor
- Potentiometer (10kΩ)
- Breadboard
- Jumper Wires
- USB Cable

---

## Circuit Diagram Description

Connections:

LED Anode (+) → Pin 13 through 220Ω resistor

LED Cathode (−) → GND

Potentiometer:
- Left Pin → 5V
- Middle Pin → A0
- Right Pin → GND

---

## Uploading Code

### Step 1
Connect Arduino to PC using USB cable.

### Step 2
Open Arduino IDE.

### Step 3
Select the correct Board.

Tools → Board → Arduino UNO

### Step 4
Select COM Port.

Tools → Port → COMx

### Step 5
Open the sketch.

### Step 6
Click Verify.

### Step 7
Click Upload.

---

## Expected Output

- LED blinks continuously.
- Rotating potentiometer changes blink speed.
- Lower resistance → Faster blinking.
- Higher resistance → Slower blinking.

---

## Troubleshooting Tips

### 1. LED not blinking
Check resistor and LED polarity.

### 2. Potentiometer not affecting speed
Verify middle pin is connected to A0.

### 3. Upload failed
Check COM port selection and USB cable connection.

---

## Author

Priyanshu Singh Bohra

IIT Jammu Summer Internship 2026

IoT, Robotics and Drones
