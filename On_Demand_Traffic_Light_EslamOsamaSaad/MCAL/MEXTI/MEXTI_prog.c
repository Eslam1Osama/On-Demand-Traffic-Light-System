#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"

#include"MEXTI_private.h"
#include"MEXTI_interface.h"


void (*ptr_f0) (void); //global varIAble which is pointer to the function in INT0
void (*ptr_f1) (void); //global varIAble which is pointer to the function in INT1
void (*ptr_f2) (void); //global varIAble which is pointer to the function in INT2

void MEXTI_void_enable(u8 INT)
{
	/*Enable PIE (peripheral interrupt enable)*/
	SET_BIT(EXTI_GICR , INT);
}

void MEXTI_void_disable(u8 INT)
{
	/* -disable PIE (peripheral interrupt enable)*/
	CLEAR_BIT(EXTI_GICR , INT);
}


void MEXTI_void_intialization(u8 INT , u8 Mode)
{

	/*Set mode*/
	if(INT == INT0)
	{
		if(Mode == RISING_EDGE)// ISC01 = 1 & ISC00 = 1
		{
			SET_BIT(EXTI_MCUCR , ISC00);
			SET_BIT(EXTI_MCUCR , ISC01);
		}
		else if(Mode == FALLING_EDGE)// ISC01 = 1 & ISC00 = 0
		{
			CLEAR_BIT(EXTI_MCUCR , ISC00);
			SET_BIT(EXTI_MCUCR , ISC01);
		}
		else if(Mode == LOW_LEVEL)// ISC01 = 0 & ISC00 = 0
		{
			CLEAR_BIT(EXTI_MCUCR , ISC00);
			CLEAR_BIT(EXTI_MCUCR , ISC01);
		}
		else if(Mode == ANY_CHANGE)// ISC01 = 0 & ISC00 =  1
		{
			SET_BIT(EXTI_MCUCR , ISC00);
			CLEAR_BIT(EXTI_MCUCR , ISC00);
		}
	}

	else if(INT == INT1)
	{
		if(Mode == RISING_EDGE) // ISC11 = 1 & ISC10 = 1
		{
			SET_BIT(EXTI_MCUCR , ISC10);
			SET_BIT(EXTI_MCUCR , ISC11);
		}
		else if(Mode == FALLING_EDGE)// ISC11 = 1 & ISC10 = 0
		{
			CLEAR_BIT(EXTI_MCUCR , ISC10);
			SET_BIT(EXTI_MCUCR , ISC11);
		}
		else if(Mode == LOW_LEVEL)// ISC11 = 0 & ISC10 = 0
		{
			CLEAR_BIT(EXTI_MCUCR , ISC10);
			CLEAR_BIT(EXTI_MCUCR , ISC11);
		}
		else if(Mode == ANY_CHANGE)// ISC11 = 0 & ISC10 = 1
		{
			SET_BIT(EXTI_MCUCR , ISC10);
			CLEAR_BIT(EXTI_MCUCR , ISC11);
		}
	}

	else if(INT == INT2)
	{
		if(Mode == RISING_EDGE) // ISC2 = 1
			SET_BIT(EXTI_MCUCSR , ISC2);

		else if(Mode == FALLING_EDGE) // ISC2 = 0
			CLEAR_BIT(EXTI_MCUCSR , ISC2);
	}
}

void MEXTI_void_setCallBack_INT0(void (*ptr) (void))
{
	ptr_f0 = ptr;
}
void MEXTI_void_setCallBack_INT1(void (*ptr) (void))
{
	ptr_f1 = ptr;
}
void MEXTI_void_setCallBack_INT2(void (*ptr) (void))
{
	ptr_f2 = ptr;
}

void __vector_1(void)  __attribute((signal));
void __vector_1(void)
{
	ptr_f0();
}
void __vector_2(void)  __attribute((signal));
void __vector_2(void)
{
	ptr_f1();
}
void __vector_3(void)  __attribute((signal));
void __vector_3(void)
{
	ptr_f2();
}
