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
  pinMode(8, OUTPUT);
}
void loop() {
  val = analogRead(analogPin); // read the input pin
  Serial.println(val); // debug value
  analogWrite(ledPin, val/4);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(2);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
} 
