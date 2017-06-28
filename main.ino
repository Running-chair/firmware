int input;
int sp;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  sp = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  input = Serial.read();
  if (input != -1)
  {
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
}
