/**
  Whack-a-mole
*/

const int NUM_MOLES = 3;
const int RISE_FACTOR = 10000;
const int MIN_UP = 10000;
const int MAX_UP = 100000;

struct mole_t {
  int out_pin;
  int in_pin;
  int state;
};

mole_t moles[] = {
  {5, 4, 0},
  {6, 3, 0},
  {7, 2, 0}
};

int score = 0;

void setup() {
  // Initialize random number generator
  Serial.begin(9600);
  for(int i = 0; i < NUM_MOLES; ++i) {
    mole_t &mole = moles[i];
    pinMode(mole.out_pin, OUTPUT);
    pinMode(mole.in_pin, INPUT);
    digitalWrite(mole.out_pin, HIGH);
  }
}

void loop() {
  for(int i = 0; i < NUM_MOLES; ++i) {
    mole_t &mole = moles[i];
    if(mole.state > 0) {
      // Mole is up.
      
      // First check if it's been whacked.
      if(digitalRead(mole.in_pin)) {
        Serial.print("Whacked mole number ");
        Serial.println(i);
        digitalWrite(mole.out_pin, HIGH);
        mole.state = 0;
        score++;
        
        Serial.print("Score is ");
        Serial.println(score);
      }
      
      // Then decrement the time to fall, and fall if necessary
      if(!--mole.state) {
        digitalWrite(mole.out_pin, HIGH);
        Serial.print("Lowering mole number ");
        Serial.println(i);
      }
    }
    else {
      if(!random(RISE_FACTOR)) {
        Serial.print("Raising mole number ");
        Serial.println(i);
        digitalWrite(mole.out_pin, LOW);
        mole.state = random(MIN_UP, MAX_UP);
      }
    }
  }
}
