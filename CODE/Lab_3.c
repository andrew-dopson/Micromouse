/** ###################################################################
**     Filename  : Lab_3.c
**     Project   : Lab_3
**     Processor : MC9S12C32MFA25
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 1/29/2013, 7:02 PM
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Lab_3 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LCD_EN.h"
#include "LCD_RS.h"
#include "MotorR_Drive.h"
#include "MotorR_Enable.h"
#include "MotorL_Drive1.h"
#include "MotorL_Drive2.h"
#include "MotorL_Drive3.h"
#include "MotorL_Drive4.h"
#include "MotorL_Enable1.h"
#include "MotorL_Enable2.h"
#include "Motor1_Timer2.h"
#include "Motor2_Timer2.h"
#include "AD1.h"
#include "TI1.h"
#include "TI2.h"
#include "Err.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
 


/* User includes (#include below this line is not maintained by Processor Expert) */
/*#define ON 1;
#define OFF 0;
*/

void InitializeLCD();
void writeCom(byte command);
void writeData(byte data);
void clearLCD();
void displaySensors(byte sensor1, byte sensor2, byte sensor3);
void pollSensors();
void motorStep(int steps);
void powerMotor(int power);
void Motor1_WriteBits(byte state);
void Motor2_WriteBits(byte state);
void turnLeft() ;
void turnRight() ;
void moveForward();
void turnAround()  ;

byte sensor[3];

byte MotorSeq[8] = {0x01,0x09,0x08,0x0C,0x04,0x06,0x02,0x03};
int stateL;
int stateR; 
int dirL;
int dirR;
int steps;
int wall;

extern int toggle1;
extern int toggle2;

void main(void)
{
  /* Write your local variable definition here */
  int x;
  
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

  
  x = 1; 
  stateL = 0;
  stateR = 0;
  dirL = 1;
  dirR = 1;
  steps = 400;
  wall = 0;
 
  powerMotor(1);
  while(x){
    
    moveForward();
    if(wall){
     turnAround(); 
      wall = 0;
      
    }
 
  }
  
  powerMotor(0);
   
  
  /*
  InitializeLCD();
 

  //Forever loop, polling sensors and displaying
  while(1){
    //Reset at beginning of loop
    clearLCD();

    //Put values into sensor array
    pollSensors();

    //Display values on LCD screen
    displaySensors(sensor[0],sensor[2],sensor[1]);


    Cpu_Delay100US(5000);
  } 
  */



  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

int checkOver()   {
    if(steps > 0){
     return 1; 
      
    } else return 0;
  
  
  
}

void turnRight(){
  int x;
  
  dirL = 0;
  dirR = 1;
  steps = 400;
  x = 1;
  while(x){
   x = checkOver(); 
    
  }
}

void turnLeft(){
  int x;
  
  dirL = 1;
  dirR = 0;
  steps = 400;
  x = 1;
  while(x){
   x = checkOver(); 
    
  }
}

void moveForward(){
  int x;
  

  dirL = 1;
  dirR = 1;
  steps = 400;
  x = 1;
  
  Err_Enable() ;

  while(x){
   pollSensors();
   x = checkOver();
   if (sensor[1] > 100){
    x = 0;
    wall = 1;
   
   }
    
  }
  Err_Disable() ;

}

void turnAround(){
   turnLeft();
   turnLeft(); 
  
  
}



void motorStep(int steps){
  int i = 0;
    
  while (i <= steps){
     
    
     if(stateL == 7){
      stateL =0;
     } 
     else{
      stateL++;
     }
     
     if(stateR == 7){
      stateR = 0;
     } 
     else {
      stateR++; 
     }
      i ++;
     Cpu_Delay100US(40);

   }
  
}

void powerMotor(int power){
 if(power == 1){
    MotorL_Enable1_PutVal(1); 
    MotorL_Enable2_PutVal(1);
    MotorR_Enable_PutVal(1);

  
 }
 else{
    MotorL_Enable1_PutVal(0); 
    MotorL_Enable2_PutVal(0);
    MotorR_Enable_PutVal(0);
  
 }
  
  
}


//LEFT
void Motor1_WriteBits(byte state){
  MotorL_Drive4_PutVal((state&0x01)&&0x01);
  MotorL_Drive3_PutVal((state&0x02)&&0x02);
  MotorL_Drive2_PutVal((state&0x04)&&0x04);
  MotorL_Drive1_PutVal((state&0x08)&&0x08);
         
  
}

//RIGHT
void Motor2_WriteBits(byte state){
  MotorR_Drive_PutVal(state);  
  
}


void pollSensors(){
  AD1_Measure(1);
  AD1_GetValue(sensor);
  
}


void writeCom(byte command){
  //powerMotor(0);
  LCD_EN_PutVal(0);
  LCD_RS_PutVal(0);
  MotorR_Drive_PutVal(command>>4);
  LCD_EN_PutVal(1);


  LCD_EN_PutVal(0);
  MotorR_Drive_PutVal(command);
  LCD_EN_PutVal(1);
  LCD_EN_PutVal(0);
  
  Cpu_Delay100US(1);

}


void InitializeLCD(){
  Cpu_Delay100US(160);
  writeCom(0x30);
  
  Cpu_Delay100US(50);
  writeCom(0x30);
  
  Cpu_Delay100US(2);
  writeCom(0x30);
  writeCom(0x20);
  writeCom(0x28); 
  writeCom(0x0C);
  writeCom(0x01);
  writeCom(0x06);
  Cpu_Delay100US(100);
  
}


void writeData(byte data) {
  LCD_EN_PutVal(0);
  LCD_RS_PutVal(1);
  MotorR_Drive_PutVal(data>>4);
  LCD_EN_PutVal(1); 

  LCD_EN_PutVal(0);
  MotorR_Drive_PutVal(data);
  LCD_EN_PutVal(1);
  LCD_EN_PutVal(0);
  
  Cpu_Delay100US(10);
  
}


void clearLCD(){
  
  writeCom(0x01);
  Cpu_Delay100US(100);
  
}

 
void displaySensors(byte sensor1, byte sensor2, byte sensor3){
  writeCom(0x80); 
  writeData(sensor1/100+48);
  sensor1%=100;
  writeData(sensor1/10+48);
  sensor1%=10;
  writeData(sensor1+48);
  writeData(32);
  writeData(32);
    
  
  writeData(sensor2/100+48);
  sensor2%=100;
  writeData(sensor2/10+48);
  sensor2%=10;
  writeData(sensor2+48);
  writeCom(0xC0);
  writeData(32);
  writeData(32);
  
  
  writeData(sensor3/100+48);
  sensor3%=100;
  writeData(sensor3/10+48);
  sensor3%=10;
  writeData(sensor3+48);
  
  
  
  
}




/* END Lab_3 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/

