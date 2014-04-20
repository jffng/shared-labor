#include <SoftwareSerial.h>

SoftwareSerial xBeeSerial(2, 3); // RX, TX
int address;



void setup()
{
  Serial.begin(9600);
  xBeeSerial.begin(9600);
  address = 1;
  pinMode(8, INPUT);
}

void loop()
{
  address = 1;
  
  int firstSensor = analogRead(A0);
  delay(10);
  int secondSensor = analogRead(A1);
  delay(10);
  int thirdSensor = analogRead(A2);
  delay(10);
  int fourthSensor = analogRead(A3);
  delay(10);
  int fifthSensor = analogRead(A4);
  delay(10);
  int digiSensor = digitalRead(8);
  


  // listen for bytes from Max
  if (xBeeSerial.available() > 0 ) {
     //if Max sends us a byte, send them sensor readings
    int inByte = xBeeSerial.read();
    Serial.write(inByte);

    xBeeSerial.print(address);
    xBeeSerial.print(",");
    xBeeSerial.print(firstSensor);
    xBeeSerial.print(",");
    xBeeSerial.print(secondSensor);
    xBeeSerial.print(",");
    xBeeSerial.print(thirdSensor);
    xBeeSerial.print(",");
    xBeeSerial.print(fourthSensor);
    xBeeSerial.print(",");
    xBeeSerial.print(fifthSensor);
    xBeeSerial.print(",");
    xBeeSerial.println(digiSensor);

  }
}



