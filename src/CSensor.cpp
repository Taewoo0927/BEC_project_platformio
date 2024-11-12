#include "CSensor.h"
#include <IRremote.h>

// Constructor
CSensor::CSensor(int recvPin, int trigPin, int echoPin, int isObstaclePin,int ledPin) {
    _recvPin = recvPin;
    _trigPin = trigPin;
    _echoPin = echoPin;
    _LedPin = ledPin;
    _isObstaclePin = isObstaclePin;
    _isObstacle = HIGH;
}

// Initialize the sensor pins and IR receiver
void CSensor::initialize() {  
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    pinMode(_LedPin, OUTPUT);
    pinMode(_isObstaclePin, INPUT);

    // _isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

    IrReceiver.begin(11);    // Start the IR receiver on the specified pin
    Serial.println("IR Receiver Ready");
}

// Check infrared sensor and return the decoded IR command
int CSensor::checkInfraredSensor() {
    if (IrReceiver.decode()) {  // Check if a signal is received
        if (IrReceiver.decodedIRData.decodedRawData != 0xFFFFFFFF) {  // Ignore repeat codes
            Serial.print("Hex Code: 0x");
            Serial.println(IrReceiver.decodedIRData.command, HEX);  // Print the hex code
            int command = IrReceiver.decodedIRData.command;  // Save the decoded command
            IrReceiver.resume();  // Prepare for the next signal
            return command;  // Return the decoded command

        }
        IrReceiver.resume();  // Prepare for the next signal
    }
    return 0;  // Return 0 if no signal is received
}
float CSensor::checkUltrasonicDistance(){
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    // Measure the duration of the pulse on ECHO
    long duration = pulseIn(_echoPin, HIGH);
    float distance = duration * 0.0343 / 2;


    return  distance;
    // Calculate the distance (cm)
}

bool CSensor::checkHutomwua() {
    _isObstacle = digitalRead(_isObstaclePin);
    // Serial.println("isObstacle: %d", _isObstacle);

    // Serial.print("isObstacle: ");
    // Serial.println(_isObstacle == HIGH ? "No Obstacle" : "Obstacle Detected");


    if (_isObstacle == LOW)
    {
      // Serial.println("OBSTACLE!!, OBSTACLE!!");
      digitalWrite(_LedPin, HIGH);
      return 1;
    }
    else
    {
      // Serial.println("clear");
      digitalWrite(_LedPin, LOW);
      return 0 ;
    }
}
