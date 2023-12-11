#include <stdio.h>
/*
int main() {
    //printf("Hello, World!\n");



    return 0;
}
*/

#include <String.h>
CustomSoftwareSerial* customSerial;
int input = ' '; // Declare serial
String bin = "";
// Init value
void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);    // sets the digital pin 13 as output

    /*
    while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
    Serial.write("Hello World");
  */
    customSerial = new CustomSoftwareSerial(10, 11); // rx, tx
    customSerial->begin(300, CSERIAL_8N1);         // Baud rate: 9600, configuration: CSERIAL_8N1
    //customSerial->write("Test message");            // Write testing data
}

void loop() {
    // digitalWrite(7, LOW); // sets the digital pin 13 on

    //customSerial->write("/?!\r\n");
    // digitalWrite(7, HIGH); // sets the digital pin 13 on

    if (customSerial->available())
    {
        input = customSerial->read();
        if (input == 10)
        {
            Serial.println("");
        }else
        {
            bin = binary(input);
            Serial.print(bin + ','+ ' ');
        }
        delay(100);
        /*if (customSerial->peek() == '\n')
        {
          input = customSerial->read();
          //Serial.print(input, BIN);
          Serial.println("");
        }else
        {
          input = customSerial->read();
          Serial.print(input, BIN);
          Serial.print(", ");
        }

       // Serial.write(customSerial->read());
      }
      */
        // if (Serial.available())


        // delay(5000);
    }
}

String binary(char c)
{

    String ret = "";
    String bin_val= "";
    while(c!=0)
    {
        ret += c%2;
        c=c/2;
    }

    int index  = ret.length();
    //Serial.println(ret + ','+' ');
    while(index != 0)
    {
        index--;
        bin_val += ret[index];
    }
    //Serial.println(bin_val + ';');
    return bin_val ;
}
