//Sending values on the ThingSpeak
#include "ThingSpeak.h"  //Include ThingSpeak library
#include "YunClient.h"
YunClient client;     //creating an object of Yun to communicate with thingspeak

unsigned long myChannelNumber = 210849;           //My channel ID
const char * myWriteAPIKey = "49I73T91FC0WX3DU";  //My API write key
byte value=15;   //I thing it must be of byte type to make the loop execute. Coz This is runnnig quite well now
//sometimes it doesnot send the data at that time I should burn the program again or else change the usb port

void setup()
{
  Bridge.begin();           //Establishing the bridge for the communication
  ThingSpeak.begin(client);  //Initializing the object 
  Serial.begin(9600);      //Setting my baudrate
  delay(1000);
  Serial.println("Arduino Yun is ready to send data on ThingSpeak.");
  delay(1000);
}

void loop()
{
    Serial.println("Sending Data on ThingSpeak...");
    //My data is just numbers incrementing by 1
    ThingSpeak.writeField(myChannelNumber, 1, value, myWriteAPIKey);
    delay(20000);          // ThingSpeak will only accept updates every 15 seconds.
    Serial.print(value);
    Serial.println(" has been uploaded.");
    Serial.println("");
    value++;
}

