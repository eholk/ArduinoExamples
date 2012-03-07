const int LIGHT_SENSOR = 0;
const int LED = 13;

void setup() {
  pinMode(LIGHT_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(LIGHT_SENSOR);
  Serial.println(x);
}

