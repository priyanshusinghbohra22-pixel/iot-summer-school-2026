# Servo Motor Sweep

This project controls an **SG90 Servo Motor** using an **ESP32**, a **potentiometer**, and a **push button**.

### Features

* Potentiometer controls the servo position from **0° to 180°**.
* Current servo angle is displayed on the Serial Monitor.
* Pressing the button initiates an automatic sweep sequence:

  * **0° → 180° → 0°**

### Components Used

* ESP32
* SG90 Servo Motor
* Potentiometer
* Push Button

### Connections

* Servo Signal → GPIO23
* Potentiometer Middle Pin → GPIO34
* Push Button → GPIO17

### Output

* Displays the current servo angle on the Serial Monitor.
* Shows status messages:

  * `Sweep Started`
  * `Sweep Complete`

