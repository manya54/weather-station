Second ESP32:
Bluetooth and lora receiver:
#include <SPI.h>
#include <LoRa.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT; 

int state;
int flag = 0;

//define the pins used by the transceiver module
#define ss 5
#define rst 0
#define dio0 2

void setup() {
  Serial.begin(115200); //baud rate
  while (!Serial);

//setup lora traceiver module
LoRa.setPins(ss,rst,dio0);

//replace the lora.begin argument with your location frequency: 866E6
while(!LoRa.begin(866E6)){
  Serial.println(".");
  delay(500);

  
}
 

LoRa.setSyncWord(0x5F); //the sync word assures you dont get lora messages from other transcievers
Serial.println("LoRa initializing OK");

SerialBT.begin("Manyas S23"); //using the device name to connect it with bluetooth
  Serial.println("the device is on, now you can pair with bluetooth");
}
void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket(); 
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); //printing the recived data to the serial moniter
      SerialBT.println(LoRaData); //printing the recived data to the bluetooth terminal on your phone
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());


 }

}
