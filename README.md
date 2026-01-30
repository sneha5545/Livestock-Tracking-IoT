# Livestock-Tracking-IoT
IoT-based livestock tracking system using GPS and Python
## Introduction
GPS-based tracking systems are widely used in applications such as vehicle and asset tracking. This project presents an IoT-based livestock tracking system that uses a GPS module and Arduino to monitor real-time location of animals.

## Bill of Materials
- Arduino Nano
- GPS Neo-6M Module
- GSM SIM800L Module (optional)
- Push Button
- 10K Resistor
- Zero PCB
- Power Supply
- ## Components Used

### Arduino Nano
Arduino Nano acts as the main controller of the system and processes GPS data.

### GPS Neo-6M Module
The GPS module receives latitude and longitude data from satellites.

### GSM SIM800L Module (Optional)
Used for sending location details through SMS in future enhancements.
## Circuit Diagram
- GPS TX connected to Arduino RX  
- GPS RX connected to Arduino TX  
- Power supply connected to Arduino and GPS module  
## Code
The Arduino program reads GPS coordinates and displays latitude and longitude through the serial monitor.

File: sketch_apr3a.ino
## Working of Project
1. GPS module receives signals from satellites.
2. Arduino reads GPS data using serial communication.
3. Location data is processed and displayed.
## Applications
- Livestock tracking and monitoring
- Theft prevention
- Farm management systems
