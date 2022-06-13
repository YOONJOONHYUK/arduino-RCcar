
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(12, 13);   //RX,TX

int motor1PinA  = 2  ;
int motor1PinB  = 3  ;
int enablelPin  =11 ;   //enablelPin은 모터속도를 제어하는 핀
int motor2PinA  = 4  ;
int motor2PinB  = 5  ;
int enable2Pin  = 10 ;  
char in;
   void setup() {
        BTSerial.begin(9600);//블루투스 통신
        Serial.begin(9600);//시리얼통신
    
        pinMode(motor1PinA, OUTPUT);
        pinMode(motor1PinB, OUTPUT);
        pinMode(motor2PinA, OUTPUT);
        pinMode(motor2PinB, OUTPUT);
        pinMode(enablelPin, OUTPUT);
        pinMode(enable2Pin, OUTPUT);

        pinMode(9, OUTPUT);
        pinMode(8, OUTPUT);

        // set enablePin high so that motor can turn on:
       analogWrite(enablelPin, 150);
       analogWrite(enable2Pin, 150);
       }
   void loop() {
       if (BTSerial.available())
          { in =BTSerial.read();
            Serial.write(in); //시리얼에 in 변수 저장
         }
         if (Serial.available())  //시리얼에 저장된게 있니?
          {  BTSerial.write(Serial.read());  //in읽기
             Serial.print("data =");
           Serial.println(in);
          }
    
    switch(in){
               case 'F':Forward(); break;
               case 'R': Right(); break; 
               case 'S': Stop(); break;
               case 'L': Left(); break;
               case 'B': Back(); break;
               case 'G': ForwardLeft(); break;
               case 'I': ForwardRight(); break;
               case 'H': BackLeft(); break;
               case 'J': BackRight(); break;
             } 
      }  
void Forward(){  
    //  앞
    analogWrite(enablelPin, 150);
    analogWrite(enable2Pin, 150);
    digitalWrite(motor1PinA, LOW);
    digitalWrite(motor1PinB,HIGH);
    digitalWrite(motor2PinA,LOW);
    digitalWrite(motor2PinB,HIGH);
}


void Right(){
    //  오른쪽
    digitalWrite(9, HIGH);  //우회전을 할때 오른쪽 불이 
    analogWrite(enablelPin, 0);
    analogWrite(enable2Pin, 150);
    digitalWrite(motor1PinA, LOW);
    digitalWrite(motor1PinB, LOW);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, HIGH);
    
    
}

    
void Left(){
    //  왼쪽
    digitalWrite(8, HIGH);  //좌회전을 할때 왼쪽 불이 켜진다
    analogWrite(enablelPin, 150);
    analogWrite(enable2Pin, 0);
    digitalWrite(motor1PinA, LOW); 
    digitalWrite(motor1PinB, HIGH);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, LOW);
}


void Stop(){
    //정지
    digitalWrite(9, LOW);  //정지일때 불이 안 들어옴
    digitalWrite(8, LOW); 
    digitalWrite(motor1PinA, LOW);
    digitalWrite(motor1PinB, LOW);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, LOW);
}
     

void Back(){
    //후진
    analogWrite(enablelPin, 150);
    analogWrite(enable2Pin, 150);
    digitalWrite(motor1PinA, HIGH);
    digitalWrite(motor1PinB, LOW);
    digitalWrite(motor2PinA, HIGH);
    digitalWrite(motor2PinB, LOW);
}


void ForwardLeft(){
    //10시30분
    analogWrite(enablelPin, 255);
    digitalWrite(motor1PinA, LOW); 
    digitalWrite(motor1PinB, HIGH);
    analogWrite(enable2Pin, 100); 
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, HIGH);  //모터속도조절은 제일 앞에 놓기 그래야 속도변화가 벅용이 됨
}


void ForwardRight(){
  //1시30분
    analogWrite(enablelPin, 100);
    digitalWrite(motor1PinA, LOW); 
    digitalWrite(motor1PinB, HIGH);
    analogWrite(enable2Pin, 255);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, HIGH);  //모터속도조절은 제일 앞에 놓기 그래야 속도변화가 벅용이 됨
}


void BackLeft(){
  //7시30분
    analogWrite(enablelPin, 255);
    digitalWrite(motor1PinA, HIGH); 
    digitalWrite(motor1PinB, LOW);
    analogWrite(enable2Pin, 100);
    digitalWrite(motor2PinA, HIGH);
    digitalWrite(motor2PinB, LOW);
}


void BackRight(){
  //4시30분
  analogWrite(enablelPin, 100);
    digitalWrite(motor1PinA, HIGH); 
    digitalWrite(motor1PinB, LOW);
    analogWrite(enable2Pin, 255);
    digitalWrite(motor2PinA, HIGH);
    digitalWrite(motor2PinB, LOW);
}
