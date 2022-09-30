#include"../LIB/LSTD_TYPES.h"
#include"../LIB/LBIT_MATH.h"

#include"../MCAL/MDIO/MDIO_interface.h"

#include"../MCAL/MEXTI/MEXTI_interface.h"

#include"../MCAL/MTIMER/MTIMER_config.h"
#include"../MCAL/MTIMER/MTIMER_interface.h"

#include"../MCAL/MGIE/MGIE_interface.h"

#include"../HAL/HLED/HLED_interface.h"
#include"../HAL/HLED/HLED_config.h"

#include"../HAL/HPUSH_BUTTON/HPUSH_BUTTON_interface.h"
#include"../HAL/HPUSH_BUTTON/HPUSH_BUTTON_config.h"

#include"APP_interface.h"

u8 ped_mode = 0 , flag_to_begin = 0;
u8 Vech_stop_or_GetReadyTo_move = 0;
u8 Vech_move_or_GetReadyTo_stop = 0;

void pattern()//called by ISR
{
	ped_mode = 1;
}

void APP_void_init()
{
	HLED_void_enable(); // Set direction of pins connected to 2 traffic lights
	HPUSH_BUTTON_void_init(BUTTON1_PORT , BUTTON1_PIN); // Set direction of pin connected to push button
	//=====================================================================================================
	/*Enable global interrupt*/
	MGIE_void_enable();
	//=====================================================================================================
	//for TIMER0
	//===========
	/*TIMER 0 INITIALIZATION*/
	MTIMER_TIMER0_void_Init();
	//=====================================================================================================
	//for external interrupt 0 (INT0)
	//===============================
	/*Configurations of external interrupt 0*/
	MEXTI_void_intialization(INT0 , FALLING_EDGE);

	MEXTI_void_setCallBack_INT0(pattern);

	/*enable external interrupt 0 initially*/
	MEXTI_void_enable(INT0);
	//====================================================================
}
void APP_void_start()
{
	switch(ped_mode)
	{
	case 0 :
		//========================================
		/*enable external interrupt 0*/
		//========================================
		MEXTI_void_enable(INT0);
		//========================================
		if(flag_to_begin == 1)
		{
			flag_to_begin = 0;
			goto from_begin;
		}
		Vech_move_or_GetReadyTo_stop = 1;
		//car moving
		HLED_void_switch_off(LED_VECH_PORT , LED_VECH_R);
		HLED_void_switch_on(LED_VECH_PORT , LED_VECH_G);

		for(u16 i = 0 ; i < 16000 ; i++)
		{
			 MTIMER_void_delay();
			 if(ped_mode == 1) break;
		}
		if(ped_mode == 1) break;
	//============================================================================
		from_begin:
		Vech_move_or_GetReadyTo_stop = 1;
		//====================================================================
		//cars get ready to stop
		HLED_void_switch_off(LED_PED_PORT , LED_PED_R);
		for(u8 j = 0 ; j < 8 ; j++)
		{
			HLED_void_switch_on(LED_VECH_PORT , LED_VECH_Y);
			for(u16 i = 0 ; i < 1000 ; i++)
			{
				MTIMER_void_delay();
				if(ped_mode == 1) break;
			}
			if(ped_mode == 1) break;

			HLED_void_switch_off(LED_VECH_PORT , LED_VECH_Y);
			for(u16 i = 0 ; i < 1000 ; i++)
			{
				MTIMER_void_delay();
				if(ped_mode == 1) break;
			}
			if(ped_mode == 1) break;
		}
		if(ped_mode == 1) break;
		Vech_move_or_GetReadyTo_stop = 0;
	//==============================================================================================================================
		Vech_stop_or_GetReadyTo_move = 1;
		// cars stop
		HLED_void_switch_off(LED_VECH_PORT , LED_VECH_G);
		HLED_void_switch_on(LED_VECH_PORT , LED_VECH_R);
		for(u16 i = 0 ; i < 16000 ; i++)
		{
			MTIMER_void_delay();
			if(ped_mode == 1) break;
		}
		if(ped_mode == 1) break;
	//===========================================================================
		//cars get ready to move
		for(u8 j = 0 ; j < 8 ; j++)
		{
			HLED_void_switch_on(LED_VECH_PORT , LED_VECH_Y);

			for(u16 i = 0 ; i < 1000 ; i++)
			{
				MTIMER_void_delay();
				if(ped_mode == 1) break;
			}
			if(ped_mode == 1) break;

			HLED_void_switch_off(LED_VECH_PORT , LED_VECH_Y);
			for(u16 i = 0 ; i < 1000 ; i++)
			{
				MTIMER_void_delay();
				if(ped_mode == 1) break;
			}
			if(ped_mode == 1) break;
		}
		if(ped_mode == 1) break;
		Vech_stop_or_GetReadyTo_move = 0;
		break;
	case 1:
		//========================================
		/*Disable external interrupt 0*/
		//========================================
		MEXTI_void_disable(INT0);
		//========================================
		if(Vech_stop_or_GetReadyTo_move == 1)
		{
			Vech_stop_or_GetReadyTo_move = 0;
			Vech_move_or_GetReadyTo_stop = 0;

			//cars stop and Pedestrian moving
			HLED_void_switch_off(LED_VECH_PORT , LED_VECH_Y);

			HLED_void_switch_on(LED_PED_PORT , LED_PED_G);
			HLED_void_switch_on(LED_VECH_PORT , LED_VECH_R);

			for(u16 i = 0 ; i < 16000 ; i++)
			{
				MTIMER_void_delay();
			}

		}
		else if(Vech_move_or_GetReadyTo_stop == 1)
		{
			Vech_stop_or_GetReadyTo_move = 0;
			Vech_move_or_GetReadyTo_stop = 0;

			//cars get ready to stop and Pedestrian get ready to move
			HLED_void_switch_off(LED_VECH_PORT , LED_VECH_Y);

			HLED_void_switch_on(LED_PED_PORT , LED_PED_R);
			HLED_void_switch_on(LED_VECH_PORT , LED_VECH_G);
			for(u8 j = 0 ; j < 8 ; j++)
			{
				HLED_void_switch_on(LED_VECH_PORT , LED_VECH_Y);
				HLED_void_switch_on(LED_PED_PORT , LED_PED_Y);
				for(u16 i = 0 ; i < 1000 ; i++)
				{
					MTIMER_void_delay();
				}

				HLED_void_switch_off(LED_VECH_PORT , LED_VECH_Y);
				HLED_void_switch_off(LED_PED_PORT , LED_PED_Y);
				for(u16 i = 0 ; i < 1000 ; i++)
				{
					MTIMER_void_delay();
				}
			}

			//cars stops and Pedestrian moves
			HLED_void_switch_off(LED_PED_PORT , LED_PED_R);
			HLED_void_switch_off(LED_VECH_PORT , LED_VECH_G);

			HLED_void_switch_on(LED_PED_PORT , LED_PED_G);
			HLED_void_switch_on(LED_VECH_PORT , LED_VECH_R);
			for(u16 i = 0 ; i < 16000 ; i++)
			{
				MTIMER_void_delay();
			}
		}

		//cars get ready to move and Pedestrian get ready to stop
		HLED_void_switch_on(LED_VECH_PORT , LED_VECH_R);
		HLED_void_switch_on(LED_PED_PORT , LED_PED_G);
		for(u8 j = 0 ; j < 8 ; j++)
		{
			HLED_void_switch_on(LED_VECH_PORT , LED_VECH_Y);
			HLED_void_switch_on(LED_PED_PORT , LED_PED_Y);
			for(u16 i = 0 ; i < 1000 ; i++)
			{
				MTIMER_void_delay();
			}

			HLED_void_switch_off(LED_VECH_PORT , LED_VECH_Y);
			HLED_void_switch_off(LED_PED_PORT , LED_PED_Y);
			for(u16 i = 0 ; i < 1000 ; i++)
			{
				MTIMER_void_delay();
			}
		}
		//cars moves and Pedestrian stops
		HLED_void_switch_off(LED_VECH_PORT , LED_VECH_R);
		HLED_void_switch_off(LED_PED_PORT , LED_PED_G);

		HLED_void_switch_on(LED_PED_PORT , LED_PED_R);
		HLED_void_switch_on(LED_VECH_PORT , LED_VECH_G);
		for(u16 i = 0 ; i < 16000 ; i++)
		{
			MTIMER_void_delay();
		}
		ped_mode = 0;
		flag_to_begin = 1;
		break;

	}
}
