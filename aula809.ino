int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
int ledPin = 13;
int pino = 2;
unsigned long myTime=0;
unsigned long currentMillis, previousMillis; 
unsigned long interval=1;
unsigned long timer_segments;
int Estado_segments, temp_uni, temp_dez, timer_contagem;
 

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

byte displaySeteSeg[10][7] = { 
  //a,b,c,d,e,f,g
  //1,0,6,4,5,2,3
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

void base_tempo (){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (timer_segments !=0){
      timer_segments--;
    }
    if (timer_contagem !=0){
      timer_contagem--;
    }   
  }
}

void tic_display(){
  switch(Estado_segments){
    case 0:
      Estado_segments=1;
      break;
    case 1:
      if(timer_segments ==0){
        timer_segments = 5;
        digitalWrite(0,displaySeteSeg[temp_uni][1]);
        digitalWrite(1,displaySeteSeg[temp_uni][0]);
        digitalWrite(2,displaySeteSeg[temp_uni][5]);
        digitalWrite(3,displaySeteSeg[temp_uni][6]);
        digitalWrite(4,displaySeteSeg[temp_uni][3]);
        digitalWrite(5,displaySeteSeg[temp_uni][4]);
        digitalWrite(6,displaySeteSeg[temp_uni][2]);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        Estado_segments=2;
      }
      break;
      
    case 2:  
      if(timer_segments ==0){
        timer_segments = 5;
        digitalWrite(0,displaySeteSeg[temp_dez][1]);
        digitalWrite(1,displaySeteSeg[temp_dez][0]);
        digitalWrite(2,displaySeteSeg[temp_dez][5]);
        digitalWrite(3,displaySeteSeg[temp_dez][6]);
        digitalWrite(4,displaySeteSeg[temp_dez][3]);
        digitalWrite(5,displaySeteSeg[temp_dez][4]);
        digitalWrite(6,displaySeteSeg[temp_dez][2]);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        Estado_segments=1;
      }
      break;
  }  
}

void tic_contagem(){
  if(timer_contagem == 0){
    timer_contagem=1000;
    temp_uni++;
    Serial.println(temp_uni);
    if(temp_uni == 10){
      temp_dez++;
      Serial.println("dez");
      Serial.println(temp_dez);
      temp_uni = 0;
      Serial.println(temp_uni);
      if(temp_dez == 10){
        temp_dez=0;
      }
    }
  }
}

void loop() {
  base_tempo();
  tic_display();
  tic_contagem();
} 


