// Sender
#include "VirtualWire.h"

int var = 0;

void setup() {
  
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(8);
  vw_setup(200);// speed of data transfer Kbps
}

void loop(){

  var=~var;
  vw_send((uint8_t *)String(var).c_str(), String(var).length());
  vw_wait_tx(); // Wait until the whole message is gone
  
  for (int i=0; i <= 6; i++){
        digitalWrite(13,i%2);
        delay(20);
     }
  
  digitalWrite(13,0);
  delay(4000);
}
