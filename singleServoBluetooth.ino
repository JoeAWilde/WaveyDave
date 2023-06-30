#include <Servo.h>
Servo servo1;

int x;
int counter = 0;
char data = 0;


void setup() {
  // put your setup code here, to run once:
  servo1.attach(6);
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  data = 0;
  if(Serial.available() > 0)
  {
    data = Serial.read();
  }

  Serial.print(data);
  
  if(data == '1')
  {
    counter ++;
  }
  if(counter == 3)
  {
    counter = 0;
  }

  //Serial.print(counter);
  
  if(counter == 0)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
    

  if(counter == 1){
    digitalWrite(LED_BUILTIN, HIGH);
    for (int i = 180; i >= 10; i--){
      if(i>=90)
      {
        x = i;
        }
      else{
        x = 180-i;
      }
      servo1.write(x);
      delay(5);
    }
    delay(1200);
  }
  
  if(counter == 2){
    digitalWrite(LED_BUILTIN, HIGH);
    for (int i = 180; i >= 10; i--){
      if(i>=90)
      {
        x = i;
        }
      else{
        x = 180-i;
      }
      servo1.write(x);
      delay(5);
    }
    delay(200);
  }
}
