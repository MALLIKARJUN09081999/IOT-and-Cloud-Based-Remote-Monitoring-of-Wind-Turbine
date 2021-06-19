

const int LED=13;
int LDR=A5;
int LM35=A0;
int readValue1;
int readValue2;

void setup() 
{
  // put your setup code here, to run once:
      Serial.begin(9600);
      pinMode(LM35,INPUT);
      pinMode(LED,OUTPUT);
      pinMode(LDR,INPUT);

}

void loop() 
{
  // put your main code here, to run repeatedly:
      readValue1=analogRead(LDR);
      Serial.println("LDR value=");
      Serial.println(readValue1);
      delay(1000);
      readValue2=analogRead(LM35);
      readValue2=readValue2*(100.0/205.0);
      Serial.println("temperature=");
      Serial.println(readValue2);
      delay(1000);
      
}
