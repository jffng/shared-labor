import oscP5.*;
import netP5.*;
import processing.serial.*;     // import the Processing serial library
Serial myPort;// The serial port

// OSC object + location of local computer
OscP5 oscP5;
NetAddress myRemoteLocation;
OscMessage X, Z;

void setup() {
  oscP5 = new OscP5(this, 8000);
  myRemoteLocation = new NetAddress("127.0.0.1", 8000); 
  println(Serial.list()); 
  
  String portName = Serial.list()[6];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {

  //  X = new OscMessage( "/x" );
  //  
  //  Z = new OscMessage( "/z" );
  //  
  //  Z.clearArguments();
  //  Z.add( );
  //  oscP5.send(X, myRemoteLocation);
  //  oscP5.send(Z, myRemoteLocation);
}

void serialEvent(Serial myPort) {
  float x, y, z, _x, _y, _z;
  float val = .1;
  float spike = .1;
  int sensors[] = new int[2];
  int old[] = new int[2];
  int counter = 1;
  // read the serial buffer:
  _z = 0;
  
  String myString = myPort.readStringUntil('\n');
  if (myString != null) {
    myString = trim(myString);

    // split the string at the commas
    // and convert the sections into integers:
    sensors = int(split(myString, ','));

//    if (sensors.length > 1) {
      //      print("X: " + map(sensors[0], 290, 550, 0, 1) + "\t");
      //      print("Y: " + map(sensors[1], 290, 550, 0, 1) + "\t");
      //      print("Z: " + map(sensors[2], 290, 550, 0, 1) + "\t");
      x = map(sensors[0], 280, 400, 0, 1);
      y = map(sensors[1], 200, 280, 0, 1);
      z = map(sensors[2], 290, 550, 0, 1);
//    }
    //    println();

    if ( abs(_z - z) > .25) {
      val += spike;
    }
    if (val > 0) {
      val -= .001;
    }
    else {
      val = 0;
    }
    _z = z;
  }
}

