This directory includes some examples of how to use an LED as a light
sensor. They assume that an LED is connected from the Arduino's analog
pin 0 to ground.

* SerialOutput - This reads the light value from analog pin 0 and
  dumps it to the serial. It's useful for determining threshold
  values.
* Threshold - Reads a value from the light sensor and turns on the LED
  on pin 13 if it is dark.
* Fading - Like threshold, but uses `analogWrite()` to fade the LED on
  pin 13 in and out depending on how dark it is.

The `LED Light Sensor.fzz` file includes circuit diagram for how to
wire everything up. It uses Fritzing.
