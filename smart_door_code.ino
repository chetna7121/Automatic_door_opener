#include <Servo.h>
Servo myservo;

int pir=7;
int pir_state=LOW;
int pos=0;

void setup()
{
  pinMode(pir,INPUT);
  myservo.attach(8);
  Serial.begin(9600);

}

void loop()
{
  int pir_value=digitalRead(pir);
  if(pir_value==HIGH)
  {
    myservo.write(180);
    delay(3000);
    if(pir_state==LOW)
    {
      Serial.println("Motion Detected");
      pir_state=HIGH;
    }  
  }
  else
  {
     myservo.write(0);
     if(pir_state==HIGH)
     {
       Serial.println("Motion Stopped");
       pir_state=LOW;
     }
  }
}
