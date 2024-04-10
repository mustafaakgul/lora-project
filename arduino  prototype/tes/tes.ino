#include <CustomSoftwareSerial.h>

CustomSoftwareSerial* customSerial;               // Declare serial

// Init value
void setup() {
  Serial.begin(9600);
    //pinMode(7, OUTPUT);    // sets the digital pin 13 as output

  customSerial = new CustomSoftwareSerial(10, 11); // rx, tx
  customSerial->begin(300, CSERIAL_7E1);         // Baud rate: 9600, configuration: CSERIAL_8N1
  //customSerial->begin(300, CSERIAL_8N1);  
  //customSerial->write("Test message");            // Write testing data
/*
  digitalWrite(7, HIGH);
  customSerial->write("/?!\r\n");
  digitalWrite(7, LOW);
  if (customSerial->available()){
    Serial.write(customSerial->read());
    }*/
  
}

void loop() {

  if (Serial.available()){
        customSerial->write(Serial.read());
        }
/*
if (customSerial->available()){
    Serial.write(customSerial->read());
    }*/
        
    //customSerial->write('b');
    //delay(2000);
  /*
  if (customSerial->available()){
    Serial.write(customSerial->read());
    }
      if (customSerial->available()){
        Serial.write(customSerial->read());
        }*/
      /*if (Serial.available()){
        customSerial->write(Serial.read());
        }

        if (customSerial->available()){
         Serial.write(customSerial->read());}*/
     //////customSerial->write("/?!\r\n");
       // if (customSerial->available()){
       //  Serial.write(customSerial->read());}
}
