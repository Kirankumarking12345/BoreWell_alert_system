#include <SoftwareSerial.h>

SoftwareSerial mySerial(6,7);

int trig1=9;
int echo1=10;
int trig2=12;
int echo2=11;
int buzzer=2;

long duration1,duration2,dist1,dist2;

void setup() 
{
  
  mySerial.begin(9600);
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
 
  
}
int c=0;
void loop() 
{  
  
  ultra1();
  ultra2();
  if((dist1<=30) || (dist2<=30))
  {
    tone(2,1000,100);
    //sent_sms();
    
  }
  delay(500);

}




   void ultra1()
  {
    digitalWrite(trig1,0);
    delayMicroseconds(2);
    digitalWrite(trig1,1);
    delayMicroseconds(10);
    digitalWrite(trig1,0);
    duration1=pulseIn(echo1,1);
    dist1=duration1/58;
    Serial.print("UV senosor 1 :");
    Serial.println(dist1);
    
  }
  void ultra2()
  {
    digitalWrite(trig2,0);
    delayMicroseconds(2);
    digitalWrite(trig2,1);
    delayMicroseconds(10);
    digitalWrite(trig2,0);
    duration2=pulseIn(echo2,1);
    dist2=duration2/58;
    Serial.print("UV senosor 2 :");
    Serial.println(dist2);
  
  }


 /* void sent_sms()
{
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918790058619\"\r");
     //7780741814
     delay(1000);
     mySerial.println("Alert!!! \n Kid is near Borewell");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);

}
  */
