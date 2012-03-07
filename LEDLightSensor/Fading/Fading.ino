const int LIGHT_SENSOR = 0;
const int LED = 13;

const int MIN = 100;
const int MAX = 240;

void setup() {
  pinMode(LIGHT_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int x = analogRead(LIGHT_SENSOR);

  int light = 0;
  
  if(x < MIN)
    light = 255;
  else if(x > MAX)
    light = 0;
  else
    light = (2 * MAX) - (255 * x) / MIN;
  
  light = (light * 256) / 150;
  analogWrite(LED, light);
}

