#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;


#define ILERI 0x10058
#define ILERI1 0x58
#define SAG 0x1005B
#define SAG1 0x5B
#define SOL 0x1005A
#define SOL1 0x5A
#define GERI 0x10059
#define GERI1 0x59
#define ON 0x10
#define ON1 0x10010
#define OFF 0x11
#define OFF1 0x10011


int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == ILERI || results.value == ILERI1 )
    {
      digitalWrite(led1, !digitalRead(led1));
      if (digitalRead(led1) == HIGH)
      {
        Serial.println("LED 1 yandi");
      }
      else 
      {
        Serial.println("LED 1 sondu");
      }
    }
    if (results.value == SAG || results.value == SAG1 )
    {
      digitalWrite(led2, !digitalRead(led2));
      if (digitalRead(led2) == HIGH)
      {
        Serial.println("LED 2 yandi");
      }
      else
      {
        Serial.println("LED 2 sondu");
      }
    }
    if (results.value == SOL || results.value == SOL1)
    {
      digitalWrite(led3, !digitalRead(led3));
      if (digitalRead(led3) == HIGH)
      {
        Serial.println("LED 3 yandi");
      }
      else
      {
        Serial.println("LED 3 sondu");
      }
    }
    if (results.value == GERI || results.value == GERI1)
    {
      digitalWrite(led4, !digitalRead(led4));
      if (digitalRead(led4) == HIGH)
      {
        Serial.println("LED 4 yandi");
      }
      else
      {
        Serial.println("LED 4 sondu");
      }
    }
    if (results.value == ON || results.value == ON1)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      Serial.println("Tum LED'ler sondu");
    }
    if (results.value == OFF || results.value == OFF1)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      Serial.println("Tum LED'ler yandi");
    }
    delay(500);
    irrecv.resume();
  }
}
