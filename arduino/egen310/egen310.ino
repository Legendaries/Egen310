//Analog pins
int SALINITY_PIN = 6;
int PRESSURE_PIN = 7;

//Digital Pins
int RESET_PIN = 8;
int LED_PIN = 9;
//     123
//1%   463
//2%   573
//3.5% 610
//ETC
int SAFE_SALINITY = 50;
int DELAY = 1000;
int PRESSURE_THRESHOLD = 50;

void setup() {
  pinMode(RESET_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int salinity = analogRead(SALINITY_PIN);
  int pressure = analogRead(PRESSURE_PIN);
  //Send salinity and pressure to be logged on PC
  Serial.write("S" + salinity);
  Serial.write("P" + pressure);
  
  if(salinity < 20)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
  
  delay(DELAY);
}
