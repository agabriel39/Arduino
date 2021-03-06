//#include<VirtualWire.h>
#include<SoftwareSerial.h>
//#include<Narcoleptic.h>
#include <SoftEasyTransfer.h>
#define LED 0
//#define PTT 3
#define THERM A3



SoftwareSerial mySerial(5,2);
SoftEasyTransfer ET;

struct SEND_DATA_STRUCT
{
  int sample1;
  int sample2;
  int sample3;
  int sample4;
  int sample5;
};

SEND_DATA_STRUCT samples;  
  
  
void setup()
{
  //adcOff();
  //setup_watchdog();
  //pinMode(PTT, OUTPUT);
  pinMode(LED, OUTPUT);
 
  mySerial.begin(9600);
  ET.begin(details(samples), &mySerial);


}


void loop()
{
  //adcOn();
  sendSample();

  //adcOff();
  //Narcoleptic.delay(8000);
  delay(500);

}

void sendSample()
{
   
  int thermistorReading;
  
  samples.sample1 = analogRead(THERM);
  delay(10);
  samples.sample2 = analogRead(THERM);
  delay(10);
  samples.sample3 = analogRead(THERM);
  delay(10);
  samples.sample4 = analogRead(THERM);
  delay(10);
  samples.sample5 = analogRead(THERM);
  delay(10);
 
  ET.sendData();
  digitalWrite(LED, HIGH); // Flash a light to show transmitting
  //digitalWrite(PTT, HIGH); // turn on the transmitter

  //digitalWrite(PTT, LOW);  /// xmitter off 
  delay(500);
  digitalWrite(LED, LOW);  // LED off
}




