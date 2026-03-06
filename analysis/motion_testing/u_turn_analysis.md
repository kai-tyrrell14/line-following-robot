# U-Turn Analysis
## 1. Purpose
The u-turn section was crucial in testing as it tested the robot's ability to perform turns with a tight radius.

## 2. Observed Behaviour
Testing initially showed that the robot often understeered on these u-turns and lost the line. Through further changes and testing the
robot either oversteered or struggled to follow the straight line after completing the turn.

## 3. Solution
The following solutions were implemented to improve performance:
- Reduced base speed during hard turns.
- Applied breaking to the inside wheel.
- Implemented hard turn cooldown to improve tracking out of corner.

## 4. Outcome
The robot able to much more accurately perform u-turns, however extremely tight turns were still unsuccessful.
