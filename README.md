# Line Following Robot
An Arduino-controlled autonomous robot capable of tracking a black line using an infrared sensor array and closed-loop motor control.

The system estimates the position of the line relative to the robot and continuously adjusts the wheel speeds to maintain alignment with the track.

# 1. Demo
![Robot Demo](media/motion_gif.gif)

This demonstrates the robot navigating a S-curve track.

# 2. Features
- Differential-drive autonomous robot  
- IR sensor array for track detection  
- Weighted sensor position estimate 
- PD steering control  
- Hard turn mode for tight radius curves 
- Lost line recovery  

# 3. Hardware

| Component | Description |
|--------|--------|
| Arduino Uno | Microcontroller |
| TB6612FNG Motor Driver | Dual DC motor driver |
| IR Line Sensor Array | 7-channel IR sensor array |
| 2 x DC Gear Motors| Drive motors |
| Chassis | Robot base |
| 7.4V LiPo Battery | Power supply |

# 4. System Design

The system consists of three primary subsystems.

## 4.1 Mechanical System

The robot uses a differential-drive system with two wheels powered by DC motors and a front caster wheel for support. The speeds of the left and right motors are adjusted to control steering, with the sensor mounted in front of the wheels to ensure sufficient reaction time.

## 4.2 Electrical System
The electrical system integrates sensing, control, and actuation components. The Arduino inputs analog signals from the sensor array before computing the necessary PWM and direction signals to send to the TB6612FNG motor driver. The motor driver regulates the power supplied to the DC motors to ensure reliable performance.

## 4.3 Control System
The robot implements a closed-loop strategy where the motors outputs are based on the sensors inputs. The raw reflectance readings from the sensor array are calibrated and converted into weighted position estimates resulting in a single position estimate of the line. A proportional-derivative (PD) controller generates steering corrections which adjust the left and right motor speeds.

Additional control features were implemented to improve performance in various track sections:
- Derivative filtering  
- Dynamic speed adjustment during turns  
- Hard turn mode for tight corners  
- Lost line recovery mode

System diagrams are available in the 'diagrams' folder.

# 5. Repository Structure
An overview of the files included in this repository:
- **'/analysis':** Calibration, testing, and performance analysis  
- **'/code':** Arduino control software  
- **'/diagrams':** System design diagrams  
- **'/docs':** Project documentation  
- **'/electronics':** Wiring diagrams and pinout reference  
- **'/media':** Demonstration images and videos  

# 6. Engineering Challenges
Several issues were encountered during the design process and resolved through testing:
- Incorrect sensor ordering initially caused incorrect steering behaviour.
- Robot direction bias produced drift during straight-line motion.
- S-curve sections typically understeered on the second curve.  
- Tight U-turns required additional hard turn logic.  
- Lost line behaviour required improved recovery logic.

More information can be found in 'analysis/failure_analysis/debugging_log.md'

# 7. Future Improvements
Possible future improvements include:
- Closed-loop motor speed control using wheel encoders.
- Improved sensor resolution for more accurate line detection.
- Improved chassis design for more efficient component mounting.
- Automatic sensor calibration for different tracks and backgrounds. 

More information can be found in 'docs/future_improvements.md'
