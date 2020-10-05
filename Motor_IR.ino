#define echopin A4 // echo pin
#define trigpin A5 // Trigger pin


// Motor A, Left Side
const uint8_t pwmLeft = 4;      // ENA - Enable and PWM
const uint8_t leftForward = 5;  // IN1 - Forward Drive
const uint8_t leftReverse = 6;  // IN2 - Reverse Drive
 
// Motor B, Right Side
const uint8_t pwmRight = 9;     // ENB - Enable and PWM
const uint8_t rightForward = 7; // IN3 - Forward Drive
const uint8_t rightReverse = 8; // IN4 - Reverse Drive

int speed = 115;
int R_S = A1; //sincer R
int test = 0;


int  frontdist;
long duration;

int setdist= 10;

//int L_S = A0; //sincer L
void setup(){

 pinMode(pwmLeft, OUTPUT);
 pinMode(leftForward, OUTPUT);
 pinMode(leftReverse, OUTPUT);
 pinMode(pwmRight, OUTPUT);
 pinMode(rightForward, OUTPUT);
 pinMode(rightReverse, OUTPUT);
  
 pinMode (trigpin, OUTPUT);
 pinMode (echopin, INPUT);
 
 //pinMode(L_S, INPUT);
 pinMode(R_S, INPUT);



 Serial.begin(9600);
 delay(1000);
 }

void loop(){
frontdist = data();
//Serial.println(frontdist); 
test = (digitalRead(R_S));
Serial.println(test); 


//if(frontdist>setdist){
if ((test == 0)){allForward();delay(1000);}
if ((test == 1)){allStop();delay(1000);}
//if ((digitalRead(R_S) == 0)){skidsteerLeft();delay(1000);}
//}
else{

// allStop();  // Stop all dc motors
// delay(1000);
// allForward(); // Drive dc motors forward
// delay(2000);
// allReverse(); // Drive dc motors in reverse
// delay(2000);
// skidsteerLeft();  // Skidsteer spin left direction
// delay(2000);
// skidsteerRight(); // Skidsteer spin right direction
// delay(2000);

}

}

long data(){
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 duration=pulseIn (echopin,HIGH);
 return duration / 29 / 2; 
}

//////////////// Start Functions //////////////////
 
// All Stop
void allStop() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 0);
  analogWrite(pwmRight, 0);
}
 
void allForward() {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
}
 
void allReverse() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, HIGH);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
}
 
void skidsteerLeft() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftReverse, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightReverse, LOW);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
}
 
void skidsteerRight() {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftReverse, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightReverse, HIGH);
  analogWrite(pwmLeft, 255);
  analogWrite(pwmRight, 255);
}
