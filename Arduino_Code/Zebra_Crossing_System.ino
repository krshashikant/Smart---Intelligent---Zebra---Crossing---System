#include <Servo.h>

Servo barrier;

const int trigPin = 9;
const int echoPin = 10;
const int redLED = 2;
const int greenLED = 3;
const int buzzerPin = 4;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  barrier.attach(6);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);

  barrier.write(0);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance <= 20)
  {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    tone(buzzerPin, 1000);

    barrier.write(90);

    delay(5000);

    noTone(buzzerPin);

    barrier.write(0);

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  delay(500);
}
