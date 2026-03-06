# Design Overview
## 1. System Details
This project consists of an autonomous differential-drive robot capable of following a track using an array of infrared 
reflectance sensors. The robot determines the position of the line in relation to its centre and adjusts the motor speeds 
accordingly to maintain alignment with the track.

The system is controlled by an Arduino Uno which inputs analog signels from the IR sensor array and generates the necessary 
motor commands. A TB6612FNG motor driver is implemented to control the two DC motors which drive the left and right wheels.

The robot is designed to navigate a test track using a closed-loop strategy and has been tested on straight sections, s-curves 
u-turns.

## 2. Mechanical Design
The robot uses a differential-drive chassis powered by two DC motors and a caster wheel for support. Steering is achieved through
varying the speeds of left and right motors.

The infrared sensor array is mounted underneath the chassis in fron of the two DC motors to ensure sufficient time for the robot
to react to the track. The sensor array is also mounted low enough to ensure sufficient contrast between the track and the background.

## 3. Electrical Design
The electrical system integrates sensing, control and motor actuation components.

The electronics system consists of:
- Arduino Uno microcontroller
- TB6612FNG motor driver
- 7-channel infrared line sensor array
- Two DC geared motors
- External 7.4V LiPo battery

The sensor array produces analog signals, read by the Arduino which calculates the position of the line relative to the centre
of the robot. Using this information, the Arduino determines the necessary PWM and direction signals which are sent to the TB6612FNG.
The motor driver then sends the appropriate signals to each DC motor to continue following the track.

## 4. Control Design
The robot uses a closed-loop control system in order to maintain alignment with the track.

Sensor readings from the sensor array are weighted appropriately and converted into a single estimate of the lines position. 
This estimate is used to calaculate a tracking error which determines the appropriate signals to adjust left and right motor speeds.

Several control features were implemented to improve performance, including:
- Derivative filtering to reduce noise and oscillation.
- Dyanmic speed adjustments during turns.
- Hard turn mode implemented for tight turns.
- Improved lost line recovery.

These features allow the robot to maintain stable line following through various curves.

## 5. Key Design Decisions
The following design decisions were implemented in order to ensure relaible system behaviour:
- A differential drive system was used to allow simple and effective steering.
- A TB6612FNG motor driver was integrated to provide accurate control of the DC motors.
- Weighted sensor positioning was used to more accurately estimate the position of the line.
- A hard turn mode was included to improve performance in tight radius turns.
- Vigorous testing and calibration of sensors and motors was undergone to verify performance.

  These design decisions improved the reliability of the system and allowed the robot to effectively navigate the tracks presented.
