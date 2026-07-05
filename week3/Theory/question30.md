Q30. (Theory) Explain I2C protocol with respect to IoT sensor communication. What are SDA and SCL lines? How does I2C addressing work? Name 3 common IoT sensors that use I2C. (2 marks)


Answer -

I2C (Inter-Integrated Circuit) is a communication protocol used in IoT systems to connect multiple sensors and devices using only two wires. It enables efficient data exchange between a microcontroller and sensors while reducing wiring complexity.

The two I2C lines are:

* **SDA (Serial Data Line):** Used for transmitting and receiving data.
* **SCL (Serial Clock Line):** Provides the clock signal to synchronize communication between devices.

I2C addressing works by assigning each device a unique address, usually 7-bit or 10-bit. The master device (such as an ESP32 or Arduino) sends the address of the target sensor, and only the device with the matching address responds and communicates.

Three common IoT sensors that use I2C are:

1. **BMP280** – Temperature and pressure sensor
2. **MPU6050** – Accelerometer and gyroscope sensor
3. **BH1750** – Light intensity sensor

