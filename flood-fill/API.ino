#include "Encoder.h"

int ena=10;
int enb=11;

int in1=9;  //Left
int in2=8;
int in3=A5;  //Right
int in4=A4;

int ft=4;
int fe=A1;
int rt=5;
int re=A2;
int lt=6;
int le=A3;
long z=1.385;
// int ma=2;
// int mb=3;


// definimg encoder pins
Encoder knobLeft(2,12);
Encoder knobRight(3,7);


void setup() {
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ft,OUTPUT);
  pinMode(rt,OUTPUT);
  pinMode(lt,OUTPUT);
  pinMode(fe,INPUT);
  pinMode(re,INPUT);
  pinMode(le,INPUT);
  Serial.begin(9600);

}

float distance(int trigPin,int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  // Read the time taken for the ultrasonic pulse to return
  long duration = pulseIn(echoPin, HIGH);
  // Speed of sound is approximately 343 meters per second or 29 microseconds per centimeter
  float distance_cm = duration * 0.0343 / 2;
  Serial.println(distance_cm);
  return distance_cm;
}

bool wallFront() {
  if(distance(ft,fe)>8 && distance(ft,fe)<800)
    return false;
  return true;
}

bool wallLeft() {
  if(distance(lt,le)>8 && distance(lt,le)<800)
    return false;
  return true;
}


bool wallRight() {
  if(distance(rt,re)>8 && distance(rt,re)<800)
    return false;
  return true;
}


void turnRight() {
  Serial.println("rightturn");
  long newLeft, newRight;
  knobLeft.write(0);
  knobRight.write(0);
  newLeft = 2*abs(knobLeft.read())/1600;
  newRight = 2*abs(knobRight.read())/1600;
  long  finalpos=z;
  while((newRight<finalpos) || (newLeft<finalpos)){
    // Serial.println(newLeft);
    // Serial.println(newRight);
    if(newRight==newLeft ) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, LOW);   // Left wheel forward
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);  // Right wheel forward
      digitalWrite(in4, LOW); 
      }
      else if(newRight>newLeft) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, LOW);   // Left wheel forward
      digitalWrite(in2, HIGH );
      digitalWrite(in3, LOW );  // Right wheel stop
      digitalWrite(in4, LOW);
      }
    else if(newRight<newLeft) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, LOW);   // Left wheel STOP
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);  // Right wheel forward
      digitalWrite(in4, LOW);
      }

    newLeft = 2*abs(knobLeft.read())/1600;
    newRight = 2*abs(knobRight.read())/1600;
  }
  
    digitalWrite(in1, LOW);   // Left wheel STOP
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);  // Right wheel forward
    digitalWrite(in4, LOW);
}

void moveForward() {
  Serial.println("forward");
  long newLeft, newRight;
  knobLeft.write(0);
  knobRight.write(0);
  newLeft = abs(knobLeft.read())/1725;
  newRight = abs(knobRight.read())/1725;
  long  finalpos=1.4433;
  while((newLeft<finalpos || newRight<finalpos) && distance(ft,fe)>5){
    // Serial.println(newLeft);
    // Serial.println(newRight);
    if(newRight==newLeft) {
      analogWrite(ena,100);
      analogWrite(enb,100);
      digitalWrite(in1, LOW);   // Left wheel forward
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH); 
      }

    else if((newRight>newLeft || distance(rt,re)>(distance(lt,le)+0.5) ) && newLeft <finalpos ) {
      analogWrite(ena,100);
      analogWrite(enb,100);
      digitalWrite(in1, LOW);   // Left wheel forward
      digitalWrite(in2, HIGH );
      digitalWrite(in3, LOW );  // Right wheel stop
      digitalWrite(in4, LOW);
      }
    else if((newRight<newLeft || distance(rt,re)<(distance(lt,le)-0.5)) && newRight <finalpos) {
      analogWrite(ena,100);
      analogWrite(enb,100);
      digitalWrite(in1, LOW);   // Left wheel STOP
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH);
      }
    newLeft = abs(knobLeft.read())/1725;
    newRight = abs(knobRight.read())/1725;
    long x=(knobRight.read());
    // Serial.print(x);
    // Serial.println(" x");
  }
  // if(distance(ft,fe)>6 && distance(ft,fe)<16){
  //   long newLeft, newRight;
  //   knobLeft.write(0);
  //   knobRight.write(0);
  //   newLeft = abs(knobLeft.read())/1700;
  //   newRight = abs(knobRight.read())/1700;
  //   long  finalpos=1.4433;
  //   while(distance(ft,fe)>5 ){
  //     float speed =150;
  //     float dist=distance(ft,fe);
  //     if (dist<12 && dist>=3){
  //       speed=(dist-3)*15;
  //     }
  //     // Serial.println(newLeft);
  //     // Serial.println(newRight);
  //     // if (distance(lt,le)>900){
  //     //   rightjerk();
  //     // }+
  //     // else if (distance(rt,re)>900){
  //     //   leftjerk();
  //     // }
  //     if(newRight==newLeft) {
  //       analogWrite(ena,speed);
  //       analogWrite(enb,speed);
  //       digitalWrite(in1, LOW);   // Left wheel forward
  //       digitalWrite(in2, HIGH);
  //       digitalWrite(in3, LOW);  // Right wheel forward
  //       digitalWrite(in4, HIGH); 
  //       }

  //     else if(newRight>newLeft && newLeft <finalpos) {
  //       analogWrite(ena,speed);
  //       analogWrite(enb,speed);
  //       digitalWrite(in1, LOW);   // Left wheel forward
  //       digitalWrite(in2, HIGH );
  //       digitalWrite(in3, LOW );  // Right wheel stop
  //       digitalWrite(in4, LOW);
  //       }
  //     else if(newRight<newLeft && newRight <finalpos) {
  //       analogWrite(ena,speed);
  //       analogWrite(enb,speed);
  //       digitalWrite(in1, LOW);   // Left wheel STOP
  //       digitalWrite(in2, LOW);
  //       digitalWrite(in3, LOW);  // Right wheel forward
  //       digitalWrite(in4, HIGH);
  //       }
  //     newLeft = abs(knobLeft.read())/1700;
  //     newRight = abs(knobRight.read())/1700;
  //     long x=(knobRight.read());
  //     // Serial.print(x);
  //     // Serial.println(" x");
  //   }
  //   }
  
    digitalWrite(in1, LOW);   // Left wheel STOP
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);  // Right wheel forward
    digitalWrite(in4, LOW);
}

void moveForward2(){
  long newLeft, newRight;
  knobLeft.write(0);
  knobRight.write(0);
  newLeft = abs(knobLeft.read())/506;
  newRight = abs(knobRight.read())/506;
  long  finalpos=1.4433;
  int speed=50;
  while(newLeft<finalpos || newRight<finalpos && distance(ft,fe)>5){
    // float speed =150;
    //   float dist=distance(ft,fe);
    //   if (dist<12 && dist>=3){
    //     speed=(dist-3)*15;
    //   }
  if(newRight==newLeft) {
      analogWrite(ena,speed);
      analogWrite(enb,speed);
      digitalWrite(in1, LOW);   // Left wheel forward
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH); 
      }

    else if(newRight>newLeft && newLeft <finalpos) {
      analogWrite(ena,speed);
      analogWrite(enb,speed);
      digitalWrite(in1, LOW);   // Left wheel forward
      digitalWrite(in2, HIGH );
      digitalWrite(in3, LOW );  // Right wheel stop
      digitalWrite(in4, LOW);
      }
    else if(newRight<newLeft && newRight <finalpos) {
      analogWrite(ena,speed);
      analogWrite(enb,speed);
      digitalWrite(in1, LOW);   // Left wheel STOP
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH);
      }
    newLeft = abs(knobLeft.read())/506;
    newRight = abs(knobRight.read())/506;
    long x=(knobRight.read());
    // Serial.print(x);
    // Serial.println(" x");
  }
    digitalWrite(in1, LOW);   // Left wheel STOP
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);  // Right wheel forward
    digitalWrite(in4, LOW);
}
// check for encoder values if negative
void turnLeft() {
 Serial.println("leftturn");
  long newLeft, newRight;
  knobLeft.write(0);
  knobRight.write(0);
  newLeft = 2*abs(knobLeft.read())/1500;
  newRight = 2*abs(knobRight.read())/1500;
  long  finalpos=z;
  while((newRight<finalpos) || (newLeft<finalpos)){
    // Serial.println(newLeft);
    // Serial.println(newRight);
    if(newRight==newLeft ) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, HIGH);   // Left wheel forward
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH); 
      }
      else if(newRight>newLeft) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, HIGH);   // Left wheel forward
      digitalWrite(in2, LOW );
      digitalWrite(in3, LOW );  // Right wheel stop
      digitalWrite(in4, LOW);
      }
    else if(newRight<newLeft) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, LOW);   // Left wheel STOP
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH);
      }

    newLeft = 2*abs(knobLeft.read())/1500;
    newRight = 2*abs(knobRight.read())/1500;
    long x=(knobRight.read());
    // Serial.print(x);
    // Serial.println(" x");
  }
  
    digitalWrite(in1, LOW);   // Left wheel STOP
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);  // Right wheel forward
    digitalWrite(in4, LOW);
}


void uturn(){
  
  Serial.println("uturn");
  long newLeft, newRight;
  knobLeft.write(0);
  knobRight.write(0);
  newLeft = abs(knobLeft.read())/1624;
  newRight = abs(knobRight.read())/1624;
  long  finalpos=z;
  while((newRight<finalpos) || (newLeft<finalpos)){
    // Serial.println(newLeft);
    // Serial.println(newRight);
    if(newRight==newLeft ) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, HIGH);   // Left wheel forward
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH); 
      }
      else if(newRight>newLeft) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, HIGH);   // Left wheel forward
      digitalWrite(in2, LOW );
      digitalWrite(in3, LOW );  // Right wheel stop
      digitalWrite(in4, LOW);
      }
    else if(newRight<newLeft) {
      analogWrite(ena,150);
      analogWrite(enb,150);
      digitalWrite(in1, LOW);   // Left wheel STOP
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);  // Right wheel forward
      digitalWrite(in4, HIGH);
      }

    newLeft = abs(knobLeft.read())/1624;
    newRight = abs(knobRight.read())/1624;
    long x=(knobRight.read());
    // Serial.print(x);
    // Serial.println(" x");
  }
  
    digitalWrite(in1, LOW);   // Left wheel STOP
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);  // Right wheel forward
    digitalWrite(in4, LOW);
}


