
#include <Servo.h>

Servo miServo;
const int pinPot=0;
const int pinServo=2;
const int pulsoMin=650;
const int pulsoMax=2550;
int valor;
int angulo;

void setup() {
  miServo.attach(pinServo,pulsoMin,pulsoMax);

}

void loop() {
  valor = analogRead(pinPot);
  angulo=map(valor,0,1023,180,0);
  miServo.write(angulo);
  delay(20);
}
