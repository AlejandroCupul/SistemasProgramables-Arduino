//SISTEMAS PROGRAMABLES - 7°A
//Alumno: Marco Alejandro Cupul Hau
//23/10/20

#include <Servo.h> //Se importa la librería Servo para indicarle al arduino que tiene un servomotor conectado.
Servo servo1; //Se declara un objeto de tipo Servo nombrando el servomotor a usar.

void setup() {
  servo1.attach(1); //Se indica el número del PIN en el que se encuentra conectado el servomotor al Arduino.
}

void loop() { //Función que contiene el código principal el cual se ejecuta repetidamente mientras el arduino está encendido.
  int t=5000; //Se declara una variable con el tiempo de permanencia máxima en milisegundos.
  for (int pos=0; pos<180; pos+=45) //Ciclo que permite posicionar el servomotor en los ángulos de 0° a 180° avanzando de a 45°.
  {
    servo1.write(pos); //Indica el ángulo en la que se posicionará el servomotor conectado.
    delay(t); //Indica el tiempo de espera a través de la variable declarada con anterioridad.
    t-=1000; //Se disminuye un segundo a la variable del tiempo de espera.
  }
  
  for (int pos=180; pos>0; pos-=20) //Ciclo que permite regresar a las posiciones anteriores desde 180° a 0° disminuyendo de a 20°.
  {
    servo1.write(pos); //Se indica mediante variable el ángulo en la que se regresará el servomotor conectado.
    delay(1000); //Tiempo de espera de 1 segundo por cada posición que recorra.
  }
  
}
