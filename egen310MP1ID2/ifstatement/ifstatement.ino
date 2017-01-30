int LED_PIN = 6;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a 1 to turn on the LED or 0 to turn off.");
}

void loop() {
  if(Serial.available())
    if(Serial.read() == '0') digitalWrite(LED_PIN, LOW);
    else if(Serial.read() == '1') digitalWrite(LED_PIN, HIGH);
}
