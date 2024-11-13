#include "CMotor.h"
#include "CServo.h"
#include "CSensor.h"

// Motor
CMotor _motor(2, 3, 4, 5, A0, A1);

// Servo
CServo _servo_1(6);
CServo _servo_2(7);

// Infrared Sensor
int const maxObjDetectDist = 30; // cm
int const minObjDetectDist = 15; // cm
bool isObjectDetected = false;
CSensor sensor(11, 9, 10, 2, 13);

void setup()
{
  Serial.begin(9600);
  _motor.setSpeed(150); // Set initial speed
  sensor.initialize();
  _servo_1.attach();
  _servo_2.attach();
  _servo_1.setAngle(0);
  _servo_2.setAngle(0);
}

void loop()
{

  // SENSOR CODE =====================================================================================================================
  sensor.checkInfraredSensor();

  int distance = 0; // sensor.checkUltrasonicDistance();
  int hexCode = sensor.checkInfraredSensor();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Hex Code: 0x");
  Serial.println(hexCode, HEX);

  delay(150);

  // MOTOR CODE =====================================================================================================================
  if (hexCode == 0x19)
  {
    _motor.forward();
  }
  else if (hexCode == 0xC) // Left
  {
    _motor.left();
  }
  else if (hexCode == 0x5E) // right
  {
    _motor.right();
  }
  else if (hexCode == 0x1C) // back
  {
    _motor.backward();
  }
  else
  {
    _motor.stop();
  }
}
