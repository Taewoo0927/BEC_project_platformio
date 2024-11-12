#include "CMotor.h"

// Constructor
CMotor::CMotor(int m1p1, int m1p2, int m2p1, int m2p2, int en1, int en2) {
    _motor1Pin1 = m1p1;
    _motor1Pin2 = m1p2;
    _motor2Pin1 = m2p1;
    _motor2Pin2 = m2p2;
    _enablePin1 = en1;
    _enablePin2 = en2;

    pinMode(_motor1Pin1, OUTPUT);
    pinMode(_motor1Pin2, OUTPUT);
    pinMode(_motor2Pin1, OUTPUT);
    pinMode(_motor2Pin2, OUTPUT);
    pinMode(_enablePin1, OUTPUT);
    pinMode(_enablePin2, OUTPUT);
}

// Set motor speed
void CMotor::setSpeed(int speed) {
    speed = constrain(speed, 0, 255);
    analogWrite(_enablePin1, speed);
    analogWrite(_enablePin2, speed);
}

// Move forward
void CMotor::forward() {
    digitalWrite(_motor1Pin1, HIGH);
    digitalWrite(_motor1Pin2, LOW);
    digitalWrite(_motor2Pin1, HIGH);
    digitalWrite(_motor2Pin2, LOW);
}

// Move backward
void CMotor::backward() {
    digitalWrite(_motor1Pin1, LOW);
    digitalWrite(_motor1Pin2, HIGH);
    digitalWrite(_motor2Pin1, LOW);
    digitalWrite(_motor2Pin2, HIGH);
}

// Turn left
void CMotor::left() {
    digitalWrite(_motor1Pin1, LOW);
    digitalWrite(_motor1Pin2, HIGH);
    digitalWrite(_motor2Pin1, HIGH);
    digitalWrite(_motor2Pin2, LOW);
}

// Turn right
void CMotor::right() {
    digitalWrite(_motor1Pin1, HIGH);
    digitalWrite(_motor1Pin2, LOW);
    digitalWrite(_motor2Pin1, LOW);
    digitalWrite(_motor2Pin2, HIGH);
}

// Stop the motors
void CMotor::stop() {
    digitalWrite(_motor1Pin1, LOW);
    digitalWrite(_motor1Pin2, LOW);
    digitalWrite(_motor2Pin1, LOW);
    digitalWrite(_motor2Pin2, LOW);
}
