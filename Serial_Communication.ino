#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11); //rx,tx

void setup() 
{
pinMode(A0,INPUT);
Serial.begin(9600);
mySerial.begin(9600);
}

void loop() 
{     mySerial.print("45");
      Serial.write(mySerial.read());
      delay(100);
  
}
