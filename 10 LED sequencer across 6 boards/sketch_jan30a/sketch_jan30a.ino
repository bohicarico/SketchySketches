/*
Left-to-right then right-to-left LED sequencer
Unified for:
- Arduino Uno / Nano
- Raspberry Pi Pico / Pico 2 / Pico 2 W
- ESP32
*/

int pokeValue = 150;

// LED pin definitions per board
#if defined(ESP32)
const int ledPins[] = {2, 4, 5, 12, 13, 14, 15, 16, 17, 18};
#elif defined(ARDUINO_ARCH_RP2040)
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
#else  // AVR (Uno, Nano)
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
#endif

const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  sequencerLtoR();
  sequencerRtoL();
  allLedsOn();
  delay(3 * pokeValue);
  allLedsOff();
  delay(3 * pokeValue);


  sequencerLtoRodds();
  allLedsOff();
  delay(3 * pokeValue);
  sequencerLtoRevens();
  allLedsOff();
  delay(3 * pokeValue);

  sequencerRtoLodds();
  allLedsOff();
  delay(3 * pokeValue);
  sequencerRtoLevens();
  allLedsOff();
  delay(3 * pokeValue);

  interceptorPackage1();
  interceptorPackage1();
  allLedsOff();
  pause();
  pause();
  allLedsOn();
  pause();
  pause();
  interceptorPackage2();
  interceptorPackage2();
}

void pause() {
  delay(pokeValue);
}

void sequencerLtoR() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    pause();
    digitalWrite(ledPins[i], LOW);
  }
}

void sequencerRtoL() {
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    pause();
    digitalWrite(ledPins[i], LOW);
  }
}

void allLedsOn() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

void allLedsOff() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

//   odd LEDs
void sequencerLtoRodds() {
  for (int i = 1; i < ledCount; i = i + 2) {
    digitalWrite(ledPins[i], HIGH);
    pause();
    digitalWrite(ledPins[i], LOW);
  }
}

//  evens LEDs
void sequencerLtoRevens() {
  for (int i = 0; i < ledCount; i = i + 2) {
    digitalWrite(ledPins[i], HIGH);
    pause();
    digitalWrite(ledPins[i], LOW);
  }
}

// odd LEDs
void sequencerRtoLodds() {
  for (int i = ledCount - 1; i >= 0; i = i - 2) {
    digitalWrite(ledPins[i], HIGH);
    pause();
    digitalWrite(ledPins[i], LOW);
  }
}

// even LEDs
void sequencerRtoLevens() {
  for (int i = ledCount - 2; i >= 0; i = i -2) {
    digitalWrite(ledPins[i], HIGH);
    pause();
    digitalWrite(ledPins[i], LOW);
  }
}

// half-on with half-off - switch
void LeftLedsOn() {
  for (int i = 0; i < ledCount/2; i++) {
    digitalWrite(ledPins[i], HIGH);
    //delay(pokeValue / 10);
    }
}
// half-on with half-off - switch
void RightLedsOn() {
  for (int i = 5; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    //delay(pokeValue / 10);
    }    
}



void interceptorPackage1(){
allLedsOff();
delay(75);
LeftLedsOn();
delay(75);
allLedsOff();
delay(75);
LeftLedsOn();
delay(75);

allLedsOff();
pause();
RightLedsOn();
pause();
}


void interceptorPackage2(){
allLedsOff();
delay(75);
RightLedsOn();
delay(75);
allLedsOff();
delay(75);
RightLedsOn();
delay(75);

allLedsOff();
pause();
LeftLedsOn();
pause();
}


