#include <Wire.h>

const uint8_t DIGIPOT_ADDRESS = 0x58;

void setup() {
  Wire.begin();
}

void loop() {
  for(int i = 0; i < 256; ++i) {
    Wire.beginTransmission(DIGIPOT_ADDRESS);
    Wire.write((uint8_t)0);
    Wire.write(i);
    Wire.endTransmission();
    delay(100);
  }
}

