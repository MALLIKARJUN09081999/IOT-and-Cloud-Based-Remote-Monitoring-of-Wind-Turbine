
#include <DHT.h>
#define DHTPIN 5 //5=DHT11 output
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
const int analogPin = A0; // A0=Current sensor output
#define DHTPIN 5  //A5=DHT11 output
const int voltagepin = A3; //A3 for voltage
//A2 for rpm
String data="";

//Voltage Measurement
int value = 0;
float voltage;
float R1 = 1000000.0;
float R2 = 10000.0;


//RPM measurement
int encoder = 2;
volatile unsigned int counter;
int rpm;




//Current measurement
int sensitivity= 66;
int adcvalue = 0;  // variable to store the sensor value read
int offsetvoltage=5000;
double voltage1 = 0;
double current = 0;

void setup() {
  Serial.begin(9600);
    
  pinMode(encoder, INPUT);
 
  digitalWrite(encoder, HIGH);
  Serial.begin(9600);
  dht.begin();
  attachInterrupt(0,countpulse,RISING);
  delay(2000);
}
void countpulse(){
        counter++;
}
 

void loop() {
  
  
  adcvalue=analogRead(analogPin);
  voltage1=(adcvalue/1024.0)*5000;
  current=((voltage1-offsetvoltage)/sensitivity);
 // current=-(current);
  
  
  float t=dht.readTemperature();
  float h=dht.readHumidity();
  
  data="";

  value = analogRead(voltagepin);
  voltage = value * (5.0/1024)*((R1 + R2)/R2);
  voltage=(voltage-2.99);

  static uint32_t previousMillis;
  if (millis() - previousMillis >= 1000) {
           rpm = (counter);          
           counter = 0;
           previousMillis += 1000;
  }
  
  float power=voltage*current;
  
  data=data+t+", ";
  data=data+h+", ";
  data=data+current+", ";
  data=data+voltage+", ";
  data=data+rpm+", ";
  data=data+power+", ";

  Serial.println(data);
  delay(2500);
}


 


 
