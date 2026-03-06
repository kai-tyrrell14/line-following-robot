# Pinout Reference
**Controller:** Arduino Uno

**Motor Driver:** TB6612FNG

Refer to 'electronics/wiring_diagram.png'.

## 1. Sensor Interface
| Arduino Pin | Sensor Output | Function |
|-------------|---------------|----------|
| A0 | Sensor 1 | Line detection |
| A1 | Sensor 2 | Line detection |
| A2 | Sensor 3 | Line detection |
| A3 | Sensor 5 | Line detection |
| A4 | Sensor 6 | Line detection |
| A5 | Sensor 7 | Line detection |

The centre sensor (sesnor 4) is not used.

## 2. Motor Driver Logic Pins
| Arduino Pin | TB6612FNG Pin | Function |
|-------------|---------------|----------|
| D4 | STBY | Enables motor driver |
| D5 | PWMA | Left motor speed control (PWM) |
| D6 | PWMB | Right motor speed control (PWM) |
| D7 | AIN1 | Left motor direction control |
| D8 | AIN2 | Left motor direction control |
| D9 | BIN1 | Right motor direction control |
| D10 | BIN2 | Right motor direction control |

## 3. Motor Connections
| TB6612FNG Pin | Component | Function |
|---------------|-----------|----------|
| A01 | Left Motor M+ | Left motor output |
| A02 | Left Motor M- | Left motor output |
| B01 | Right Motor M+ | Right motor output |
| B02 | | Right Motor M- | Right motor output |

## 4. Power Distribution
| Source | Destination | Function |
|--------|-------------|----------|
| Battery V+ | Arduino Vin | Arduino power |
| Battery V+ | TB6612FNG Vm | Motor power supply |
| Battery GND | Arduino GND | Common ground |
| Battery GND | TB6612FNG GND | Common ground |
| Arduino 5V | TB6612FNG VCC | Motor driver logic power |
| Arduino 5V | Sensor VCC | Sensor power |
| Arduino GND | TB6612FNG GND | Common ground |
| Arduino GND | Sensor GND | Common ground |
