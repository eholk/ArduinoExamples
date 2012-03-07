const int LIGHT_SENSOR = 0;
const int LED = 13;

const int THRESHOLD = 200;

void setup() {
  pinMode(LIGHT_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int x = analogRead(LIGHT_SENSOR);

  if(x < THRESHOLD) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}

