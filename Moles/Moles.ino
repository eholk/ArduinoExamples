/**
  Whack-a-mole
*/

const int NUM_MOLES = 3;
const int RISE_FACTOR = 10000;
const int MIN_UP = 1000;
const int MAX_UP = 100000;

struct mole_t {
  int out_pin;
  int in_pin;
  int state;
};

mole_t moles[] = {
  {5, -1, 0},
  {6, -1, 0},
  {7, -1, 0}
};

void setup() {
  // Initialize random number generator
  Serial.begin(9600);
  for(int i = 0; i < NUM_MOLES; ++i) {
    digitalWrite(moles[i].out_pin, HIGH);
  }
}

void loop() {
  if(Serial.available()) {
    int i = Serial.read() - '0';
    if(0 <= i && i < 3) {
      mole_t &mole = moles[i];
      
      if(mole.state > 0) {
        digitalWrite(mole.out_pin, HIGH);
        Serial.print("Lowering mole number ");
        Serial.println(i);
        mole.state = 0;
      }
      else {
        Serial.print("Raising mole number ");
        Serial.println(i);
        digitalWrite(mole.out_pin, LOW);
        mole.state = random(MIN_UP, MAX_UP);
      }
    }
    else {
      Serial.println("Invalid Mole");
    }
  }
  
/*  
  for(int i = 0; i < NUM_MOLES; ++i) {
    mole_t &mole = moles[i];
    if(mole.state > 0) {
      // Mole is up.
      
      // First check if it's been whacked.
      
      // Then decrement the time to fall, and fall if necessary
      if(!--mole.state) {
        digitalWrite(mole.out_pin, LOW);
        Serial.print("Lowering mole number ");
        Serial.println(i);
      }
    }
    else {
      if(!random(RISE_FACTOR)) {
        Serial.print("Raising mole number ");
        Serial.println(i);
        digitalWrite(mole.out_pin, HIGH);
        mole.state = random(MIN_UP, MAX_UP);
      }
    }
  }
*/
}
