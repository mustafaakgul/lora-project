
#include <SoftwareSerialParity.h>
SoftwareSerialParity mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600,ODD);
  //mySerial.begin(9600,EVEN);
  //mySerial.begin(9600,NONE);
  Serial.begin(9600);
  Serial.write("hello");
   
}

void loop() {
  // put your main code here, to run repeatedly:
  //mySerial.println("Hello Worlds");
  //delay(1000);
  if (mySerial.available())
    Serial.write(mySerial.read());
}
