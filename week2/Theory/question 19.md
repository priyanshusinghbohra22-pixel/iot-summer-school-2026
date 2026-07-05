Q19. What is the difference between analogWrite() and analogRead() in Arduino? What is PWM and why is it used? Give a practical IoT example for each.

analogRead()

Used to read analog signals from sensors.
Converts voltage into a digital value.
Arduino UNO range: 0–1023 (10-bit ADC).
Example:
int value = analogRead(A0);

IoT Example: Reading a soil moisture sensor in a smart irrigation system.

analogWrite()

Used to generate a PWM signal on PWM-supported pins.
Controls average output voltage by changing duty cycle.
Arduino UNO range: 0–255.
Example:
analogWrite(9, 128);

IoT Example: Adjusting LED brightness in a smart lighting system.

PWM (Pulse Width Modulation)

PWM is a technique in which a digital signal is switched ON and OFF rapidly to simulate an analog output voltage.

Why is PWM used?

LED brightness control
Motor speed control
Power-efficient output control

Practical IoT Example:
A smart street light automatically changes brightness at night using PWM based on ambient light sensor readings.
