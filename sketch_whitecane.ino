//Presented by SSU 3

int vSpeed = 150; // 속도 정의
int turn_speed = 200; // 회전 속도 수치
int turn_delay = 10; // 회전 지연
int stopspeed = 0; 
int sensor1 = 0; // 적외선 거리센서 1
int sensor2 = 1; // 적외선 거리센서 2
int sensor3 = 2; // 적외선 거리센서 3
int val = 0; // 적외선 센서 정의
int val2 = 0; // 적외선 센서 정의
int val3 = 0; // 적외선 센서 정의
const int motorA1 = 3; //모터 정의 부분
const int motorA2 = 4; 
const int motorAspeed = 5; // 모터 A 속도
const int motorB1 = 8; 
const int motorB2 = 6; 
const int motorBspeed =7; // 모터 B 속도
const int left_sensor_pin =9; //라인 트레이서 1
const int right_sensor_pin =10; // 라인 트레이서 2
int left_sensor_state;
int right_sensor_state;
int cds = A3; //조도 센서
int led = 2; //led

void setup() {
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
pinMode(12, INPUT);
pinMode(led, OUTPUT);

Serial.begin(9600);

}

void loop() {

val = analogRead(sensor1); 
val2 = analogRead(sensor2); 
val3 = analogRead(sensor3); 
int v = digitalRead(12); // 터치 센서
int cdsValue = analogRead(cds);
left_sensor_state = digitalRead(left_sensor_pin);
right_sensor_state = digitalRead(right_sensor_pin);
if( v == 0){ //터치센서에 인식이 될 경우, 이 경우 안에 직진과 회피코드 모두 포함이 되어 있음.=

//cdsValue는 조도센서
if( cdsValue > 400){ //조도센서 수치가 400 초과일 때
digitalWrite(led, HIGH); //LED 전원 ON
}
if( cdsValue <= 400){ //조도센서 수치가 400 이하일 때
digitalWrite(led, LOW); //LED 전원 OFF
}
if(val >= 400 || val2 >= 400 || val3 >= 400){ //세 적외선 거리센서 중 한 센서라도 장애물이 감지된다면


if( cdsValue > 400){ //조도센서 수치가 400 초과일 때
digitalWrite(led, HIGH); //LED 전원 ON
}
if( cdsValue <= 400){ //조도센서 수치가 400 이하일 때
digitalWrite(led, LOW); //LED 전원 OFF
}
//모터 회전, 오른쪽
digitalWrite (motorA1,LOW);
digitalWrite(motorA2,HIGH); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, turn_speed);
analogWrite (motorBspeed, vSpeed);
delay(3000);

//모터 직진
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, vSpeed);
delay(3000);

//모터 회전, 왼쪽
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,LOW);
digitalWrite(motorB2,HIGH);
analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, turn_speed);
delay(3000);

//모터 직진
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, vSpeed);
delay(3000);

//모터 회전, 왼쪽
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,LOW);
digitalWrite(motorB2,HIGH);

analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, turn_speed);
delay(3000);

//모터 직진
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, vSpeed);
delay(3000);

//모터 회전, 오른쪽
digitalWrite (motorA1,LOW);
digitalWrite(motorA2,HIGH); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, turn_speed);
analogWrite (motorBspeed, vSpeed);
delay(3000);

//모터 직진
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, vSpeed);
delay(3000);



}

if(val < 400 && val2 < 400 && val3 < 400){ //만약 장애물이 없다면, 즉 평소의 상태


if( cdsValue > 400){ //조도센서 수치가 400 초과라면
digitalWrite(led, HIGH); //LED 전원 ON
}
if( cdsValue <= 400){ //조도센서 수치가 400 이하라면
digitalWrite(led, LOW); //LED 전원 OFF
}

if(right_sensor_state == HIGH && left_sensor_state == LOW)
{
//오른쪽 회전
digitalWrite (motorA1,LOW);
digitalWrite(motorA2,HIGH); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, turn_speed);
analogWrite (motorBspeed, vSpeed);

}
if(right_sensor_state == LOW && left_sensor_state == HIGH)
{
//왼쪽 회전
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,LOW);
digitalWrite(motorB2,HIGH);

analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, turn_speed);

}

else if(right_sensor_state == HIGH && left_sensor_state == HIGH)
{ //두 라인트레이서 전부 흰색일 경우 모터 정지

analogWrite (motorAspeed, stopspeed);
analogWrite (motorBspeed, stopspeed);


}

else if(right_sensor_state == LOW && left_sensor_state == LOW)
{ 
//두 라인트레이서 전부 검은색일 경우 직진
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

analogWrite (motorAspeed, vSpeed);
analogWrite (motorBspeed, vSpeed);

}

}

}



if(v == 1){ //터치 센서에 인식이 되지 않는 경우
//모터 멈춤
digitalWrite (motorA1,HIGH);
digitalWrite(motorA2,LOW); 
digitalWrite (motorB1,HIGH);
digitalWrite(motorB2,LOW);

digitalWrite(led, LOW); // led 전원 끄기

analogWrite (motorAspeed, stopspeed);
analogWrite (motorBspeed, stopspeed);
delay(turn_delay);

}

}
