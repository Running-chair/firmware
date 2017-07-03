int BTReset = 3;
int LED = 13;
int sp = 0;
char input = 0;         // incoming serial byte

void handle_command() {
  switch(input){
      case 'u':
        if (sp < 255) sp += 5;
        Serial.println(sp);
        break;
      case 'd':
        if (sp > 0) sp -= 5;
        Serial.println(sp);
        break;
      case 'g':
      Serial.println("go");
      digitalWrite(7,HIGH);
      analogWrite(9,sp);
      break;
      case 'b':
      Serial.println("back");
      digitalWrite(7,LOW);
      analogWrite(9,sp);
      break;
      case 's':
      Serial.println("stop");
      digitalWrite(7,LOW);
      analogWrite(9,0);
      break;
      }
}
 
void setup() {
  // make the Bluetooth Module reset:
  digitalWrite(BTReset, LOW);
  delay(100);
  digitalWrite(BTReset, HIGH);
  delay(500);
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);  // make a LED pin output
}
 
void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    input = Serial.read();
    handle_command();
    delay(100);
  }
  delay(1);        // delay in between reads for stability
}


