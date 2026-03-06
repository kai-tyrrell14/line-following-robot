# Sensor Calibration
**Sensor Array:** 7-Channel IR Line Sensor

**Controller:** Arduino Uno

**Active Sensors:** 6

## 1. Overview
The sensor calibration process was necessary to ensure reliable reflectance limits for the line-following controller.

The robot estimates the position of the line by converting raw sensor readings into a scaled black-strength value. This is
dependent on reliable black and white calibration boundaries.

Hence, these calibrations are necessary in order to ensure reliable line tracking.

## 2. Calibration Objectives
The sensor calibration procedure aimed to:
- Identify reliable sensor readings for black tape and the background surface.
- To confirm the correct positioning of each sensor.
- To ensure the weightings given to each sensor value accurately estimate the lines position.

## 3. Calibration Method
### 3.1 Raw Reflectance Test
A sensor testing Arduino sketch was implemented that printed the raw reflectance readings to the serial monitor.

The sensor array was tested on:
- The black tape used for the track
- The background surface
- A plain white surface

This allows for a measureable contrast between the line and the background surface.

### 3.2 Sensor Position Verification
The same sketch was used to confirm the position of each sensor in relation to the connection to the Arduino's analog connections.

Black tape was held under each sensor, one at a time, while monitoring the position of the output in the serial monitor. This
is crucial since the weightings given to each sensor value is dependent on the sensors being set left to right.

Incorrect positioning of the sensors was an early issue in testing as it led to incorrect line tracking behaviour.

## 4. Final Calibration Values
| Parameter | Value | Function |
|-----------|-------|----------|
| 'whiteLevel' | 50 | Lower bound for background reflectance |
| 'blackLevel' | 750 | Upper bound for black line reflectance |
| Sensor Order | Left -> Right | As required for correct position weighting |

### Final Sensor Order
| Physical Position | Arduino Pin |
|-------------------|-------------|
| Sensor 1 | A0 |
| Sensor 2 | A1 |
| Sensor 3 | A2 |
| Sensor 5 | A3 |
| Sensor 6 | A4 |
| Sensor 7 | A5 |
