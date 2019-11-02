//creamos constantes que simplifiquen el código y simplifiquen la legibilidad
const int enRojo = 0;
const int enVerde = 1;
const int subirPuente = 0;
const int bajarPuente = 1;
const int bajarBarreras = 0;
const int subirBarreras = 1;

//utilización de pines
int pinPulsador = 2; //Conectamos el pulsador en el pin 2
int pinRojo = 4;
int pinAmarillo = 6;
int pinVerde = 7;
int pinBarreras = 5;
//PASO A PASO: Definimos los pines donde tenemos conectadas las bobinas
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

//declaración de variables
int valorPulsador = 0;
int puenteElevado = false;

#include <Servo.h>
Servo myservo;
int posServo = 0;

// Secuencia de pasos (par máximo)
int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};
int paso2 [4][4] =
{
  {0, 0, 1, 1},
  {0, 1, 1, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 1}
};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPulsador, INPUT);
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBarreras, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Estado inicial
  myservo.attach(pinBarreras);
  semaforos(enVerde);
  barreras(subirBarreras);
}

void loop() {

  // put your main code here, to run repeatedly:
  //Leemos el valor del pulsador
  valorPulsador = digitalRead(pinPulsador);

  //Cuando el pulsador se oprima
  if (valorPulsador == 1) { //Si se oprime el pulsador...
    delay(100);
    if (puenteElevado == false) { //... y el puente está bajo
      //Elevar puente!!!!

      //Semáforos a rojo
      semaforos(enRojo);
      //Bajar barreras
      barreras(bajarBarreras);
      //Elevar puente
      //puente(subirPuente);

      puenteElevado = true; //Ahora el puente está elevado
    }
    else {//Si se oprime el pulsador ... y el puente está elevado
      //Bajar puente!!!

      //Bajar puente
      //puente(bajarPuente);
      //Elevar barreras
      barreras(subirBarreras);
      //Semáforos a verde
      semaforos(enVerde);

      puenteElevado = false; //Ahora el puente está bajo
    }
  }
  if(puenteElevado){
    puente(subirPuente);
  }else{
    puente(bajarPuente);
  }

}

//Programamos los semáforos
void semaforos(int enRojo) {
  if (enRojo == 0) {
    //Pone los semáforos en ROJO
    digitalWrite(pinRojo, 0);
    digitalWrite(pinAmarillo, 1);
    digitalWrite(pinVerde, 0);
    delay(2000);
    digitalWrite(pinRojo, 1);
    digitalWrite(pinAmarillo, 0);
    digitalWrite(pinVerde, 0);
  }
  else {
    //Pone los semáforos en VERDE
    digitalWrite(pinRojo, 0);
    digitalWrite(pinAmarillo, 1);
    digitalWrite(pinVerde, 0);
    delay(2000);
    digitalWrite(pinRojo, 0);
    digitalWrite(pinAmarillo, 0);
    digitalWrite(pinVerde, 1);
  }
}

//Programamos las barreras
void barreras(int hacer) {
  if (hacer == subirBarreras)
  {
    for (posServo = 90; posServo >= 0; posServo--) {
      // in steps of 1 degree
      myservo.write(posServo);
      delay(10);
    }
  } else {
    for (posServo = 0; posServo <= 90; posServo += 1) {
      myservo.write(posServo);
      delay(10);
    }
  }
}

//Programamos el puente
void puente(int elevar) {
  if (elevar == subirPuente) {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(5);
    }
  } else {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(IN1, paso2[i][0]);
      digitalWrite(IN2, paso2[i][1]);
      digitalWrite(IN3, paso2[i][2]);
      digitalWrite(IN4, paso2[i][3]);
      delay(5);
    }
  }
}
