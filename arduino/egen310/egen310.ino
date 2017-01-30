#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
//Analog pins
int SALINITY_PIN = 6;
int PRESSURE_PIN = 7;

//Digital Pins
int RESET_PIN = 8;

//ETC
int SAFE_SALINITY = 50;
int PASSIVE_DELAY = 1000; //Update once per sec to save power
int ACTIVE_DELAY = 100; // Update screen & log 10 times per sec
int PRESSURE_THRESHOLD = 50;

void setup() {
  lcd.begin(16, 2);
  pinMode(RESET_PIN, OUTPUT);
  //Bluetooth Serial &/ or pc connection
  Serial.begin(9600);
}

void loop() {
  int salinity = analogRead(SALINITY_PIN);
  int pressure = analogRead(PRESSURE_PIN);

  //Detect if water is inserted
  if(pressure > PRESSURE_THRESHOLD)
    purify();
  
  delay(PASSIVE_DELAY);
}

void purify (){
  int salinity;
  for(int i = 0; i < 10*60*20; i++){ //Wait 20 minutes
    salinity = analogRead(SALINITY_PIN);
    int pressure = analogRead(PRESSURE_PIN);
    //Send salinity and pressure to be logged on PC
    Serial.write("S" + salinity);
    Serial.write("P" + pressure);
    lcd.print("Pressure" + pressure);
    delay(ACTIVE_DELAY);
  }
  calculateSafety (salinity);
}

//Do salinity calculation to see if safe
void calculateSafety (int salinity){
  if(salinity < SAFE_SALINITY) {
    Serial.write("Safe");
    lcd.print("Safe");
  } else {
    Serial.write("Not Safe");
    lcd.print("Not Safe");
  }
  
  digitalWrite(RESET_PIN, HIGH);
}

