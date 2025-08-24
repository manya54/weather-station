# weather-station
This is a smart weather monitoring system using two ESP32 microcontrollers. The project collects environmental data, displays it locally, and transmits it wirelessly for remote monitoring.

# Features

# First ESP32: Web Server & LoRa Transmitter
Reads temperature from a DS18B20 One-Wire sensor.
Reads temperature, humidity, and pressure from a BME280 sensor via I2C.
Displays sensor readings on a 16x2 RGB LCD.
Hosts a web server to view real-time readings in a browser.
Transmits the data wirelessly using LoRa.

# Second ESP32: LoRa Receiver & Bluetooth Output
Receives data from the first ESP32 via LoRa.
Sends received data to a Bluetooth terminal on a mobile device.

