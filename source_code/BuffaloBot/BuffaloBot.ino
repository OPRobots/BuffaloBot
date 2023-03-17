#include <Servo.h>

//Pines de los motores
int PinMotorDerecho = 10;
int PinMotorIzquierdo = 9;

//Pin sistema de arranque
int pinSistemaDeCuerda = 2;

//Motores
Servo MotorDerecho;
Servo MotorIzquierdo;

void setup() {
  // Inicia el puerto Serial
  Serial.begin(9600);

  // Inicia los pines
  pinMode(pinSistemaDeCuerda, INPUT_PULLUP);
  MotorDerecho.attach(PinMotorDerecho);
  MotorIzquierdo.attach(PinMotorIzquierdo);

  // Inicia ambos ESC
  MotorIzquierdo.writeMicroseconds(2000);
  MotorDerecho.writeMicroseconds(2000);
  delay(5000);
  MotorIzquierdo.writeMicroseconds(1000);
  MotorDerecho.writeMicroseconds(1000);
  delay(5000);
}
void loop() {
  // Imprime valor del jumper de inicio
  Serial.println(digitalRead(pinSistemaDeCuerda));

  // Comprueba si el jumper se ha liberado
  if (digitalRead(pinSistemaDeCuerda)) {
    // Escribe la velocidad deseada en los motores durante 15s, luego los para durante 5s
    MotorIzquierdo.writeMicroseconds(2000);
    MotorDerecho.writeMicroseconds(2000);
    delay(15000);
    MotorIzquierdo.writeMicroseconds(1000);
    MotorDerecho.writeMicroseconds(1000);
    delay(5000);
  }
}
