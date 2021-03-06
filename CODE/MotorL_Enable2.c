/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : MotorL_Enable2.c
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
**                       2             |  PT1_PWM1_IOC1
**             ----------------------------------------------------
**
**         Port name                   : T
**
**         Bit number (in port)        : 1
**         Bit mask of the port        : $0002
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
**         SetDir - void MotorL_Enable2_SetDir(bool Dir);
**         GetVal - bool MotorL_Enable2_GetVal(void);
**         PutVal - void MotorL_Enable2_PutVal(bool Val);
**         ClrVal - void MotorL_Enable2_ClrVal(void);
**         SetVal - void MotorL_Enable2_SetVal(void);
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE MotorL_Enable2. */

#include "MotorL_Enable2.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG MotorL_Enable2_DATA   /* Select data segment "MotorL_Enable2_DATA" */
#pragma CODE_SEG MotorL_Enable2_CODE
#pragma CONST_SEG MotorL_Enable2_CONST /* Constant section for this module */
/*
** ===================================================================
**     Method      :  MotorL_Enable2_GetVal (component BitIO)
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
/*
bool MotorL_Enable2_GetVal(void)

**  This method is implemented as a macro. See MotorL_Enable2.h file.  **
*/

/*
** ===================================================================
**     Method      :  MotorL_Enable2_PutVal (component BitIO)
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
void MotorL_Enable2_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTT, 0x02U);           /* PTT1=0x01U */
    Shadow_T |= 0x02U;                 /* Set-up shadow variable */
  } else { /* !Val */
    clrReg8Bits(PTT, 0x02U);           /* PTT1=0x00U */
    Shadow_T &= 0xFDU;                 /* Set-up shadow variable */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  MotorL_Enable2_ClrVal (component BitIO)
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
/*
void MotorL_Enable2_ClrVal(void)

**  This method is implemented as a macro. See MotorL_Enable2.h file.  **
*/

/*
** ===================================================================
**     Method      :  MotorL_Enable2_SetVal (component BitIO)
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
/*
void MotorL_Enable2_SetVal(void)

**  This method is implemented as a macro. See MotorL_Enable2.h file.  **
*/

/*
** ===================================================================
**     Method      :  MotorL_Enable2_SetDir (component BitIO)
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
void MotorL_Enable2_SetDir(bool Dir)
{
  if (Dir) {
    setReg8(PTT, (getReg8(PTT) & (byte)(~(byte)0x02U)) | (Shadow_T & 0x02U)); /* PTT1=Shadow_T[bit 1] */
    setReg8Bits(DDRT, 0x02U);          /* DDRT1=0x01U */
  } else { /* !Dir */
    clrReg8Bits(DDRT, 0x02U);          /* DDRT1=0x00U */
  } /* !Dir */
}


/* END MotorL_Enable2. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.02 [04.44]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
