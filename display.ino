int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
int ledPin = 13;
// outside leads to ground and +5V
int val = 0; // variable to store the value read
int conta=0; //
int col;
int lin;
int pino = 2;
 
byte displaySeteSeg[10][7] = { 
  
 { 1,1,1,1,1,1,0 },  //DIGITO 0
 { 0,1,1,0,0,0,0 },  //DIGITO 1
 { 1,1,0,1,1,0,1 },  //DIGITO 2
 { 1,1,1,1,0,0,1 },  //DIGITO 3
 { 0,1,1,0,0,1,1 },  //DIGITO 4
 { 1,0,1,1,0,1,1 },  //DIGITO 5
 { 1,0,1,1,1,1,1 },  //DIGITO 6
 { 1,1,1,0,0,0,0 },  //DIGITO 7
 { 1,1,1,1,1,1,1 },  //DIGITO 8
 { 1,1,1,1,0,1,1 }   //DIGITO 9
 
};
void setup() {
  Serial.begin(9600); // setup serial
  pinMode(ledPin, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
void loop() {
  val = analogRead(analogPin); // read the input pin
  Serial.println(val); // debug value
  analogWrite(ledPin, val/4);
  
  if(conta<10){
    digitalWrite(pino, displaySeteSeg[col][lin]);
    conta++;
    col++;
    lin++;
    pino++;
  }else{
    conta=0;
  }
} 
