#ifndef CMOTOR_H
#define CMOTOR_H

#include <Arduino.h>

class CMotor {
private:
    int _motor1Pin1, _motor1Pin2;
    int _motor2Pin1, _motor2Pin2;
    int _enablePin1, _enablePin2;

public:
    // Constructor
    CMotor(int m1p1, int m1p2, int m2p1, int m2p2, int en1, int en2);

    // Public methods
    void setSpeed(int speed);
    void forward();
    void backward();
    void left();
    void right();
    void stop();
};

#endif