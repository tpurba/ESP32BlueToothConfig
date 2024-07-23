#include "BluetoothSerial.h"
#include "RTClib.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

BluetoothSerial SerialBT;
RTC_DS1307 rtc;
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");//bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  DateTime now = rtc.now();
  print(rtc);
}

void loop() {
  //if we want to send something back to the app
//  if(Serial.available())
//  {
//    SerialBT.write(Serial.read());  
//  }
  if(SerialBT.available())
  {
    Serial.write(SerialBT.read());  
  }
  delay(20);
}
