#include <BoltDeviceCredentials.h>
#include <BoltIoT-Arduino-Helper.h>
const int trigpin=9;
const int echopin=10;
const int buzzer=11;
const int ledpin=13;
long duration;
int distance;
int safetydistance;

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=duration*0.034/2;
  safetydistance=distance;
  if(safetydistance<=5){
    digitalWrite(buzzer,HIGH);
    digitalWrite(ledpin,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
    digitalWrite(ledpin,LOW);
  }
  Serial.print("Distance:");
  Serial.println("distance");

}