int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
int ledPin = 13;
// outside leads to ground and +5V
int val = 0; // variable to store the value read
void setup() {
  Serial.begin(9600); // setup serial
  pinMode(ledPin, OUTPUT);
}
void loop() {
  val = analogRead(analogPin); // read the input pin
  Serial.println(val); // debug value
  analogWrite(ledPin, val/4);
}
