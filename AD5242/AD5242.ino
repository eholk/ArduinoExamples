#include <Wire.h>
#include "nunchuck_funcs.h"

const uint8_t DIGIPOT_ADDRESS = 0x58 >> 1;

void setup() {
  Wire.begin();
  nunchuck_init_light();
  Serial.begin(19200);
  Serial.println("Initialized");
}

void loop() {
  
  nunchuck_get_data();
  
  Serial.println("Got Nunchuck");
  
  int accelx = nunchuck_accelx();
  
  Serial.print("Accel is ");
  Serial.println(accelx);
  
  int val = map(accelx, 75, 185, 0, 256);
  
  Serial.println(val);
  
  delay(10);
  
  {
    Wire.beginTransmission(DIGIPOT_ADDRESS);
    Wire.write((uint8_t)0);
    Wire.write(val);
    Wire.endTransmission();
  }
  
  Serial.println("Wrote Digipot");
  
  delay(500);
}

// 75 to 185
