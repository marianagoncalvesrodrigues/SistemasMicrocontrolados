#include <Servo.h> 
#include <SoftwareSerial.h> //biblioteca bluetooth

SoftwareSerial SerialBT(10, 11); // RX, TX do Arduino

Servo meuservo;
int ang = 0;
int sensorAgua = 8;
int botao = 7;
int msgEstendeVaral = 0;


void setup() {
  SerialBT.begin(9600);
  meuservo.attach(9);  // Pino usado para conectar o servo
  pinMode(sensorAgua, INPUT);
  pinMode(botao, INPUT_PULLUP);
}

void estendeVaral(){
  for (ang = 0; ang <= 360; ang += 1) { // Vai de 0º até 360º
    meuservo.write(ang);              // Comando que envia o sinal para o servo rotacionar
    delay(15);                       // Espera 15ms 
  }
  msgEstendeVaral = 1;
  SerialBT.write(msgEstendeVaral);
}

void recolheVaral(){
  for (ang = 360; ang >= 0; ang -= 3) { // Vai de 360º até 0º (+ rápido)
    meuservo.write(ang);                // Comando que envia o sinal para o servo rotacionar
    delay(15);                          // Espera 15ms 
  }
  msgEstendeVaral = 0;
  SerialBT.write(msgEstendeVaral);  
}

void loop() {
  if( digitalRead(sensorAgua) == LOW) {
    recolheVaral();
  }
  //if(digitalRead(botao) == LOW){
   // estendeVaral(); 
  //}
  if(SerialBT.available()){
    int data = SerialBT.read();
    if(data == 1){
      estendeVaral();
    }else if(data == 0){
      recolheVaral();
    }
  }
}
