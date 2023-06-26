#include <SoftwareSerial.h>
#include "MQ7.h" 
int lm35Pin = A1;
float temp;
float gas;
SoftwareSerial Bluetooth(2,3);
MQ7 mq7(A0,5.0);

unsigned long time_previous, time_current;
boolean a = false;

void setup(){
  Serial.begin(9600);
  Bluetooth.begin(9600);
  time_previous = millis();
}
void loop(){
time_current = millis()  ;

float val = analogRead(A1);
double temp = (val * 5 * 100)/1024;
double gas = mq7.getPPM();

double sum = temp + gas;

Serial.print(temp); 
Serial.print(" ");
Serial.print(gas);
Serial.print(" ");
Serial.print(sum); 
Serial.println(); 
delay(1000); 
String strtemp = String(temp);
String strgas = String(gas);
String strsum = strtemp+" " +strgas;
if(time_current - time_previous >= 1000){ 
  Bluetooth.print(strsum);
  }
  
if (Bluetooth.available()) { 
 Serial.print(Bluetooth.read());  
  }
//exit(0);

}




   
//  Bluetooth.print((char)223); 
  
  //print(mq7.getPPM());
  //println("ppm");
  //  if (mq7.getPPM() = 100){
 //   Bluetooth.print(a);}
//  int val = analogRead(A0);
//    temp = (val * 5 * 100)/1024;
//    
//    Serial.println(temp);
//  delay(1000);
// String tempstr = String(temp);
