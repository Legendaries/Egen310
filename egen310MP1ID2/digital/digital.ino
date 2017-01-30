//1. Reads the input state (HIGH,LOW) of the given pin
//2. Makes a decision based on inputted logic
//3. 

int LED_PIN = 6;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a 1 to turn on the LED or 0 to turn off.");
}

void loop() {
  if(Serial.available()) {
    if(Serial.read() == 'A') {
      digitalWrite(LED_PIN, HIGH);
      delay(10000);
      digitalWrite(LED_PIN, LOW);
    }
  }
}
