#define trig  10
#define echo 9
#define motor 3
long int duration, distance;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = 0.0343 * (duration / 2);

  if (distance < 200) {
    int speed = map(distance, 0, 200, 255, 64);
    analogWrite(motor, speed);
  } else {
    analogWrite(motor, 0);
  }
}