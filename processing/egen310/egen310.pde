import processing.serial.*;

Serial myPort;  // Create object from Serial class
int pressure, salinity;      // Data received from the serial port
String safety = "Not Safe";

void setup() {
  size(300, 300, P2D);
  String portName = Serial.list()[0];
  //myPort = new Serial(this, portName, 9600);
  textSize(32);
  background(0,0,0);
  smooth(8);
}

void draw() {
  //if ( myPort.available() > 0){   // If data is available,
  //  String temp = myPort.readString();         // read it and store it in val
  //  if(temp.charAt(0) == 'P') pressure = Integer.parseInt(temp.split("P")[1]);
  //  else if(temp.charAt(0) == 'S') salinity = Integer.parseInt(temp.split("S")[1]);
  //  else if(temp.equals("Safe")) {
  //    safety = "Safe";      
  //  } else if(temp.equals("Not Safe")){
  //    safety = "Not Safe";      
  //  }
  //}
  if(safety.equals("Safe"))
    fill(0,255,0);
  else
    fill(255,0,0);
  text(safety, (width-textWidth(safety))/2, height/3);  
    fill(255,255,255);
  text("Pressure " + pressure, (width-textWidth("Pressure " + pressure))/2, height/2);
  text("Salinity " + salinity, (width-textWidth("Salinity " + salinity))/2, 2*height/3);
}