/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TI1.h
**     Project   : Lab_3
**     Processor : MC9S12C32MFA25
**     Component : TimerInt
**     Version   : Component 02.159, Driver 01.20, CPU db: 2.87.402
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 3/5/2013, 8:19 PM
**     Abstract  :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings  :
**         Timer name                  : TIM_Counter (16-bit)
**         Compare name                : TC2
**         Counter shared              : Yes
**
**         High speed mode
**             Prescaler               : divide-by-32
**             Clock                   : 750000 Hz
**           Initial period/frequency
**             Xtal ticks              : 32000
**             microseconds            : 4000
**             milliseconds            : 4
**             seconds (real)          : 0.004
**             Hz                      : 250
**
**         Runtime setting             : period/frequency interval (continual setting)
**             ticks                   : 16000 to 48000 ticks
**             microseconds            : 2000 to 6000 microseconds
**             milliseconds            : 2 to 6 milliseconds
**             seconds (real)          : 0.002 to 0.006 seconds
**             Hz                      : 167 to 500 Hz
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TCNT      [$0044]
**              Mode                   : TIOS      [$0040]
**              Run                    : TSCR1     [$0046]
**              Prescaler              : TSCR2     [$004D]
**
**         Compare registers
**              Compare                : TC2       [$0054]
**
**         Flip-flop registers
**              Mode                   : TCTL2     [$0049]
**     Contents  :
**         SetPeriodTicks16 - byte TI1_SetPeriodTicks16(word Ticks);
**         SetPeriodTicks32 - byte TI1_SetPeriodTicks32(dword Ticks);
**         SetPeriodUS      - byte TI1_SetPeriodUS(word Time);
**         SetPeriodMS      - byte TI1_SetPeriodMS(word Time);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TI1
#define __TI1

/* MODULE TI1. */

#include "Cpu.h"

#pragma CODE_SEG TI1_CODE

#define TI1_SPT16_MIN        0x3E80U   /* Lower bound of interval for method SetPeriodTicks16 */
#define TI1_SPT16_MAX        0xBB80U   /* Upper bound of interval for method SetPeriodTicks16 */
#define TI1_SPT32_MIN        0x3E80UL  /* Lower bound of interval for method SetPeriodTicks32 */
#define TI1_SPT32_MAX        0xBB80UL  /* Upper bound of interval for method SetPeriodTicks32 */
#define TI1_SPUS_MIN         0x07D0U   /* Lower bound of interval for method SetPeriodUS */
#define TI1_SPUS_MAX         0x1770U   /* Upper bound of interval for method SetPeriodUS */
#define TI1_SPMS_MIN         0x02U     /* Lower bound of interval for method SetPeriodMS */
#define TI1_SPMS_MAX         0x06U     /* Upper bound of interval for method SetPeriodMS */
/* Deprecated constants, for backward compatibility */
#define TI1_SPT16Min         0x3E80U   /* Deprecated. Lower bound of interval for method SetPeriodTicks16 */
#define TI1_SPT16Max         0xBB80U   /* Deprecated. Upper bound of interval for method SetPeriodTicks16 */
#define TI1_SPT32Min         0x3E80UL  /* Deprecated. Lower bound of interval for method SetPeriodTicks32 */
#define TI1_SPT32Max         0xBB80UL  /* Deprecated. Upper bound of interval for method SetPeriodTicks32 */
#define TI1_SPUSMin          0x07D0U   /* Deprecated. Lower bound of interval for method SetPeriodUS */
#define TI1_SPUSMax          0x1770U   /* Deprecated. Upper bound of interval for method SetPeriodUS */
#define TI1_SPMSMin          0x02U     /* Deprecated. Lower bound of interval for method SetPeriodMS */
#define TI1_SPMSMax          0x06U     /* Deprecated. Upper bound of interval for method SetPeriodMS */


byte TI1_SetPeriodTicks16(word Ticks);
/*
** ===================================================================
**     Method      :  TI1_SetPeriodTicks16 (component TimerInt)
**
**     Description :
**         This method sets the new period of the generated events.
**         The period is expressed in main oscillator (usualy External
**         osc., internal osc. if exits and external osc. is disabled)
**         ticks as a 16-bit unsigned integer number.
**         This method is available only if the runtime setting type
**         'from interval' is selected in the Timing dialog box in
**         the Runtime setting area.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ticks           - Period to set [in Xtal ticks]
**                      (16000 to 48000 ticks)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

byte TI1_SetPeriodTicks32(dword Ticks);
/*
** ===================================================================
**     Method      :  TI1_SetPeriodTicks32 (component TimerInt)
**
**     Description :
**         This method sets the new period of the generated events.
**         The period is expressed in main oscillator (usualy External
**         osc., internal osc. if exits and external osc. is disabled)
**         ticks as a 32-bit unsigned integer number.
**         This method is available only if the runtime setting type
**         'from interval' is selected in the Timing dialog box in
**         the Runtime setting area.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ticks           - Period to set [in Xtal ticks]
**                      (16000 to 48000 ticks)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

byte TI1_SetPeriodUS(word Time);
/*
** ===================================================================
**     Method      :  TI1_SetPeriodUS (component TimerInt)
**
**     Description :
**         This method sets the new period of the generated events.
**         The period is expressed in microseconds as a 16-bit
**         unsigned integer number.
**         This method is available only if the runtime setting type
**         'from interval' is selected in the Timing dialog box in
**         the Runtime setting area.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Period to set [in microseconds]
**                      (2000 to 6000 microseconds)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

byte TI1_SetPeriodMS(word Time);
/*
** ===================================================================
**     Method      :  TI1_SetPeriodMS (component TimerInt)
**
**     Description :
**         This method sets the new period of the generated events.
**         The period is expressed in miliseconds as a 16-bit
**         unsigned integer number.
**         This method is available only if the runtime setting type
**         'from interval' is selected in the Timing dialog box in
**         the Runtime setting area.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Period to set [in miliseconds]
**                      (2 to 6 milliseconds)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

void TI1_Init(void);
/*
** ===================================================================
**     Method      :  TI1_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void TI1_Interrupt(void);
/*
** ===================================================================
**     Method      :  TI1_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END TI1. */

#endif /* ifndef __TI1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/