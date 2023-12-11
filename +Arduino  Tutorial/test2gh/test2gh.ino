#include <CustomSoftwareSerial.h>
 
void setup() {
  Serial.begin(9600);
  CustomSoftwareSerial* customSerial;

  customSerial = new CustomSoftwareSerial(10, 11); // rx, tx
  customSerial->begin(300, CSERIAL_7E1);
  
}

void loop() {

    customSerial->write('b');
    delay(2000);
   
}
