Structure of design 

OOP PRINCIPLES FOLLOWED! 

CMotor – Controlls the movement DC motors. Forward, Backwards, Left, Right, Stop 

CServo – Servo controls. (FOLLOW CRAIGS SERVO CLASS) set position, get position, increment/speed control as well 

CControl – Gets contorller input from IR reciever (different than the CInfared sensor), sets output to variables associated with that function we want 

CUltasonic – Gets and reads US Sensor, does math to translate it into a distance, output’s distance 

CInfared – Gets and reads IR obstacel avoidance Sensor, does something 

 
# Naming Conventions -
**Variable Naming:** underscore_seperated 

Example: dc_motor_signal 

 

**Subroutine Naming:** lowerCamelCase 

Example: checkInfraredSignal 
