#include <Servo.h>

#define X_PIN 11
#define Y_PIN 10
#define LASER 8

Servo servo_x;
Servo servo_y;

const long action_delay = 10800000; // 3 hours in ms
const long interval = 900000; // 15 minutes in ms
unsigned long last_active = 0;

void setup() {
  // put your setup code here, to run once:
  servo_x.attach(X_PIN);
  servo_y.attach(Y_PIN);

  pinMode(LASER, OUTPUT);
  digitalWrite(LASER, HIGH);

  homing();
  delay(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(millis() - last_active <= interval) {
    handleServos();
  }
  last_active = millis() + action_delay;
  digitalWrite(LASER, LOW);
  homing();
  delay(action_delay);
}

void homing() {
  servo_x.write(90);
  servo_y.write(90);
}

void handleServos() {
  // do some random movements to swing the laser around
  // combinations of directions and time spent moving
  int randx = random(30, 131);
  int randy = random(30, 131);
  servo_x.write(randx);
  servo_y.write(randy);
  delay(random(750, 1001));
}
