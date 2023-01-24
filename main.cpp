/*Medición de la posición de un motor*/
/*Código adaptado por: Juan Diego Elvis García Munayco*/
/*Fecha: Enero 2023*/

#include <Arduino.h>

#define ENCODER_A 2 
#define ENCODER_B 3 

void leerEncoder();

// Declaración de variables globales
volatile long temp,posicion = 0; 
float resolution = 600; // PPR

void setup() {
    Serial.begin(9600);
    pinMode(ENCODER_A, INPUT_PULLUP);
    pinMode(ENCODER_B, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENCODER_A), leerEncoder, RISING);
}

void loop() {
    float theta;
    if (posicion != temp){
        theta = posicion*360.0/resolution;
        Serial.println(theta);
        temp = posicion;
    }
}

// Función que suma o resta los pulsos registrados,
// dependiendo del sentido de giro del motor
void leerEncoder(){
    if (digitalRead(ENCODER_B) == LOW){ // Horario
        posicion++;
    }
    else{
        posicion--; // Antihorario
    }
}
