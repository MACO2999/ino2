#include <Servo.h> 
  
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
 
int pin0 = A0;
int pin1 = A1;
int pin2 = A2;
int pin3 = A3;
int angle1;
int angle2;
int angle3;
int angle4;
int value1;
int value2;
int value3;
int value4;
long int forservo1 = 20000;
long int forservo2 = 40000;
long int forservo3 = 20000;
long int forservo4 = 1;

void setup() 
{ 
  pinMode(13, OUTPUT);
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
} 
 
void loop() 
{ 
  /* read analog values from joysticks */
  value1 = analogRead(pin0);
  value2 = analogRead(pin1);
  value3 = analogRead(pin2);
  value4 = analogRead(pin3);
  
  /* 10 bit value is too big, so we change the scale from 0 - 1023 proportionately to 1 - 29 */
  value1 = map(value1, 0, 1023, 1, 29);
  value2 = map(value2, 0, 1023, 1, 29);
  value3 = map(value3, 0, 1023, 1, 29);
  value4 = map(value4, 0, 1023, 1, 29);
  
  /* it needs corection of positions, because joysticks are not very precise to stay exactly in the center  */
  if(value1  <= 17 && value1 >= 13)
      value1 = 15;
  if(value2  <= 17 && value2 >= 13)
      value2 = 15;
  if(value3  <= 17 && value3 >= 13)
      value3 = 15;
  if(value4  <= 17 && value4 >= 13)
      value4 = 15;
    
  /* Change initial value 'forservo' which is used to turn servo slower. This value has got very big scale.
  We add or substract (depends on turning direction) difference between analog value and center from 'forservo'  */
  forservo1 = forservo1 - (value1 - 15);
  forservo2 = forservo2 - (value2 - 15);
  forservo3 = forservo3 + (value3 - 15);
  forservo4 = forservo4 + (value4 - 15);
  
  /* this part do not let variables 'forservo' go out of the limits */
  if(forservo1  < 1)
      forservo1 = 1;
  if(forservo1  > 40000)
      forservo1 = 40000;
  if(forservo2  < 1)
      forservo2 = 1;
  if(forservo2  > 40000)
      forservo2 = 40000;
  if(forservo3  < 1)
      forservo3 = 1;
  if(forservo3  > 40000)
      forservo3 = 40000;
  if(forservo4  < 1)
      forservo4 = 1;
  if(forservo4  > 40000)
      forservo4 = 40000;
  
  /* change used value to angle of servo. Angles are adjusted during testing */
  angle1 = map(forservo1, 1, 40000, 33, 145);
  angle2 = map(forservo2, 1, 40000, 60, 155);
  angle3 = map(forservo3, 1, 40000, 40, 180);
  angle4 = map(forservo4, 1, 40000, 75, 155);
  
  /* send angles to servos */
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);

} 
