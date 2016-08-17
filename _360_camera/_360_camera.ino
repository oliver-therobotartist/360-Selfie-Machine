/*
 * This is a  project using the google street view app.  It is an experment to see if a simple stepper 
 * motor loop could be used to capture 360 images.
 * Stepper Motor is set to half-step
 */

#define STEP 9//pins to the dvr8825
#define DIR 8
#define ENABLE 12

#define button 7//push button pin

int val = 1;//for recording the pin value

void setup(){
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  pinMode(button, INPUT);
  
  digitalWrite(DIR, HIGH);//moves clockwise
  digitalWrite(ENABLE, LOW);
  
  while(val)//keep in while loop until the first picture is taken, then press button
  {
    val = !digitalRead(button);//pull-up resistor used
  }
  delay(500);//this gives the user and google street view the time needed to catch up
}

void loop(){
  //this loop takes one photo and will need to repeat 13 times
  for(int spin = 0; spin < 29; spin++)//there are 13 photos taken 400 steps per rev / 13 phots = ~30 steps.  29 steps works better. 
  {
    digitalWrite(STEP, HIGH);
    delay(3);
    digitalWrite(STEP, LOW);
    delay(3);//this total delay time works at limiting the amount of vibration. 
  }
  
  delay(1500);//time needed for app to take photo
}

