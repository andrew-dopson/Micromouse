/** ###################################################################
**     Filename  : Events.c
**     Project   : Lab_3
**     Processor : MC9S12C32MFA25
**     Component : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 1/29/2013, 7:02 PM
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Events */

#include <stdio.h>
#include "Cpu.h"
#include "Events.h"


/* User includes (#include below this line is not maintained by Processor Expert) */
extern void Motor1_WriteBits(byte state);
extern void Motor2_WriteBits(byte state);
extern toggle1;
extern toggle2;
extern byte MotorSeq[8];
extern int stateL;
extern int stateR;
extern int dirL;
extern int dirR;
extern int steps;
extern byte sensor[3];
extern int wall;

#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnEnd(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Motor2_Timer2_OnInterrupt (module Events)
**
**     Component   :  Motor2_Timer2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Motor2_Timer2_OnInterrupt(void)
{
  if (toggle2) {
     Motor2_WriteBits(0);
     toggle2 = 0;
    
  } 
  else {
     Motor2_WriteBits(MotorSeq[stateL]);
     toggle2 = 1;
  }
}

/*
** ===================================================================
**     Event       :  Motor1_Timer2_OnInterrupt (module Events)
**
**     Component   :  Motor1_Timer2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Motor1_Timer2_OnInterrupt(void)
{
   if (toggle1) {
     Motor1_WriteBits(0);
     toggle1 = 0;
    
  } 
  else {
     Motor1_WriteBits(MotorSeq[stateR]);
     toggle1 = 1;
  }
}

/*
** ===================================================================
**     Event       :  TI2_OnInterrupt (module Events)
**
**     Component   :  TI2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI2_OnInterrupt(void)
{
  /* Write your code here ... */
  
  if(dirL){
     if(stateL == 7){
      stateL =0;
     } 
     else{
      stateL++;
     }
    
    
  }
  else {
     if(stateL == 0){
      stateL = 7;
     } 
     else {
      stateL--; 
     }
    
  }
  steps--;
}

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
  if(dirR){
     if(stateR == 7){
      stateR =0;   
      
     } 
     else{
      stateR++;
     }
    
    
  }
  else {
     if(stateR == 0){
      stateR = 7;
     } 
     else {
      stateR--; 
     }
     
  }
  steps--;
}

/*
** ===================================================================
**     Event       :  Err_OnInterrupt (module Events)
**
**     Component   :  Err [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Err_OnInterrupt(void)
{
  int propErr = 0;
  /* Write your code here ... */
   //0 is left, 2 is right, 1 front
   
   //Left 85, right 87 as far away (for now)
   //Mid: left 110, right is 113
  
  //BOTH WALLS
  
  if(sensor[0] > 85 && sensor[2] > 87){
     propErr = sensor[0] - sensor[2];
     
     //Cpu_Delay100US(5000);
     if(propErr > 0){
       TI2_SetPeriodUS(4200); 
       TI1_SetPeriodUS(3800); 
     }
     else{
       TI2_SetPeriodUS(3800);   
       TI1_SetPeriodUS(4200);   
     }  
     
    
  }
  //LEFT WALL
  else if(sensor[0] > 85){
     propErr = (sensor[0] - 110);
  
     if(propErr > 0){
       TI2_SetPeriodUS(4200); 
       TI1_SetPeriodUS(3800); 
     } else{
       TI2_SetPeriodUS(3800); 
       TI1_SetPeriodUS(4200);
      
     }
     
  }
  
  //RIGHT WALL
  else if(sensor[2] > 87){
      propErr = (sensor[2] - 113);
    if(propErr > 0){
       TI2_SetPeriodUS(3800); 
       TI1_SetPeriodUS(4200); 
     } else{
       TI2_SetPeriodUS(4200); 
       TI1_SetPeriodUS(3800);
      
     }
  
    
  } else{
    TI1_SetPeriodUS(4000) ;
    TI2_SetPeriodUS(4000);
    
  }
  
  
   

}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
