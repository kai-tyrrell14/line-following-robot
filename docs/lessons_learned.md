# Lessons Learned
## 1. Sensor calibration is critical
In order to correctly follow the line the sensor arrays input must be correctly calibrated and weighted. Incorrect sensor ordering initially caused the robot to steer in the wrong direction, highlighting how small errors can significantly affect system behaviour.

## 2. Mechanical imperfections must be accounted for
Even when both motors receive identical commands, small differences in mechanical components can cause noticeable drift.
Testing revealed that these imbalances required software compensation through trim adjustments to achieve stable straight-line motion.

## 3. Controller tuning through iteration
In order to achieve the required performance several of the values in the code needed to be tuned. The final result required a number of iterations to find the best combination of values.

## 4. Special cases needed specific logic
The standard line following strategy accounted for most track geometries, however u-turns or turns with a tight radius were unsuccessful. In order to successfully complete these turns additional logic specific to these turns was required. Introducing a hard turn mode significantly improved the robot’s ability to navigate these curves.
