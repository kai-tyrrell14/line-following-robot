# Power Distribution
**Controller:** Arduino Uno

**Motor Driver:** TB6612FNG

**Motor Supply:** 7.4V LiPo Battery (2S)

## 1. Overview
The system is powered through an 7.4V LiPo battery which provides power to the Arduino Uno and the motors through the TB6612FNG
motor driver. The sensor array and motor driver logic are powered through the Arduino 5V supply.

Separating the logic and motor power prevents voltage drop when motors are accelerating and reduces electrical noise.

All system grounds are connected to provide a common reference.

See 'wiring_diagram.png' for the wiring layout.

## 2. Power Sources
| Subsystem | Voltage | Source | Notes |
|-----------|---------|--------|-------|
| Arduino Uno | 7.4V | LiPo Battery -> Vin | Logic control |
| IR Sensor Array | 5V | Arduino 5V -> VCC | Sensor operation |
| TB6612FNG Logic | 5V | Arduino 5V -> VCC | Motor driver logic |
| Motors | 7.4V | LiPo Battery -> Vm | High current load |

## 3. Power Wiring
### 3.1 Motor Power
- Battery +7.4V -> TB6612FNG Vm
- TB6612FNG A01/A02 -> Left Motor
- TB6612FNG B01/B02 -> Right Motor

### 3.2 Logic Power
- Battery +7.4 -> Arduino Vin
- Arduino 5V -> TB6612FNG VCC
- Arduino 5V -> Sensor Array VCC

### 3.3 Ground / Reference
- Battery GND -> Arduino GND
- Battery GND -> TB6612FNG GND
- Arduino GND -> Sensor Array GND
- Arduino GND -> TB6612FNG GND

## 4. Risk Controls
### 4.1 Electrical Noise Reduction
- Logic power separate from motor power.
- Motor driver separates high-current switching from the microcontroller.

### 4.2 Ground Reference Stability
- Common ground ensures reliable sensor array readings.
