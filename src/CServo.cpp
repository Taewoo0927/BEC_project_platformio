#include "CServo.h"
#include <Servo.h>

// Constructor
CServo::CServo(int servoPin) {
    pin = servoPin;
    currentAngle = 0;  // Default to 0 degrees
}

// Attach the servo to the specified pin
void CServo::attach() {
    servo.attach(pin);
}

// Detach the servo
void CServo::detach() {
    servo.detach();
}

// Set the servo angle (constrained to 0-180)
void CServo::setAngle(int angle) {
    currentAngle = constrain(angle, 0, 180);
    servo.write(currentAngle);
}

// Get the current servo angle
int CServo::getAngle() {
    return currentAngle;
}

// Sweep between two angles with a delay
void CServo::sweep(int startAngle, int endAngle, int delayTime = 15) {
        startAngle = constrain(startAngle, 0, 180);
        endAngle = constrain(endAngle, 0, 180);

        if (startAngle < endAngle) {
            for (int angle = startAngle; angle <= endAngle; angle++) {
                servo.write(angle);
                delay(delayTime);
            }
        } else {
            for (int angle = startAngle; angle >= endAngle; angle--) {
                servo.write(angle);
                delay(delayTime);
            }
        }
    }