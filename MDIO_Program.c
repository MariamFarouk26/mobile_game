/*this file contain all func we will call in main to make pins or port out or input without writing 
DDRA=0b00000001;
PORTA=0b000000001;
and so on....
*/
// include STD_TYPES.h before MIDO_Interface.h and MDIO_private.h because we use for ex u8 in these 2 files and we can not include file.h inside other file.h
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_private.h"

void MDIO_VoidSetPinDirection(u8 copy_U8Port , u8 copy_U8Pin , u8 copy_U8Dircation)
{
	if(0==copy_U8Dircation)
	{
		switch(copy_U8Port)
		{ 
		  case 0:CLR_BIT(DDRA_REG, copy_U8Pin); break;
		  case 1:CLR_BIT(DDRB_REG, copy_U8Pin); break;
		  case 2:CLR_BIT(DDRC_REG, copy_U8Pin); break;
		  case 3:CLR_BIT(DDRD_REG, copy_U8Pin); break;
		}	
	}
else if(1==copy_U8Dircation)
    {
		switch(copy_U8Port)
		{ 
		  case 0:SET_BIT(DDRA_REG, copy_U8Pin); break;
		  case 1:SET_BIT(DDRB_REG, copy_U8Pin); break;
		  case 2:SET_BIT(DDRC_REG, copy_U8Pin); break;
		  case 3:SET_BIT(DDRD_REG, copy_U8Pin); break;
		}
	}
			
}

u8 MDIO_U8GetPinValue(u8 copy_U8Port , u8 copy_U8Pin )
{  
   u8 Return_Value;
	switch(copy_U8Port)
	{    
	      case 0:Return_Value=GET_BIT(PINA_REG,copy_U8Pin);break;
		  case 1:Return_Value=GET_BIT(PINB_REG,copy_U8Pin);break;
		  case 2:Return_Value=GET_BIT(PINC_REG,copy_U8Pin);break;
		  case 3:Return_Value=GET_BIT(PIND_REG,copy_U8Pin);break;
	}
	return Return_Value;
}


// as we want some pins input and some pins output not all input only or out only
void MDIO_VoidSetPortDirection(u8 copy_U8Port , u8 copy_U8Dircation)
{
		switch(copy_U8Port)
		{ 
		  case 0:DDRA_REG=copy_U8Dircation; break;
		  case 1:DDRB_REG=copy_U8Dircation; break;
		  case 2:DDRC_REG=copy_U8Dircation; break;
		  case 3:DDRD_REG=copy_U8Dircation; break;
		}
		
}


void MDIO_VoidSetPinValue(u8 copy_U8Port , u8 copy_U8Pin , u8 copy_U8Value)
{
	if(0==copy_U8Value)
	{
		switch(copy_U8Port)
		{ 
		  case 0:CLR_BIT(PORTA_REG, copy_U8Pin); break;
		  case 1:CLR_BIT(PORTB_REG, copy_U8Pin); break;
		  case 2:CLR_BIT(PORTC_REG, copy_U8Pin); break;
		  case 3:CLR_BIT(PORTD_REG, copy_U8Pin); break;
		}	
	}
else if(1==copy_U8Value)
    {
		switch(copy_U8Port)
		{ 
		  case 0:SET_BIT(PORTA_REG, copy_U8Pin); break;
		  case 1:SET_BIT(PORTB_REG, copy_U8Pin); break;
		  case 2:SET_BIT(PORTC_REG, copy_U8Pin); break;
		  case 3:SET_BIT(PORTD_REG, copy_U8Pin); break;
		}
	}
		
	
}

void MDIO_VoidSetPortValue(u8 copy_U8Port , u8 copy_U8Value)
{
	
		switch(copy_U8Port)
		{ 
		  case 0:PORTA_REG=copy_U8Value; break;
		  case 1:PORTB_REG=copy_U8Value; break;
		  case 2:PORTC_REG=copy_U8Value; break;
		  case 3:PORTD_REG=copy_U8Value; break;
		}	

	
}

void MDIO_VoidTogglePin(u8 copy_U8Port , u8 copy_U8Pin )
{  

	switch(copy_U8Port)
	{    
	      case 0:TOGGLE_BIT(PORTA_REG,copy_U8Pin);break;
		  case 1:TOGGLE_BIT(PORTB_REG,copy_U8Pin);break;
		  case 2:TOGGLE_BIT(PORTC_REG,copy_U8Pin);break;
		  case 3:TOGGLE_BIT(PORTD_REG,copy_U8Pin);break;
	}
	
}
