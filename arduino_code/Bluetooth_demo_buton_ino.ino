
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);
const int led1 = 9;
const int led2 = 8;
const int buton1 = 6;
const int buton2 = 7;
int gelen;      

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
}

void loop() {
  if (mySerial.available() > 0) {
    gelen = mySerial.read();
    if (gelen == 'A') {
      digitalWrite(led1, HIGH);
      mySerial.println("Led1 yandi");
    }

    if (gelen == 'D') {
      digitalWrite(led2, HIGH);
      mySerial.println("Led2 yandi");
    }

    if (gelen == 'S') {
      digitalWrite(led1, LOW);
      mySerial.println("Led1 sondu");
    }
    if (gelen == 'F') {
      digitalWrite(led2, LOW);
      mySerial.println("Led2 sondu");
    }
  }
  if(digitalRead(buton1)==LOW){
    mySerial.println("Buton1'e basildi");  
    delay(1000);
  }
  if(digitalRead(buton2)==LOW){
    mySerial.println("Buton2'ye basildi");  
    delay(1000);
  }
}







