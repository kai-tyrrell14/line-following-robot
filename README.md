# Line Following Robot

An Arduino-controlled autonomous robot capable of tracking a black line using an infrared sensor array and closed-loop motor control.

The system estimates the position of the line relative to the robot and continuously adjusts the wheel speeds to maintain alignment with the track.

---

# 1. Demo

![Robot Demo](media/robot_on_track.jpg)

This demonstrates the robot navigating a line track containing straight sections, S-curves, and tight turns.

---

# 2. Features

• Differential-drive autonomous robot  
• Infrared line sensor array for track detection  
• Weighted sensor position estimation  
• PD-based steering control  
• Hard-turn logic for tight-radius corners  
• Lost-line recovery behaviour  
• Motor deadband compensation and trim balancing

---

# 3. Hardware

| Component | Description |
|--------|--------|
| Arduino Uno | Microcontroller |
| TB6612FNG Motor Driver | Dual DC motor driver |
| IR Line Sensor Array | Reflectance-based line detection |
| DC Gear Motors (x2) | Drive motors |
| Differential Drive Chassis | Robot base |
| Battery Supply | Motor power |
| USB Power | Logic power |

The Arduino reads the infrared sensor array and generates PWM motor commands which are sent to the TB6612 motor driver to control the left and right wheels.

---

# 4. System Design

The system consists of three primary subsystems.

## 4.1 Mechanical System

The robot uses a differential-drive configuration consisting of two powered wheels and a passive caster wheel.

Steering is achieved by varying the relative speed of the left and right motors.

The infrared sensor array is mounted at the front of the chassis to detect the line before it reaches the wheels.

---

## 4.2 Electrical System

The electrical system integrates sensing, control, and actuation components.

The Arduino reads analog signals from the sensor array and sends PWM and direction signals to the TB6612 motor driver.

The motor driver regulates power supplied to the DC motors.

Motor power and logic power are separated to improve electrical stability.

---

## 4.3 Control System

The robot uses a closed-loop control strategy.

Sensor readings are converted into a weighted position estimate which represents the location of the line relative to the robot.

A proportional-derivative (PD) controller generates steering corrections which adjust the left and right motor speeds.

Additional control features improve performance in difficult track sections:

• derivative filtering  
• dynamic speed adjustment during turns  
• hard-turn behaviour for tight corners  
• lost-line recovery mode

System diagrams are available in the **'diagrams'** folder.

---

# 5. Repository Structure

An overview of the files included in this repository:

• `/analysis` – Calibration, testing, and performance analysis  
• `/code` – Arduino control software  
• `/diagrams` – System and control architecture diagrams  
• `/docs` – Project documentation  
• `/electronics` – Wiring diagrams and pinout reference  
• `/media` – Demonstration images and videos  

---

# 6. Engineering Challenges

Several issues were encountered during development and resolved through testing and iteration:

• Incorrect sensor ordering initially caused incorrect steering behaviour  
• Drivetrain imbalance produced drift during straight-line motion  
• S-curve sections required improved controller responsiveness  
• Tight U-turns required additional hard-turn control logic  
• Line-loss behaviour required improved recovery logic

More information can be found in **`analysis/failure_analysis/debugging_log.md`**

---

# 7. Future Improvements

Possible future improvements include:

• Closed-loop motor speed control using wheel encoders  
• Adaptive controller gains based on speed or curvature  
• Improved sensor resolution for more accurate line detection  
• Automatic sensor calibration during system startup  

More information can be found in **`docs/future_improvements.md`**