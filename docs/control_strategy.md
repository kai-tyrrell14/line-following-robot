# Control Strategy
## 1. Overview
The project implements a closed-loop system to follow a black line against a contrasted background. The control strategy aims
to convert IR readings from the sensor array into a single estimated position of the line. Adjustments are then made to the 
speed of each motor to control steering and maintain alignment with the line.

The system uses a proportional-derivative (PD) controller to generate these motor adjustments based on the estimated position
of the line relative to the centre of the robot.

Additional logic was implemented for turns with a smaller radius to ensure accurate tracking of the line.

## 2. Line Position Estimation
The robot uses a 7-channel IR sesnor array to detect the position of the line, however since the Arduino Uno used only has six 
analog ports the middle sensor (4th) is not used. Since the black tape reflects less infrared light than the lighter background, the robot is able to easily follow the track. Calibration levels are applied to the raw readings recieved from the array and then they are weighted according to position. These weighted positions are then used to estimate the position of the line.

| Sensor Position | Weighting |
|-----------------|-----------|
| Sensor 1 (Leftmost) | -6 |
| Sensor 2 | -4 |
| Sensor 3 | -2 |
| Sensor 5 | 2 |
| Sensor 6 | 4 |
| Sensor 7 (Rightmost) | 6 |

## 3. Tracking Error
The tracking error measures the difference between the current estimated line position and the centre of the robot. If the line is detected to the left of the robot's centre the tracking error will be negative and when to the right of the centre it will be positive.

This error value is the primary input for steering control.

## 4. PD Controller
A PD controller is implemented to convert the tracking error input into steering control. The proportional term generates
the necessary steering proportional to the magnitude of the steering error, whilst the derivative term takes in the rate of change of the error. This approach helps the robot steer towards the line when it is off centre and reduces oscillations and improves stability.

## 5. Derivative Filtering
Sensor readings may contain unwanted noise, which can cause errors in the derivative calculation. To combat this a low-pass filter was implemented to reduce any unwanted noise. This filtering improved stability whilst still maintaining responsiveness in case of turns in quick succession.

## 6. Hard Turn Logic
During small radius turns or u-turns, the standard steering control may not be able to effectively maintain alignement with the track. To address this issue, a hard turn mode was implemented and applied when the tracking error exceeds a given threshold. This mode includes:
- Reducing the base speed of the robot.
- Sharply increasing the speed of the outer wheel.
- Sharply reducing or stopping the speed of the inner wheel.

This resulted in the robot more effectively managing sharp turns.

## 7. Lost Line Recovery
In situations where line following fails and the sensor array is unable to track the line, logic is implemented to ensure the robot can effectively find the track. This logic keeps track of where the line was most recently found and turns the robot in that direction. If the line is unable to be found in a period of time, the direction of turns switches to prevent the robot just spinning in a circle continuously. Once the line is found, normal line following logic resumes.
