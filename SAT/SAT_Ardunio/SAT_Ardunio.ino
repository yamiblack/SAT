#include <LiquidCrystal.h>
#include <Stepper.h>

//lcd핀 설정
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

//led핀 설정
const int ledR = 19;
const int ledG = 18;
const int ledB = 17;

//초음파 센서핀 설정
const char trigPin=7;
const char echoPin=6;

//스텝모터핀 설정
Stepper stepper(2048,5,3,4,2);
//초음파 센서 변수 설정
int pulseWidth;
double distance;
double maxdistance = 42.0; // 휴지통의 높이
double outputdistance; // 현재 쓰레기양
double percent; //현재 채워진 양%

//모터관련변수
int n = 1; //바퀴 수 설정
int rotation = n*2048; // 돌릴 바퀴 수

void setup() {
// 16*2 lcd 센서 사용
  lcd.begin(16,2); 
// 초음파센서 설정
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
// RGB핀 설정
  pinMode(ledR, OUTPUT);  
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
//스텝모터 속도 설정
  stepper.setSpeed(10);
//현재 쓰레기량 측정
  outputdistance = getDistance(); 
}

void loop() {
//RGB led 출력메소드
  rgbLed();
//lcd에 현재 채워진 양 %로 나타내기
  lcd.setCursor(0,0);
  lcd.print(percent);
  lcd.print(" %"); 
//현재 채워진 양%
  percent = (maxdistance-outputdistance)/maxdistance*100; 
//쓰레기통이 열렸다가 닫히면 압축 및 출력값 최신화
  if(getDistance()>maxdistance){
    while(true){
      if(getDistance()<maxdistance){
      delay(3000);
//스텝모터 가동 메소드
      push();
//현재 쓰레기양 측정
      outputdistance = getDistance();
      break;
     }    
    }
  }
}

//스텝모터 가동 메소드
void push(){
//시계 방향으로 돌린다
  stepper.step(rotation);
  delay(1000);
//반시계 방향으로 돌린다
  stepper.step(-rotation);
  delay(1000);
}

// RGB led 출력 메소드 
void ledOutput(int Red, int Green, int Blue){
  analogWrite(ledR,Red);
  analogWrite(ledG,Green);
  analogWrite(ledB,Blue);
}
// 색 표현 메소드
void greenOutput(){
  ledOutput(0,255,0); // 녹색
}
void yellowOutput(){
  ledOutput(255,100,0); //황색
}
void redOutput(){
  ledOutput(255,0,0); //빨간색
}
//쓰래기양에 비례하여 RGB색 표현 메소드
void rgbLed(){
// 60%까지는 녹색
    if(percent<=60.0&&percent>=0.0){
      greenOutput();
    }
//60%~90%까지는 황색
    else if(percent>60.0&&percent<90.0){
      yellowOutput();
    }
//90%~ 빨간색
    else {
      redOutput();
    }
}
//거리 최신화 메소드 거리(cm) 리턴
double getDistance(){
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pulseWidth = pulseIn(echoPin,HIGH);
  return pulseWidth / 58;  // cm단위로 표기
}
