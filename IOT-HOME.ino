#include <ESP32Servo.h>

static const int servoPin = 14;
static const int left_LED = 33;

Servo garagem;
int current_value = 35;

void setup() {
  Serial.begin(115200);
  garagem.setPeriodHertz(50);
  garagem.attach(servoPin, 500, 2400);
  pinMode(left_LED, OUTPUT);
}

void loop() {
  digitalWrite(left_LED, HIGH);
  opening();
  delay(2000);
  closing();
  digitalWrite(left_LED, LOW);
  delay(2000);
}

void closing() {
  for (int i=current_value; i<95; i++) {
    garagem.write(i);
    current_value = i;
    Serial.println(current_value);
    delay(50);
  }
}


void opening() {
  for (int i=current_value; i>35; i--) {
    garagem.write(i);
    current_value = i;
    Serial.println(current_value);
    delay(50);
  }
}
