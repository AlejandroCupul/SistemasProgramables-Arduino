/* _____________________________________________
  |            SISTEMAS PROGRAMABLES            |
  |   INGENIERÍA EN SISTEMAS COMPUTACIONALES    |
  |                 7° SEMESTRE                 |
  |          MARCO ALEJANDRO CUPUL HAU          |
  |                 27/11/2020                  |
  |_____________________________________________|*/
  
const int sensorPin = 0; // LDR

const int ocaso = 300; //valor minimo de luz para el cual haremos funcionar el sistema
const int luz_minima = 500; //rango de luz deseado (salida del sistema) éstos valores los debe asignar el usuario de acuerdo a su necesidad y situación.
const int luz_maxima = 550;

#define e1 10  // Enable Pin for motor 1
#define i1 8   // Control pin 1 for motor 1
#define i2 9   // Control pin 2 for motor 1

void setup()
{
 Serial.begin(9600);
}

void loop() {
 int valueAnalog = analogRead(sensorPin); //guardamos los valores observados por el LDR
 Serial.println(valueAnalog); //mostramos en pantalla la luz observada por el LDR

 if(valueAnalog < ocaso) {
   digitalWrite(e1, HIGH); // Motor Activado
   digitalWrite(i1, HIGH);  //Motor Parado = Hay luz insuficiente
   digitalWrite(i2, HIGH);
 }

 if(valueAnalog > ocaso && valueAnalog < luz_minima) {
   digitalWrite(e1, HIGH); // Motor Activado
   digitalWrite(i1, HIGH); // Gira adelante = Abre persiana
   delay(4000);
   digitalWrite(i1, HIGH);  //Motor Parado = Hay Luz ideal
   digitalWrite(i2, HIGH);
 }

 if(valueAnalog > luz_maxima) {
   digitalWrite(e1, HIGH); // Motor Activado
   digitalWrite(i1, LOW);  // Gira al revés = Cierra persiana
   delay(4000);
   digitalWrite(i1, HIGH);  //Motor Parado = Hay Luz ideal
   digitalWrite(i2, LOW);
 }

if(valueAnalog > luz_minima && valueAnalog < luz_maxima) {
   digitalWrite(e1, HIGH); // Motor Activado
   digitalWrite(i1, HIGH);  //Motor Parado = Hay Luz ideal
   digitalWrite(i2, HIGH);
 }

} 
