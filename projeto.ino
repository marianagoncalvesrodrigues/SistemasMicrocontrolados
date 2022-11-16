#include <Servo.h> 
#include <SoftwareSerial.h> //biblioteca bluetooth

SoftwareSerial SerialBT(10, 11); // RX, TX do Arduino

Servo meuservo;
int ang = 0;
int sensorAgua = 8;
int msgEstendeVaral = 0;
int motor1Pin1 = 5; 
int motor1Pin2 = 6;
int agua = A0;

void setup() {
  SerialBT.begin(9600);
  Serial.begin(9600);
  meuservo.attach(9);  // Pino usado para conectar o servo
  pinMode(agua, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
}

void estendeVaral(){
  analogWrite(motor1Pin1, 120);//frente
  digitalWrite(motor1Pin2, LOW);
  delay(2000);
  digitalWrite(motor1Pin1, LOW);
  msgEstendeVaral = 1;
  SerialBT.write(msgEstendeVaral);
}

void recolheVaral(){
  analogWrite(motor1Pin2, 120);//marcha ré
  digitalWrite(motor1Pin1, LOW);
  delay(2000);
  digitalWrite(motor1Pin2, LOW);
  msgEstendeVaral = 0;
  SerialBT.write(msgEstendeVaral);  
}

void loop() {
  int aguinha = analogRead(agua);
  Serial.println(aguinha);
  if( analogRead(agua) < 512 && msgEstendeVaral) {
    recolheVaral();
    if(SerialBT.available()){
      int dat = SerialBT.read();
      if(dat == 1){
        estendeVaral();
      }
    }
  } 
  if(SerialBT.available()){
    int data = SerialBT.read();
    if(data == 1){
      estendeVaral();
    }else if(data == 0){
      recolheVaral();
    }
  }
}
