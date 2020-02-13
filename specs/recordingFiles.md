Space Separated Values Recording Specification
==============================================

File ending: .rcd (ReCorD)
Because the input devices used to control the robot do not
give any single value that contains a space, "Space separated values"
will be used.

Now CSV could be more useful as a library could be incorporated and allow
better flexibility. There is no rule against using third-party libraries
in programming.

## XboxController recording
### First Line
The first line of the file will contain a long double containing the average
delta for the time between snapshots. During parsing, each line will be
called sequentially with the time interval provided by this line.
In the code, the long double will be truncated to a double.
### Subsequent Lines
The values for each column will be as follows(left to right):
*Booleans will be recorded as "1/0"*
*Preferably, there will be padding to ensure equal columns*


LeftJoystickAxisX[double] LeftJoystickAxisY[double]
RightJoystickAxisX[double] RightJoystickAxisY[double]

ButtonAState[bool] ButtonAPressed[bool] ButtonAReleased[bool]
ButtonBState[bool] ButtonBPressed[bool] ButtonBReleased[bool]
ButtonXState[bool] ButtonXPressed[bool] ButtonXReleased[bool]
ButtonYState[bool] ButtonYPressed[bool] ButtonYReleased[bool]

LeftTrigger[double] RightTrigger[double]

LeftBumperState[bool] LeftBumperPressed[bool] LeftBumperReleased[bool]
RightBumperState[bool] RightBumperPressed[bool] RightBumperReleased[bool]

LeftJoystickButtonState[bool] LeftJoystickButtonPressed[bool] LeftJoystickButtonReleased[bool]
RightJoystickButtonState[bool] RightJoystickButtonPressed[bool] RightJoystickButtonReleased[bool]

StartButtonState[bool] StartButtonPressed[bool] StartButtonReleased[bool]
BackButtonState[bool] BackButtonPressed[bool] BackButtonReleased[bool]

