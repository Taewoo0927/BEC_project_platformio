#include "CMotor.h"
#include "CServo.h"
#include "CSensor.h"

// Motor
CMotor _motor(2, 3, 4, 5, A0, A1);

// Servo
CServo _servo_1(6);
CServo _servo_2(7);

// Infrared Sensor
int const maxObjDetectDist = 30;//cm
int const minObjDetectDist = 15;//cm
bool isObjectDetected = false;
CSensor sensor(11, 9, 10,2,13);



void setup() {
  Serial.begin(9600);
  _motor.setSpeed(150);  // Set initial speed
  sensor.initialize();
  _servo_1.attach();
  _servo_2.attach();
      _servo_1.setAngle(0);
    _servo_2.setAngle(0);
}


void loop() {

    // if (Serial.available() > 0) {
    //     char input = Serial.read();  // Read a single character
    //     //int input_num = input.toInt();
    //     //Serial.print("You entered: ");
    //     //Serial.println(input);

    //     if (input == 'w' || input == 'W') {
    //         _motor.forward();
    //     } else if (input == 's' || input == 'S') {
    //         _motor.backward();
    //     } else if (input == 'a' || input == 'A') {
    //         _motor.left();
    //     } else if (input == 'd' || input == 'D') {
    //         _motor.right();
    //         }
    //     else {
    //         _motor.stop();
    //     }

    // }


  // SENSOR CODE =====================================================================================================================
    // sensor.checkInfraredSensor();

    int distance = 0;//sensor.checkUltrasonicDistance();
    int hexCode = sensor.checkInfraredSensor();
     
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm, Hex Code: 0x");
    Serial.println(hexCode, HEX);

    // if((distance  > minObjDetectDist) && (distance < maxObjDetectDist) && isObjectDetected == false){
    //   isObjectDetected = true;
    //   Serial.println("detected!!@@@@@@@@@@@@@@@@@@@");
    //   //if true, enter into interrupt.
    //   _motor.stop(); //temp stop
    //   //delay(5000);
    // }
  delay(150);


  // MOTOR CODE =====================================================================================================================
  if (hexCode == 0x19){
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
   else if (hexCode == 0X47)
   {
    //_servo_1.sweep(0, 250);
    _servo_1.setAngle(0);
   // _servo_2.setAngle(0);
    delay(1000);
    _servo_1.setAngle(20);
   delay(1000);

    delay(1000);
    _servo_2.setAngle(150);
    delay(1000);
   }
   else if(hexCode == 0x15)
   {
    _servo_1.setAngle(0);
    _servo_2.setAngle(0);
    delay(1000);
   }
  else
  {
    _motor.stop();
  }

  // SERVO CODE =====================================================================================================================

  // _servo.sweep(0, 250);
  // delay(500);
  // _servo.setAngle(0);

  //int hi = _servo.getAngle();
  //Serial.println(hi);



  // OPEN 0x15 (-)
  // CLOSE 0x7 (+)
  // UP  0x44 (VOL -)
  // DOWN 0x40 (VOL +)




}
