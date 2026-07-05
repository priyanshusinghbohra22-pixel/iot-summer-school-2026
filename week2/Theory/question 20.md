setup()
Executes only once when the Arduino/ESP32 starts.
Used for initialization such as:
pinMode()
Serial.begin()
sensor initialization


loop()
Executes continuously after setup().
Contains the main program logic.
What happens if a long delay() is used inside loop()?
The microcontroller stops executing other tasks during the delay.
Sensor readings become slow.
Button presses may be missed.
Overall responsiveness decreases.


Non-blocking Alternative

The non-blocking alternative is:

millis()

Using millis() allows multiple tasks to run simultaneously without stopping program execution.

Example: Reading a sensor every second while continuously checking button inputs.
