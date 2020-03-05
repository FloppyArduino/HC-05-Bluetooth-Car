/*
 * ECSS STEM car for Science fair
 * Feb 2020
 * Coded by: Vincenzo L
 * Team Members: Vincenzo L(me),David A, Matthew G, Byron Z
 */

int Drive=255, Turn =125 ;

int Received=0;//store ascii num value from BT
//-------Driving states--------//
int F =0;
int FL =0;
int FR =0;
int B =0;
int BL =0;
int BR =0;
int L =0;
int R =0;

//---------------------------Pins---------------------------// 
//----motors for driving----//
  int motor[]={6,9,2,3,4,5};//EnA,EnB,in1,in2,in3,in4 EnA&B used to control speed


void setup(){
  Serial.begin(9600);
  //setting pin modes
  pinMode(motor[0],OUTPUT);
  pinMode(motor[1],OUTPUT);
  pinMode(motor[2],OUTPUT);
  pinMode(motor[3],OUTPUT);
  pinMode(motor[4],OUTPUT);
  pinMode(motor[5],OUTPUT);
}
//------------------------------BOT DRIVING MOVING CONTROLS------------------------//
void MoveFoward(int driveSpeed){
  //Move Foward inA1 and inB2
  Serial.println("Foward");
  analogWrite(motor[0],driveSpeed);//Motor A
  analogWrite(motor[1],driveSpeed);//Motor B
  digitalWrite(motor[2],HIGH);
  digitalWrite(motor[3],LOW);
  digitalWrite(motor[4],HIGH);
  digitalWrite(motor[5],LOW);
}
void MoveBack(int driveSpeed){
  //Move back inA2 and inB1
  Serial.println("Backwards");
  analogWrite(motor[0],driveSpeed);//Motor A
  analogWrite(motor[1],driveSpeed);//Motor B
  digitalWrite(motor[2],LOW);
  digitalWrite(motor[3],HIGH);
  digitalWrite(motor[4],LOW);
  digitalWrite(motor[5],HIGH);
}
void TurnLeft(int turnSpeed, int driveSpeed,int motorDir){
  switch(motorDir){
  case 1://foward
    Serial.println("Left Foward");
    analogWrite(motor[0],driveSpeed-turnSpeed);//Motor A
    analogWrite(motor[1],driveSpeed);//Motor B
    digitalWrite(motor[2],HIGH);
    digitalWrite(motor[3],LOW);
    digitalWrite(motor[4],HIGH);
    digitalWrite(motor[5],LOW);
  break;
  case 0://back
    Serial.println("Left Backwards");
    analogWrite(motor[0],driveSpeed-turnSpeed);//Motor A
    analogWrite(motor[1],driveSpeed);//Motor B
    digitalWrite(motor[2],LOW);
    digitalWrite(motor[3],HIGH);
    digitalWrite(motor[4],LOW);
    digitalWrite(motor[5],HIGH);
  break;
  }
}

void TurnRight(int turnSpeed, int driveSpeed,int motorDir){
  switch(motorDir){
    case 1://foward
      Serial.println("Right Foward");
      analogWrite(motor[0],driveSpeed);//Motor A
      analogWrite(motor[1],driveSpeed-turnSpeed);//Motor B
      digitalWrite(motor[2],HIGH);
      digitalWrite(motor[3],LOW);
      digitalWrite(motor[4],HIGH);
      digitalWrite(motor[5],LOW);
    break;
    case 0://back
      Serial.println("Right Backwards");
      analogWrite(motor[0],driveSpeed);//Motor A
      analogWrite(motor[1],driveSpeed-turnSpeed);//Motor B
      digitalWrite(motor[2],LOW);
      digitalWrite(motor[3],HIGH);
      digitalWrite(motor[4],LOW);
      digitalWrite(motor[5],HIGH);
    break;
  }
}

void StopAllMotors(){
  Serial.println("STOP");
  analogWrite(motor[0],0);// Motor A
  analogWrite(motor[1],0);//Motor B
  for(int t=2;t<6;t++){
  digitalWrite(motor[t],LOW);
  }
}

void  pivLeft(int driveSpeed){
  Serial.println("Left Turn");
  analogWrite(motor[0],driveSpeed);//Motor A
  analogWrite(motor[1],driveSpeed);//Motor B
  digitalWrite(motor[2],HIGH);
  digitalWrite(motor[3],LOW);
  digitalWrite(motor[4],LOW);
  digitalWrite(motor[5],HIGH);
}
void  pivRight(int driveSpeed){
  Serial.println("Right Turn");
  analogWrite(motor[0],driveSpeed);//Motor A
  analogWrite(motor[1],driveSpeed);//Motor B
  digitalWrite(motor[2],LOW);
  digitalWrite(motor[3],HIGH);
  digitalWrite(motor[4],HIGH);
  digitalWrite(motor[5],LOW);
}
//-------------------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------------------//
void loop(){

 if(Serial.available()>0){ //if serial data is available
    Received = Serial.read();//read all data
     Serial.println(Received);//print data values 
 }else{
  //Serial.println("None");
 }
    

//----------------------------foward controls---------------------------//
if (F == 0 && Received == 70 )
  {
    MoveFoward(Drive);//calls drive foward method and num is the drive speed
    F=1;
    Received=0;  
  }
if (F ==1 && Received == 70)
  {
    StopAllMotors();//calls MotorStop block to stop all motors
    F=0;
    Received=0;
  }

//-------------------------------------------------------------------// 
if (FL == 0 && Received == 49)
  {
    TurnLeft(Turn,Drive,1);//calls TurnLeft block with 1st num for turn speed and 2nd num for drive speed and 3rd is for direction(0=back 1=foward)
    FL=1;
    Received=0;  
  }
if (FL ==1 && Received == 49)
  {
    StopAllMotors();//calls MotorStop block to stop all motors
    FL=0;
    Received=0;
  }
//-------------------------------------------------------------------// 
if (FR == 0 && Received == 76)
  {
    TurnRight(Turn,Drive,1);//calls TurnRight block with 1st num for turn speed and 2nd num for drive speed 3rd is for direction(0=back 1=foward)
    FR=1;
    Received=0;  
  }
if (FR ==1 && Received == 76)
  {
    StopAllMotors();//calls MotorStop block to stop all motors
    FR=0;
    Received=0;
  }
//----------------------------backwards controls---------------------------//
if (BR == 0 && Received == 82)
  {
    TurnRight(Turn,Drive,0);//calls TurnRight block with 1st num for turn speed and 2nd num for drive speed 3rd is for direction(0=back 1=foward)
    BR=1;
    Received=0;  
  }
if (BR ==1 && Received == 82)
  {
    StopAllMotors();//calls MotorStop block to stop all motors
    BR=0;
    Received=0;
  }
//-------------------------------------------------------------------//
if (BL == 0 && Received == 66)
  {
    TurnLeft(Turn,Drive,0);//calls TurnRight block with 1st num for turn speed and 2nd num for drive speed 3rd is for direction(0=back 1=foward)
    BL=1;
    Received=0;  
  }
if (BL ==1 && Received == 66)
  {
    StopAllMotors();//calls MotorStop block to stop all motors
    BL=0;
    Received=0;
  }
//-------------------------------------------------------------------//  

if (B == 0 && Received == 52 )
  {
    MoveBack(Drive);//calls drive foward method and num is the drive speed
    B=1;
    Received=0;  
  }
if (B ==1 && Received == 52)
  {
    StopAllMotors();//calls MotorStop block to stop all motors
    B=0;
    Received=0;
  }
//-------------------------------------------------------------------// 
//-----------------------onspot turns------------------------------// 
if(L==0 && Received==51){
  pivLeft(Drive);
  L=1;
  Received=0;
}
if(L==1 && Received==51){
  StopAllMotors();
  L=0;
  Received=0;
}
//-------------------------------------------------------------------//
if(R==0 && Received==50){
  pivRight(Drive);
  R=1;
  Received=0;
}
if(R==1 && Received==50){
  StopAllMotors();
  R=0;
  Received=0;
}
}



