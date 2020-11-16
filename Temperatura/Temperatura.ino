
/* _____________________________________________
  |            SISTEMAS PROGRAMABLES            |
  |   INGENIERÍA EN SISTEMAS COMPUTACIONALES    |
  |                 7° SEMESTRE                 |
  |          MARCO ALEJANDRO CUPUL HAU          |
  |                 16/11/2020                  |
  |_____________________________________________|*/

//:::::::::::::::::::LIBRERÍAS:::::::::::::::::::
#include <LiquidCrystal.h>                      //Importar la librería para el manejo de la pantalla LCD.
#include <Servo.h>                              //Incluir la librería para controlar servomotores.
//::::::::::::::::::::OBJETOS::::::::::::::::::::
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);          //Crea un objeto enviando los pines (rs,e,d3,d2,d1,d0) del lcd.
Servo ventilador;                               //Crea un objeto de tipo Servo llamado Ventilador.
//:::::::::::::::::::VARIABLES:::::::::::::::::::
int sensor;                                     //Variable para almacenar la temperatura del sensor.
float temperatura;                              //Variable para almacenar la temperatura del sensor en °C.
//::::::::::::::CRITERIOS INICIALES:::::::::::::: 
void setup() {
  lcd.begin(16, 2);                             //Configurar número de columnas y filas de la pantalla (16x2).
  ventilador.attach(13);                        //Indica el número de pin al que está conectado el ventilador.
}
//:::::::::::CICLO PROGRAMA PRINCIPAL:::::::::::
void loop() {                                   //Se ejecuta repetidamente mientras el arduino está encendido.
  sensor = analogRead(A0);                      //Lee la temperatura del sensor conectado en la entrada A0.
  temperatura = ((sensor*5000.0)/1023)/10;      //Convierte la temperatura leída en grados centígrados.
  lcd.setCursor(0, 0);                          //Coloca el cursor en la columna 0, línea 1 (primera fila).
  lcd.print("Temp: ");                          //Imprime un mensaje en la pantalla.
  lcd.print(temperatura, 1);                    //Imprime la temperatura en grados.
  lcd.print(" C");                              //Imprime un mensaje en la pantalla.
  if (temperatura>65.0) {                       //Condición: Si la temperatura es mayor a 65°C hacer:
    for (int pos=0; pos<180; pos+=1) {          //Ciclo que permite girar el servomotor avanzando de a 1°.
      ventilador.write(pos);                    //Indica el ángulo en el que se posiciona el servomotor.
      delay(15);                                //Indica el tiempo de espera en milisegundos.
    }
  }else {                                       //En caso que la condición anterior no se cumpla, hacer:
    ventilador.write(0);                        //Posicionar el servomotor en el ángulo 0.
    delay(1000);                                //Tiempo de espera en el que se mantendrá quieto.
  }
}
