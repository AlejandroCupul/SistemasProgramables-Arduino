//:::::::::::::::PINES UTILIZADOS:::::::::::::::
int leds[]={2,3,4, 5,6,7, 8,9,10, 11,12,13};    //Semáforos 1, 2, 3 y 4 (verde, amarillo, rojo)

//::::::::::::::::::CONSTANTES:::::::::::::::::::
const int tVerde=7000;                          //Tiempo encendido de led verde (7 segundos)
const int tVerdeP=3000;                         //Tiempo parpadeando de led verde (3 segundos)
const int tAmarillo=3000;                       //Tiempo encendido de led amarillo (3 segundos)
const int tAmarilloP=2000;                      //Tiempo parpadeando de led amarillo (2 segundos)

//::::::::::::::CRITERIOS INICIALES::::::::::::::
void setup() {
  for (int n=0; n<=11; n++) {                   //Recorrer el arreglo de los pines utilizados   
    pinMode(leds[n], OUTPUT);                   //Activa los pines del 2 al 13 como salidas
  }
  for (int n=0; n<=11; n++) {                   //Recorrer el arreglo de los pines utilizados 
    digitalWrite(leds[n], LOW);                 //Apagar todos los leds conectados
  }                                             //Estado inicial: Semáforo 1 abierto y los demás cerrados
  digitalWrite(leds[0], HIGH);                  //Verde encendido del Semáforo 1
  digitalWrite(leds[5], HIGH);                  //Rojo encendido del Semáforo 2
  digitalWrite(leds[8], HIGH);                  //Rojo encendido del Semáforo 3
  digitalWrite(leds[11], HIGH);                 //Rojo encendido del Semáforo 4
}

//::::::::::::CICLO PROGRAMA PRINCIPAL:::::::::::
void loop() {
  int i=0;                                      //Declarar contador inicializado en cero
  while (i<=9) {                                //Ciclo para obtener los pines que ocupa cada led de semáforo
    encenderSemaforo(i, i+1, i+2);              //Llamar función para encender el semáforo enviando sus pines
    i=i+3;                                      //Aumentar el contador a 3 para saltar al siguiente semáforo
  }
}

//:::::::::FUNCIÓN PARA ACTIVAR SEMÁFORO:::::::::
void encenderSemaforo(int lVerde, int lAmarillo, int lRojo) {
  digitalWrite(leds[lRojo], LOW);               //Apagar led rojo
  digitalWrite(leds[lVerde], HIGH);             //Encender led verde
  delay(tVerde);                                //Tiempo de espera de led verde
  digitalWrite(leds[lVerde], LOW);              //Apagar led verde
  parpadearLed(lVerde, tVerdeP);                //Llamar función para parpadear led, enviando su pin y tiempo
  digitalWrite(leds[lAmarillo], HIGH);          //Encender led amarillo
  delay(tAmarillo);                             //Tiempo de espera de led amarillo
  digitalWrite(leds[lAmarillo], LOW);           //Apagar led amarillo
  parpadearLed(lAmarillo, tAmarilloP);          //Llamar a la función que hace parpadear un led
  digitalWrite(leds[lRojo], HIGH);              //Encender led rojo
}

//:::::FUNCIÓN PARA HACER PARPADEAR UN LED:::::
void parpadearLed(int nLed, int tParpadeo) {    //Recibir los valores de pin ocupado y duración de parpadeo
  int tiempo=0;                                 //Inicializar contador de tiempo en cero
  while(tiempo<=tParpadeo) {                    //Mientras contador sea menor o igual al tiempo de parpadeo:
    digitalWrite(leds[nLed],HIGH);              //Encender el led
    delay(100);                                 //Mantenerlo encendido 100 milisegundos
    digitalWrite(leds[nLed],LOW);               //Apagar el led
    delay(100);                                 //Mantenerlo apagado 100 milisegundos
    tiempo=tiempo+200;                          //Aumentar contador el tiempo total que realiza un parpadeo
  }                                             //Se repite el ciclo hasta que la condición ya no se cumpla
}
