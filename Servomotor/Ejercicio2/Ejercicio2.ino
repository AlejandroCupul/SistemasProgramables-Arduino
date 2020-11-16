//SISTEMAS PROGRAMABLES - 7°A
//Alumno: Marco Alejandro Cupul Hau
//23/10/20

#include <Servo.h> //Se importa la librería Servo para indicarle al arduino que tiene un servomotor conectado.
Servo servo1; //Se declara un objeto de tipo Servo nombrando el servomotor a usar.

void setup() {
  servo1.attach(1); //Se indica el número del PIN en el que se encuentra conectado el servomotor al Arduino.
}

void loop() { //Función que contiene el código principal el cual se ejecuta repetidamente mientras el arduino está encendido.
  
  for (int pos=0; pos<180; pos+=1) //Ciclo que permite posicionar el servomotor en los ángulos de 0° a 180° avanzando de a 1°.
  {
      servo1.write(pos); //Indica el ángulo en la que se posicionará el servomotor conectado.
      delay(25); //Se indica el tiempo de espera de 25 milisegundos.
  }
  
  for (int pos=180; pos>0; pos-=1) //Ciclo que permite regresar a las posiciones anteriores desde 180° a 0° disminuyendo de a 1°.
  {
      servo1.write(pos); //Se indica mediante variable el ángulo en la que se regresará el servomotor conectado.
      delay(25); //Tiempo de espera de 25 milisegundos por cada posición que recorra para que todo el recorrido tome 4.5 segundos.
  }
    
}
