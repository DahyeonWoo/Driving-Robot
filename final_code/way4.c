//
//  main.c
//  adventure
//
//  Created by 우다현 on 2020/11/13.
//

#pragma config(Sensor, S2,    color,    sensorEV3_Color)
#pragma config(Motor, motorB,    left, tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor, motorC,    right, tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard   !!*//

task main()
{
   while(1)
   {
      writeDebugStreamLine("%d", SensorValue[S2]);
      writeDebugStream("%d",SensorValue[S2]);

      if(SensorValue[S2]>70)
      {
        motor[motorB]=29;
        motor[motorC]=-21;
      }
      else if(SensorValue[S2]<=70){
        motor[motorB]=-21;
        motor[motorC]=29;
      }
      else if(SensorValue[S2]>90){ //  ? ? <?L
        motor[motorB]=50;
        motor[motorC]=0;
      }
     else if(SensorValue[S2]<30){ //X ? ? <? L
        motor[motorB]=0;
        motor[motorC]=50;
      }
      
   }
}

#include "NXCDefs.h"
#define Forward OnFwd(OUT_AC,27);
#define Back OnRev(OUT_AC,50);
#define Left OnFwd(OUT_A,65);OnRev(OUT_C,55);
#define Right OnFwd(OUT_C,60);OnRev(OUT_A,50);
//수정의 편의성을 위해 기본 주행에 사용되는 코드는 매크로 상수로 사용


task main(){
    
    /*
     SetSensorLight(IN_1);
     SetSensorColorFull(IN_2);
     SetSensorLowspeed(IN_3);
     SetSensorLight(IN_4);
     SetSensorType(IN_1,IN_TYPE_LIGHT_ACTIVE);
     SetSensorType(IN_4,IN_TYPE_LIGHT_ACTIVE);
     */


    while(true){

    if(Sensor(IN_2)<=4 && Sensor(IN_2)>=2){   //컬러 센서 장애물을 인지 -> 장애물을 잡음
     Off(OUT_AC); //정지
     Wait(100);
     OnRev(OUT_B,15); // 집게로 물체 잡음
     Wait(1000);

     while(true){

     if((Sensor(IN_2)==2 || Sensor(IN_2)==3||Sensor(IN_2)==6)&&Sensor(IN_1)<44&&Sensor(IN_4)<44)
     {  while(true){
        Off(OUT_ABC);
        Wait(100000);}}//컬러센서가 파란색 감지하고 양쪽 센서가 검정색 감지시 주차

     if(Sensor(IN_1)>44 && Sensor(IN_4)>44)
                  {Forward;}//직진
     if(Sensor(IN_1)<44 && Sensor(IN_4)>44)
                  {Right;}//우회전
     if(Sensor(IN_1)>44 && Sensor(IN_4)<44)
                  {Left;}//좌회전
     if(Sensor(IN_1)<44&& Sensor(IN_4)<44)
                  {Left;}//좌회전

     if(Sensor(IN_2)<=4 && Sensor(IN_2)>=2&&SensorUS(IN_3)<=22&&SensorUS(IN_3)>=7)
     {    //장애물을 잡은 상태에서 벽 가까워짐 -> 장애물을 놓고 유턴
         Off(OUT_AC); //정지
         Wait(100);
         OnFwd(OUT_B,15); //물체 놓음
         Wait(100);
         OnRev(OUT_AC,30);//후진
         Wait(1300);
         OnFwd(OUT_A,50);
         OnRev(OUT_C,50);// 회전
         Wait(800);
         Back; //좀 더 빠르게 후진
         Wait(800);
         break;//while 문 종료
     }


     }
     }


        if((Sensor(IN_2)==2 || Sensor(IN_2)==3||Sensor(IN_2)==6)&&Sensor(IN_1)<44&&Sensor(IN_4)<44)
     {  while(true){
        Off(OUT_ABC);
        Wait(100000);}}//컬러센서가 파란색 감지하고 양쪽 센서가 검정색 감지시 주차
        if(Sensor(IN_1)>44 && Sensor(IN_4)>44)
                  {Forward;}//직진
        if(Sensor(IN_1)<44 && Sensor(IN_4)>44)
                  {Right;}//우회전
        if(Sensor(IN_1)>44 && Sensor(IN_4)<44)
                  {Left;}//좌회전
        if(Sensor(IN_1)<44&& Sensor(IN_4)<44)
                  {Left;}//좌회전
}
}





#include"NXCDefs.h"
sub cross(int color,int num)//빛센서 두개 모두가 검은색으로 인지 될때
{
 if(num==1)//첫번째로 인지될때 좌회전
 {
  TextOut(16,21,"num:");
  NumOut(20,21,num);
  RotateMotor(OUT_AC,-40,200);
  RotateMotor(OUT_C,60,700);
 }
 else if(num==2)//두번째로 인지될때 좌회전
 {
  NumOut(20,21,num);
  RotateMotor(OUT_AC,-40,130);
  RotateMotor(OUT_C,60,600);
 }
 else if(num==3)//세번째로 인지될때 우회전
 {
  NumOut(20,21,num);
  OnFwd(OUT_C,-30);
  RotateMotor(OUT_A,60,270);
 }
 else if(num==4)//네번째로 인지될때 자회전
 {
  NumOut(20,21,num);
  RotateMotor(OUT_AC,-50,50);
  RotateMotor(OUT_C,60,180);
 }
 else if(num==5)//다섯번째로 인지될대 좌회전
 {
 NumOut(20,21,num);
  RotateMotor(OUT_AC,-70,30);
  RotateMotor(OUT_C,60,210);
 }

 else if(num==6)//여섯번째로 인지될때 직진
 {
 NumOut(20,21,num);
 RotateMotor(OUT_A,80,150);
 OnFwd(OUT_C,-10);

 }
 else if(num==7)//일곱번째로 인지될 때 좌회전
 {
 NumOut(20,21,num);
 RotateMotor(OUT_AC,-50,50);
  RotateMotor(OUT_C,60,180);
 }
else if(num==8)//여덟번째로 인지 될 때 우회전
 {
 NumOut(20,21,num);
 OnFwd(OUT_C,-30);
  RotateMotor(OUT_A,60,270);
 }
else if(num==9)//아홉번째로 인지 될때 좌회전
 {
 NumOut(20,21,num);
 RotateMotor(OUT_AC,-50,50);
  RotateMotor(OUT_C,60,180);
 }
 else if(num==10)//열번째로 인지 될때 좌회전
 {NumOut(20,21,num);
 RotateMotor(OUT_AC,-50,50);
  RotateMotor(OUT_C,60,180);
  }
 else if(num==11)//열한번째로 인지 될때 좌회전
 {NumOut(20,21,num);
 RotateMotor(OUT_AC,-50,50);
  RotateMotor(OUT_C,60,180);
 }
 else if(num==12)//열두번째로 인지 될때 우회전
 {OnFwd(OUT_C,-30);
  RotateMotor(OUT_A,60,270);
 }
 else if(num==13)//열세번째로 인지 될때 좌회전
 {NumOut(20,21,num);
 RotateMotor(OUT_AC,-50,50);
  RotateMotor(OUT_C,60,180);
  }
  else if(num==14)//열네번째로 인지 될때 좌회전
  {NumOut(20,21,num);
 RotateMotor(OUT_AC,-50,50);
  RotateMotor(OUT_C,60,180);
  }
  else if(num==15)//열다섯번째로 인지 될때 멈춤
{ NumOut(20,21,num);
  RotateMotor(OUT_B,70,-60);
  Off(OUT_AC);
  }
}


task main()
{
 int light1,light2,num1=1,num2=0;//빛센서값을 저장할 변수 light1,2와 횟수들을 저장할 num1,2를 선언
 int color,distance;//칼라센서를 저장할 변수 color와 초음파 센서값을 저장할 변수 distance선언
 SetSensorLight(IN_1);
 SetSensorType(IN_1,IN_TYPE_LIGHT_ACTIVE);
 SetSensorLight(IN_2);
 SetSensorType(IN_2,IN_TYPE_LIGHT_ACTIVE);
 SetSensorColorFull(IN_3);
 SetSensorLowspeed(IN_4);//1,2,3,4 port에 연결된  모든 sensor 작동,1,2 port에 연결된 light sensor LED on.
 while(true)
 {
  light1=Sensor(IN_1);
  light2=Sensor(IN_2);
  color=Sensor(IN_3);
  distance=SensorUS(IN_4);
  NumOut(30,31,light1);
  NumOut(10,11,light2);
  NumOut(80,81,num2);//확인을 위한 num2값 출력 .
  if(light1>45&&light2>45)
  {
  OnFwd(OUT_A,20);
  OnFwd(OUT_C,40);
                 ;
  }//양 light sensor의 sensor value가 43이상일 때 전진한다.
  else if(light1<=45&&light2>45)
  {
  OnFwd(OUT_A,-70);
  OnFwd(OUT_C,90);
  }//왼쪽light sensor이 검정색이 되면 좌회전
  else if(light1>45&&light2<=45)
  {
  OnFwd(OUT_A,90);
  OnFwd(OUT_C,-70);
  }//오른쪽light sensor이 검정색이 되면 우회전
  else
  {
   cross(color,num1);//양 쪽이 검정을 인식할시 cross함수를 실행.
   num1++;//실행 횟수를 알 수 있는 변수.
   }
   //motor 구동//

 if(color==4)//color sensor가 노란색을 인식하여 4라는 value일 때 .
  {
   if(num2<1)
   {
   RotateMotor(OUT_B,60,50); //집게 작동 .
   num2++;
   }
   else
   OnFwd(OUT_B,10);//잡은 장애물을 계속 잡음.
  }
 if(color==2)//color sensor가  파란색을 인식하여 2라는 value일때
 {
  RotateMotor(OUT_B,70,60); //집게 작동 .
  OnFwd(OUT_B,10);//잡은 장애물을 계속 잡음.
 }
 if(num1==6&&light1<=45&&light2>45)
 {
 OnFwd(OUT_A,-20);
 OnFwd(OUT_C,40);
 }
 if(num1==12&&light1<=45&&light2>45)
 {OnFwd(OUT_A,-20);
 OnFwd(OUT_C,40);
 }

  if(distance<20)//벽을 판별 후 장애물을 놓고 회전.
     {
     RotateMotor(OUT_B,70,-60);
     RotateMotor(OUT_AC,50,-360);
     RotateMotor(OUT_C,50,360);
     RotateMotor(OUT_A,-50,360);
     RotateMotor(OUT_C,50,360);
     RotateMotor(OUT_AC,50,-210);
     num2=0;//다음 번 노란색을 만났을 경우를 위해 num2값을 다시 0으로 초기화시킨다..
     }
  }
 }




