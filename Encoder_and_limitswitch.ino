int val;
int encoder0PinA = 53;
int encoder0PinB = 50;
int encoder0PinZ = 52;
int encoder0Pos = 0;
int encoder0revs = 0;
int encoder0PinALast = LOW;
int n = LOW;
int Lswitch = 43;
int LED = 13;


void setup() {
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (encoder0PinZ, INPUT);
  pinMode(Lswitch, INPUT); 
  // LED turns on when limit switch engages
  pinMode(LED, OUTPUT); 
  digitalWrite(LED,LOW);
  Serial.begin (9600);
}

void loop() {
  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
    if (digitalRead(encoder0PinZ) == HIGH) {
      Serial.println("ROTATE");
    }
    if (encoder0Pos>1024) {
      encoder0revs--;
      encoder0Pos=0;
      Serial.println(encoder0revs);      
    }
    if (encoder0Pos<-1024) {
      encoder0revs++;
      encoder0Pos=0;
      Serial.println(encoder0revs);
    }    
  }
  encoder0PinALast = n;
  if( digitalRead(Lswitch) == LOW ) {
    digitalWrite(LED,HIGH);
    Serial.println("Turning Motor Off - Retract tether and bring back plane");
  } else {
    digitalWrite(LED,LOW);
  }
}
