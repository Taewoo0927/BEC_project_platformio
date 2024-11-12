#ifndef CSENSOR_H
#define CSENSOR_H

#include <Arduino.h>

class CSensor {
  private:
    int _recvPin, _trigPin, _echoPin, _LedPin, _isObstaclePin, _isObstacle;

  public:
    // Constructor
    CSensor(int recvPin, int trigPin, int echoPin, int isObstaclePin,int ledPin );

    // Public methods
    int checkInfraredSensor();
    void initialize();
    float checkUltrasonicDistance();
    bool checkHutomwua();
};

#endif
