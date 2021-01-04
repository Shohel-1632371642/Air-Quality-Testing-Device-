#include <SoftwareSerial.h>
#define sensorPin A0
SoftwareSerial s(5,6);
const int led = 2;
int sensorValue;
int sensorValuePrev;
int difference;

void setup() {
 s.begin(115200);
 Serial.begin(115200);
 pinMode(led,OUTPUT);
 sensorValue = 0;
 sensorValuePrev = 0;
 difference = 0;
 delay(5000);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  difference = sensorValue-sensorValuePrev; 
  Serial.println(sensorValue);

  if(s.available()>0 && abs(difference)>2){
    
      sensorValuePrev = sensorValue;
      s.write(sensorValue);
      if(sensorValue>65){
          digitalWrite(2, HIGH);
      }
      else{
         digitalWrite(2, LOW); 
      }
  }
  
  
  delay(3000);
}
