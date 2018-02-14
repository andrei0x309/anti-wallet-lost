// Receiver
#include "VirtualWire.h"
unsigned long time;
unsigned long last_ok;
const int buzzerPin = 3;

void setup()
{
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(8);
  vw_setup(200); // Bits per sec
  pinMode(13, OUTPUT);
  last_ok = millis();
  vw_rx_start(); // Start the receiver PLL running
}
void loop()
{
  time = millis();
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    last_ok = time;
    for (int i=0; i <= 6; i++){
          digitalWrite(13,i%2);
          delay(20);
       }
  }
  
  if((last_ok + 10000) <  time){
    tone( buzzerPin, 2000, 500);
    delay(1000);
  }
}
