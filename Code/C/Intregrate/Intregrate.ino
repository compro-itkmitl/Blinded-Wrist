#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
const int pingPin = 7;
int inPin = 6;


void setup () {
 
  Serial.begin(9600);
  while (!Serial) ;
  mySerial.begin(9600);
}



void loop() {
  long duration, cm;

pinMode(pingPin, OUTPUT);


digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
pinMode(inPin, INPUT);
duration = pulseIn(inPin, HIGH);

cm = microsecondsToCentimeters(duration);
if(cm > 400){
  cm = 0;
}
if(cm <= 0){
  cm = 0;
}
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
