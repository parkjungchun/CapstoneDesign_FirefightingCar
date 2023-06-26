#include <SoftwareSerial.h>
const int ENA = 6;
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 2;
const int IN4 = 4;
const int ENB = 3;
SoftwareSerial mySerial(12,13);
char input;
void setup() {
  Serial.begin(9600); 
  mySerial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop(){
  if(mySerial.available()){
    input = mySerial.read();
    
    if(input =='w') {
      digitalWrite(IN1, HIGH);    //전진
      digitalWrite(IN2, LOW);
  
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      analogWrite(ENA, 200);
      analogWrite(ENB, 200);
      }
      
    
    if(input =='a') {
      digitalWrite(IN1, LOW);    //좌회전
      digitalWrite(IN2, HIGH);
  
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
      }
    
    if(input =='d') {
      digitalWrite(IN1, HIGH);    //우회전
      digitalWrite(IN2, LOW);
  
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
      }
    
    if(input =='s') {
      digitalWrite(IN1, LOW);    //후진
      digitalWrite(IN2, HIGH);
  
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
      }
    
    if(input =='q') {
      digitalWrite(IN1, HIGH);    //정지
      digitalWrite(IN2, HIGH);
  
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);

      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
      }
    }
exit(0);
}
