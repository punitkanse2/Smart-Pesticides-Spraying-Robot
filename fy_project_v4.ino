#include <Servo.h>
#include <SoftwareSerial.h>
#define RELAY_1 12

#include "dht.h"
#define dataPin A0
dht DHT;

int temp;
int hum;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


// For Front Wheels
int motor_r1 = 2;
int motor_r2 = 3;
int motor_r3 = 4;
int motor_r4 = 5;

// For Back Wheels
int motor_r5 = 6;
int motor_r6 = 7;
int motor_r7 = 8;
int motor_r8 = 9;



char flag;

void setup(){
Serial.begin(9600);

myservo.attach(11);

pinMode(RELAY_1, OUTPUT);
digitalWrite(RELAY_1, HIGH);

pinMode(motor_r1, OUTPUT);
pinMode(motor_r2, OUTPUT); 
pinMode(motor_r3, OUTPUT);
pinMode(motor_r4, OUTPUT);

pinMode(motor_r5, OUTPUT);
pinMode(motor_r6, OUTPUT); 
pinMode(motor_r7, OUTPUT);
pinMode(motor_r8, OUTPUT);

// initialize serial communication at 9600 bits per second:
}



void loop()
 { 

  sensData();
  
  if (Serial.available())
    {   
        flag = Serial.read();// read input from bluetooth
        if (flag == 'F')                
        {
          forword();
        }
        else if (flag == 'B')
        {
          backword();
        }

        if (flag == 'S')                
        {
          stop();
        }
        
        if (flag == 'L')
        {
          Fleft();
        }
        else if (flag == 'R')
        {
          Fright();
        }
        else if (flag == 'P')
        {
          Bleft();
        }
        else if (flag == 'K')
        {
          Bright();
        }
        
        if (flag == 'A')
        {
          Sleft();
        }
        else if (flag == 'C')
        {
          Sright();
        }
        
        if (flag == 'D')
        {
          digitalWrite(RELAY_1, HIGH);
        }
        else if (flag == 'E')
        {
          digitalWrite(RELAY_1, LOW);
        }
    }

 }





void stop(){

    digitalWrite(motor_r1, LOW);

    digitalWrite(motor_r2, LOW); 

    digitalWrite(motor_r3, LOW);

    digitalWrite(motor_r4, LOW);

    digitalWrite(motor_r5, LOW);

    digitalWrite(motor_r6, LOW); 

    digitalWrite(motor_r7, LOW);

    digitalWrite(motor_r8, LOW);

}



void forword(){ 
    
    digitalWrite(motor_r5, HIGH);

    digitalWrite(motor_r6, LOW); 

    digitalWrite(motor_r7, HIGH);

    digitalWrite(motor_r8, LOW);

}



void backword(){
   
    digitalWrite(motor_r5, LOW);

    digitalWrite(motor_r6, HIGH); 

    digitalWrite(motor_r7, LOW);

    digitalWrite(motor_r8, HIGH);

}


void Fleft(){

    digitalWrite(motor_r1, HIGH);

    digitalWrite(motor_r2, LOW); 

    digitalWrite(motor_r3, LOW);

    digitalWrite(motor_r4, LOW);
     
    digitalWrite(motor_r5, HIGH);

    digitalWrite(motor_r6, LOW); 

    digitalWrite(motor_r7, HIGH);

    digitalWrite(motor_r8, LOW);

}


void Fright(){

    digitalWrite(motor_r1, LOW);
    
    digitalWrite(motor_r2, LOW);
    
    digitalWrite(motor_r3, HIGH);
  
    digitalWrite(motor_r4, LOW);
    
    digitalWrite(motor_r5, HIGH);

    digitalWrite(motor_r6, LOW); 

    digitalWrite(motor_r7, HIGH);

    digitalWrite(motor_r8, LOW);
  
}

void Bleft(){

    digitalWrite(motor_r1, LOW);

    digitalWrite(motor_r2, HIGH); 

    digitalWrite(motor_r3, LOW);

    digitalWrite(motor_r4, LOW); 
    
    digitalWrite(motor_r5, LOW);

    digitalWrite(motor_r6, HIGH); 

    digitalWrite(motor_r7, LOW);

    digitalWrite(motor_r8, HIGH);

}


void Bright(){

    digitalWrite(motor_r1, LOW);
    
    digitalWrite(motor_r2, LOW);
    
    digitalWrite(motor_r3, LOW);

    digitalWrite(motor_r4, HIGH);

    digitalWrite(motor_r5, LOW);

    digitalWrite(motor_r6, HIGH); 

    digitalWrite(motor_r7, LOW);

    digitalWrite(motor_r8, HIGH);
  
}

void Sright(){
    myservo.write(180);              // tell servo to go to position in variable 'pos'
    delay(100);                    // waits 15ms for the servo to reach the position
    
    for(pos = 180; pos >= 135; pos -= 1){
    myservo.write(pos);
    delay(15);
    }    
    
    for(pos = 135; pos <= 180; pos += 1){
    myservo.write(pos);
    delay(15);
    }
  }


void Sleft(){
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(100);                    // waits 15ms for the servo to reach the position
    
    for(pos = 0; pos <= 45; pos += 1){
    myservo.write(pos);
    delay(15);
    }    
    
    for(pos = 45; pos >= 0; pos -= 1){
    myservo.write(pos);
    delay(15);
    }
}

void sensData(){
        int readData = DHT.read11(dataPin);
        hum = DHT.humidity;
        temp = DHT.temperature;
        Serial.print(temp); //send distance to App
        Serial.print(";");
        Serial.print(hum); //send distance to App 
        Serial.println(";");
        delay(1000);
}
