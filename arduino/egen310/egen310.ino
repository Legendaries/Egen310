//Analog pins
int SALINITY_PIN = 0;

//Digital Pins
int LED_PIN = 9;

//Salinity Calibration Values
//     123
//1%   463
//2%   573
//3.5% 610

//ETC
int SAFE_SALINITY = 150;
int DELAY = 1000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int salinity = analogRead(SALINITY_PIN);
  Serial.println(salinity);
  
  if(salinity < SAFE_SALINITY)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
  
  delay(DELAY);
}
