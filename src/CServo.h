#ifndef CServo_h
#define CServo_h

#include <Arduino.h>
#include <Servo.h>

class CServo {
private:
    Servo servo;         // Servo object
    int pin;             // Pin to which the servo is connected
    int currentAngle;    // Current angle of the servo

public:
    // Constructor
    CServo(int servoPin);

    // Attach the servo
    void attach();

    // Detach the servo
    void detach();

    // Set the servo angle
    void setAngle(int angle);

    // Get the current servo angle
    int getAngle();

    // Sweep between two angles
    void sweep(int startAngle, int endAngle, int delayTime = 15);
};

#endif