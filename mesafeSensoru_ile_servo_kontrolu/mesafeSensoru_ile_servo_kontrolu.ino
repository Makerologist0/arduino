#include <Servo.h>
#define trigPin 10
#define echoPin 8
long sure, mesafe;
Servo myservo;
void setup () {
  
Serial.begin(9600);
myservo.attach(9);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.println("Arduino İle Mesafe Sensörü Uygulaması Başlatılıyor...");
delay(3000);
}

void loop () {
digitalWrite(trigPin, LOW);
delayMicroseconds(3);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
mesafe = (sure/2) * 0.0343;
Serial.print(mesafe);
Serial.println(" cm uzaklıkta");

if (mesafe > 0 && mesafe <= 20){
  myservo.write(30);
  }
  
  else if(mesafe > 20 && mesafe <= 30){
  myservo.write(60);
  }
    
  else if(mesafe > 30 && mesafe <= 50){
  myservo.write(90);
  }
  else if(mesafe > 50 && mesafe <= 70){
  myservo.write(120);
    }
    else {
 myservo.write(180);
    }
  
delay(500);
}
