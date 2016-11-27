/**
 * @file		AMC7812__GPIO.C
 * @brief		GPIO Interface
 * @author		Lachlan Grogan
 * @copyright	This file contains proprietary and confidential information of
 *				SIL3 Pty. Ltd. (ACN 123 529 064). This code may be distributed
 *				under a license from SIL3 Pty. Ltd., and may be used, copied
 *				and/or disclosed only pursuant to the terms of that license agreement.
 *				This copyright notice must be retained as part of this file at all times.
 * @copyright	This file is copyright SIL3 Pty. Ltd. 2003-2016, All Rights Reserved.
 * @st_fileID	LCCM658R0.FILE.006
 */
/**
 * @addtogroup MULTICORE
 * @{ */
/**
 * @addtogroup AMC7812
 * @ingroup MULTICORE
 * @{ */
/**
 * @addtogroup AMC7812__GPIO
 * @ingroup AMC7812
 * @{ */

#include "../amc7812.h"
#if C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE == 1U

// GPIO pin address
#define AMC7812_REG_ADR__GPIO 	(0x4B)

#define LOOP_COUNTER_LIMIT		(10000000U)

/***************************************************************************//**
 * @brief
 * Init the GPIO portion of the device
 * 
 * @st_funcMD5		61B0504883195D29B464EA09607BECEF
 * @st_funcID		LCCM658R0.FILE.006.FUNC.001
 */


void vAMC7812_GPIO__Init(void)
{


}


void vAMC7812_GPIO__Process( void )
{

	// declarations

	Luint8 u8GPIOState;

	u8GPIOState = 100;

	switch ( u8GPIOState )
	{
		case 0:
			vAMC7812_GPIO__Test();
			break;

	}
}




void vAMC7812_GPIO__Test( void )
{
	// declarations

	Lint16 s16Return;
	Luint16 u16GPIO_BitField;
	Luint32 u32Counter;
	Luint8 u8GPIO_Addr;
	Luint16 u16GPIO_Masks[8];


	// generate bit masks

	u16GPIO_Masks[0] = 0x0001;
	u32Counter = 1;
	while ( u32Counter < 8 )
	{
		u16GPIO_Masks[u32Counter] = u16GPIO_Masks[u32Counter - 1] << 1;
	}

	// set GPIO 0 low

	u16GPIO_BitField = 0x0000;
	u8GPIO_Addr = AMC7812_REG_ADR__GPIO;
	s16Return = -1;
	s16Return = s16AMC7812_I2C__WriteU16( C_LOCALDEF__LCCM658__BUS_ADDX, u8GPIO_Addr, u16GPIO_BitField );

	//	use a loop for a cheap delay

	u32Counter = 0;
	while ( u32Counter < LOOP_COUNTER_LIMIT )
	{
		u32Counter++;
	}

	// set GPIO 0 high

	u16GPIO_BitField = u16GPIO_Masks[0];
	s16Return = -1;
	s16Return = s16AMC7812_I2C__WriteU16( C_LOCALDEF__LCCM658__BUS_ADDX, u8GPIO_Addr, u16GPIO_BitField );

}


#endif //#if C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE == 1U
//safetys
#ifndef C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE
	#error
#endif
/** @} */
/** @} */
/** @} */
