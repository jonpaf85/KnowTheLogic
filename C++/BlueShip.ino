//libraries
#include <Servo.h>
Servo myservo; // create servo object to control a servo

//Variables
char blueValue = 0;
int pos = 90;
int mspeed = 0;
int direc = 0;

const int enablepin = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myservo.attach(11);
  
  pinMode (13, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (2, OUTPUT);  
 
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW); 

  digitalWrite(10,LOW);//Motor is off
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    blueValue = Serial.read();
    Serial.print("Button number:  "); Serial.println (blueValue);
    if (blueValue == '1'){but1();}
    else if (blueValue == '2'){but2();}
    else if (blueValue == '3'){but3();}
    else if (blueValue == '4'){but4();}
    else if (blueValue == '5'){but5();}
    else if (blueValue == '0'){but6();}//my fault, sends a 0
    else if (blueValue == '7'){but7();}
    else if (blueValue == '8'){but8();}
    else if (blueValue == '9'){but9();}
    else {}        
    }
} 

void but1 () { 
  mspeed = 65;
  digitalWrite (3,HIGH);
  digitalWrite (2,LOW);
  analogWrite (enablepin,mspeed);}//Moton pin 10 , speed 10

void but2 () { 
  mspeed = 65;
  digitalWrite (3,LOW);
  digitalWrite (2,HIGH);
  analogWrite (enablepin,mspeed);}//Moton pin 10 , speed 10

void but3 () {
  mspeed = 255;
  analogWrite (enablepin,mspeed);}//Moton pin 10 , speed 50

void but4 () {
  mspeed = 128;
  analogWrite (enablepin,mspeed);}//Moton pin 10 , speed 50

void but5 () {
  mspeed = 65;
  Serial.println(mspeed);
  analogWrite (enablepin,mspeed);}

void but6 () {
  mspeed = 0;
  analogWrite (enablepin,mspeed);}//Moton pin 9 , speed LOW, motor off
 

void but7 () {
  pos = 90;
  myservo.write (pos );
  Serial.print ("Angle Position:  "); Serial.println(pos);
  delay (100);
  }

void but8 () {
  pos = pos - 5;
  myservo.write (pos );
  Serial.print ("Angle Position:  "); Serial.println(pos);
  delay (100);}

void but9 () {
  pos = pos + 5;
  myservo.write (pos );
  Serial.print ("Angle Position:  "); Serial.println(pos);
  delay (100);
}
