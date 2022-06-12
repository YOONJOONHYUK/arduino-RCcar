
int motor1PinA  = 2 ;
int motor1PinB =3 ;
int enablelPin=  11 ; 
int motor2PinA  = 4 ;
int motor2PinB =5 ;
int enable2Pin=  10 ; 

  void setup() {
     pinMode(motor1PinA, OUTPUT);     
     pinMode(motor1PinB, OUTPUT);
     pinMode(enablelPin, OUTPUT);
     pinMode(motor2PinA, OUTPUT);     
     pinMode(motor2PinB, OUTPUT);
     pinMode(enable2Pin, OUTPUT);
     analogWrite(enablelPin, 100);
     analogWrite(enable2Pin, 100);//모터속도를 정해준다
  }
   void loop() {
     digitalWrite(motor1PinA, LOW);    //1시 30분
     digitalWrite(motor1PinB, LOW);
     analogWrite(enablelPin, 100);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
     analogWrite(enable2Pin, 100);
     delay(1000);

     digitalWrite(motor1PinA, LOW);     //전진
     digitalWrite(motor1PinB, HIGH);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
     delay(1000);

     digitalWrite(motor1PinA, LOW);    //180도 회전
     digitalWrite(motor1PinB, LOW);
     analogWrite(enablelPin, 200);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
     analogWrite(enable2Pin, 200);
     delay(1000);


     digitalWrite(motor1PinA, LOW);     //전진
     digitalWrite(motor1PinB, HIGH);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
     delay(1000);


     
     
     digitalWrite(motor1PinA, LOW);     //정지
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
     delay(1000);
     }
