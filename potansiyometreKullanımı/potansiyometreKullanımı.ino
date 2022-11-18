const byte potPin = A0;
int potDeger;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  potDeger = analogRead(potPin);
  Serial.print("Potansiyometre okunan değer = ");
  Serial.println(potDeger);

  if(potDeger > 0 && potDeger < 300){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    }

    else if (potDeger > 300 && potDeger < 600){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    }

    else if (potDeger > 600 && potDeger < 1000){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    }

    else {
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
      }

      
}
