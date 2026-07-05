# LED Blink Project


Tinkercad link -
https://www.tinkercad.com/things/1iCxPJQKa3m-potentiometer?sharecode=aUW8fjXe2XdUgTx44Izi57uoDKwkyqhskV9TIUPJd3I
## Project Title

Basic LED Blink using Arduino Uno

---

## Hardware Required

- Arduino Uno
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable

---

## Circuit Diagram Description

The LED is connected to digital pin 13 through a 220Ω resistor.

The cathode terminal of the LED is connected to the GND pin.

Connection sequence:

Arduino Pin 13
↓

220Ω Resistor
↓

LED Anode (+)

LED Cathode (-)
↓

GND

---

## How to Upload Code

### Step 1
Open Arduino IDE.

### Step 2
Connect the Arduino board using a USB cable.

### Step 3
Go to **Tools → Board** and select **Arduino Uno**.

### Step 4
Go to **Tools → Port** and select the correct COM port.

### Step 5
Open `led_blink.ino`.

### Step 6
Click **Verify**.

### Step 7
Click **Upload**.

### Step 8
Wait until "Done Uploading" appears.

---

## Expected Output

The LED connected to pin 13 blinks continuously.

LED ON duration: 1 second

LED OFF duration: 1 second

This cycle repeats indefinitely.

---

## Troubleshooting Tips

### 1. LED polarity check

Ensure the longer leg (anode) is connected towards pin 13 through the resistor.

The shorter leg (cathode) must be connected to GND.

### 2. Board selection

Verify that Arduino Uno is selected from the Board menu.

### 3. COM Port selection

Ensure the correct COM port is selected.

Wrong port selection may cause upload errors.

### 4. Check wiring

Confirm that all jumper wires are properly connected.

### 5. USB Cable

Some USB cables support charging only and cannot transfer data.

---

## Author

Priyanshu Singh Bohra

IIT Jammu Summer School 2026
