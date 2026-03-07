# Lessons Learned

## 1. Sensor Interpretation is Critical

Reliable line-following behaviour depends heavily on correct interpretation of sensor data. Incorrect sensor ordering initially caused the robot to steer in the wrong direction, demonstrating how small configuration errors can significantly affect system behaviour.

Verifying sensor layout and calibration early in development proved essential for stable control.

---

## 2. Mechanical Imperfections Affect Control

Even when both motors receive identical commands, small differences in drivetrain components can cause noticeable drift.

Testing revealed that drivetrain imbalance required software compensation through trim adjustments and deadband handling to achieve stable straight-line motion.

---

## 3. Controller Tuning Requires Iteration

Achieving stable behaviour required multiple cycles of testing and tuning. Controller gains that worked well on straight sections did not always perform well in curves or tight turns.

Iterative testing across different track geometries was necessary to balance responsiveness and stability.

---

## 4. Special Cases Need Dedicated Logic

Standard PD control alone was not sufficient for all track conditions. Tight U-turns required additional logic to increase turning authority.

Introducing a hard-turn mode significantly improved the robot’s ability to navigate extreme curvature.

---

## 5. Structured Debugging Improves Development

Using small diagnostic programs to test individual subsystems—such as sensor ordering and motor drift—made it easier to isolate problems.

Breaking the system into smaller components allowed issues to be identified and resolved more efficiently.
