int LED_PIN = 6;

void setup (){
 pinMode(LED_PIN, OUTPUT); 
}

void loop (){
 for(int i = 0; i < 5; i++){
  digitalWrite(LED_PIN, LOW); 
   delay(400);
   digitalWrite(LED_PIN, HIGH);
   delay(400);
 }
}
