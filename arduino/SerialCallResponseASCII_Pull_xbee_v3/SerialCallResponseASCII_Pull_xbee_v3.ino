#include <SoftwareSerial.h>

SoftwareSerial xBeeSerial(2, 3); // RX, TX
int address;

void setup()
{
  Serial.begin(9600);
  xBeeSerial.begin(9600);
  address = 1;
//  establishContact();  // send a byte to establish contact until receiver responds 

}

void loop()
{
  address = 1;
  
  int Z = analogRead(A0);
  delay(10);
  int Y = analogRead(A1);
  delay(10);
  int X = analogRead(A2);
  delay(10);


  // listen for bytes from Max
  if (xBeeSerial.available() > 0 ) {
     //if Max sends us a byte, send them sensor readings
    int inByte = xBeeSerial.read();
    Serial.write(inByte);

//    xBeeSerial.print("Address: ");
//    xBeeSerial.print(address);
//    xBeeSerial.print(", X: ");
    xBeeSerial.print(X);
    xBeeSerial.print(",");
    xBeeSerial.print(Y);
    xBeeSerial.print(",");
    xBeeSerial.println(Z);
  }
}

//void establishContact() {
//  while (Serial.available() <= 0) {
//    Serial.println("0,0,0");   // send an initial string
//    delay(300);
//  }
//}


