/*
  ESP32 Fade + LED Control
  Ported from Arduino Uno sketch
*/

#define LED_PWM_PIN  18
#define BLUE_LED     19
#define RED_LED      21

// PWM configuration
#define PWM_CHANNEL  0
#define PWM_FREQ     5000
#define PWM_RES      8   // 8-bit resolution (0–255)

int brightness = 0;
int fadeAmount = 15;
int globalDelay = 75;
float k = 1.25;

void setup() {
  // LED outputs
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // PWM setup
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(LED_PWM_PIN, PWM_CHANNEL);
}

void loop() {
  grind();
  blueON_redOFF();
  redON_blueOFF();
}

// ---------------- LED helpers ----------------

void blue_LED() {
  digitalWrite(BLUE_LED, HIGH);
  delay(globalDelay * 1.5);
  digitalWrite(BLUE_LED, LOW);
  delay(globalDelay * 1.5);
}

void red_LED() {
  digitalWrite(RED_LED, HIGH);
  delay(globalDelay * 1.5);
  digitalWrite(RED_LED, LOW);
  delay(globalDelay * 1.5);
}

void blueON_redOFF() {
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  delay(globalDelay * k);
}

void redON_blueOFF() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  delay(globalDelay * k);
}

// ---------------- PWM fade ----------------

void grind() {
  ledcWrite(PWM_CHANNEL, brightness);

  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
}
