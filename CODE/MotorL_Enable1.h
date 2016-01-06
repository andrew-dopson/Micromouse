/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : MotorL_Enable1.h
**     Project   : Lab_3
**     Processor : MC9S12C32MFA25
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.15, CPU db: 2.87.402
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2/19/2013, 7:13 PM
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       1             |  PT0_PWM0_IOC0
**             ----------------------------------------------------
**
**         Port name                   : T
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : $0001
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTT       [$0240]
**         Port control register       : DDRT      [$0242]
**
**         Optimization for            : speed
**     Contents  :
**         SetDir - void MotorL_Enable1_SetDir(bool Dir);
**         GetVal - bool MotorL_Enable1_GetVal(void);
**         PutVal - void MotorL_Enable1_PutVal(bool Val);
**         ClrVal - void MotorL_Enable1_ClrVal(void);
**         SetVal - void MotorL_Enable1_SetVal(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef MotorL_Enable1_H_
#define MotorL_Enable1_H_

/* MODULE MotorL_Enable1. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG MotorL_Enable1_CODE
/*
** ===================================================================
**     Method      :  MotorL_Enable1_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define MotorL_Enable1_GetVal() ( \
    (bool)((getReg8(PTT) & 0x01U))     /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  MotorL_Enable1_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void MotorL_Enable1_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  MotorL_Enable1_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**           a) direction = Input  : sets the output value to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define MotorL_Enable1_ClrVal() ( \
    (void)clrReg8Bits(PTT, 0x01U)      /* PTT0=0x00U */, \
    (Shadow_T &= 0xFEU)                /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  MotorL_Enable1_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**           a) direction = Input  : sets the output value to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define MotorL_Enable1_SetVal() ( \
    (void)setReg8Bits(PTT, 0x01U)      /* PTT0=0x01U */, \
    (Shadow_T |= 0x01U)                /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  MotorL_Enable1_SetDir (component BitIO)
**
**     Description :
**         This method sets direction of the component.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void MotorL_Enable1_SetDir(bool Dir);

#pragma CODE_SEG DEFAULT

/* END MotorL_Enable1. */
#endif /* #ifndef __MotorL_Enable1_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
