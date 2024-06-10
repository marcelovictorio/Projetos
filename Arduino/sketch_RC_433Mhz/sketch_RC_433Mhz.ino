#include <RCSwitch.h>
RCSwitch mySwitch=RCSwitch();
int oldvalue;
int value;


void setup() {
 Serial.begin(9600);
 mySwitch.enableReceive();
 Serial.println("Conectado a 9600");
 }

void loop() {
  if (mySwitch.available())
  {
    Serial.println("available");
    oldvalue= value;
    value=mySwitch.getReceivedValue();
    if (value== oldvalue)
    {}
    else{
      if (value==0){
        Serial.print("Recebido");
        Serial.print(mySwitch.getReceivedValue());
        Serial.print("/");
        Serial.print(mySwitch.getReceivedBitlength());
        Serial.print("bit");
        Serial.print("Protocolo:");
        Serial.println(mySwitch.getReceivedProtocol());}
      }
    }
  }
