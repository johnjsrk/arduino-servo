#include <Servo.h> 
int speakerPin = 8;
int servoPin = 9;
Servo servo; 
//int angle = 0; // servo position in degrees 
#define LEFT_90   18
#define RIGHT_90  168
#define CENTER    90
#define LEFT_45   (CENTER + LEFT_90)/2
#define RIGHT_45  (CENTER + RIGHT_90)/2
#define TONE_SUS  3
#define TONE_PIT  4000
void set_speaker(int pitch, int msec)
{
  //tone(speakerPin, pitch);
  //delay(TONE_SUS);
  //noTone(speakerPin);
  delay(msec);
  tone(speakerPin, pitch);
  delay(TONE_SUS);
  noTone(speakerPin);
}
void set_servo(int angle, int msec)
{  
  servo.write(angle);
  //delay(40);
  set_speaker(TONE_PIT, 100);
  set_speaker(TONE_PIT, 400);
  //delay(400);
  servo.detach();
  delay(msec);
  servo.attach(servoPin);
  //servo.write(angle);
  //delay(1000);
}
void setup() 
{ 
  servo.attach(servoPin);
  servo.write(CENTER);
  delay(3000);
} 
void loop() 
{
  set_servo(LEFT_90, 3000);
  set_servo(CENTER, 3000);
  set_servo(RIGHT_90, 3000);
  set_servo(CENTER, 3000);
}
