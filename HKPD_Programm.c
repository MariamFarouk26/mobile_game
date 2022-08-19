
#include "STD_TYPES.h"
#include "MDIO_Interface.h"
//#include "HKPD_private.h" /*here we don't need to include HLCD_private as it empty file */
#include "HKPD_Interface.h"
#include "HKPD_CFG.h"
#include "HLCD_Interface.h"
#include <avr/delay.h>



void HKPD_VoidInit()
{   /* first part:intialize which ports or pins is output and which is input
       second part: put value for voll up resistance for pins in ports which is input
       third part : set the colounms for output pins
    */


	//MDIO_VoidSetPortDirection(PORTA , ob00001111);  THIS if i want to dell with one port only
	// using MDIO_VoidSetPinDirection if i want diff port to work with it
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN0 , INPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN1 , INPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN2 , INPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN3 , INPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN4 , OUTPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN5 , OUTPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN6 , OUTPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT , PIN7 , OUTPUT);


//for second and third part togther
	//MDIO_VoidSetPortDirection(PORTA , ob11111111);  THIS if i want to dell with one port only
	// using MDIO_VoidSetPinDirection if i want diff port to work with it

	// second part:set the voll up resistance for input pins
	MDIO_VoidSetPinValue(HKPD_PORT , PIN0, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT , PIN1, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT , PIN2, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT , PIN3, HIGH);


	// third part:set the colounms for output pins
	MDIO_VoidSetPinValue(HKPD_PORT , PIN4, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT , PIN5, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT , PIN6, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT , PIN7, HIGH);

}



 // using equation
u8 HKPD_U8GetPressKey()
{  // default value for  Present_Key_value in case i want to check if i am not pressing on switch
	u8 Copy_U8Present_Key_value='#';


	for(u8 Copy_U8COLOUMN=0;Copy_U8COLOUMN<4;Copy_U8COLOUMN++)
	{ //set current column pin low to test all row pins to find out which button has been pressed
	MDIO_VoidSetPinValue(HKPD_PORT , 4+Copy_U8COLOUMN, LOW);

		for(u8 Copy_U8ROW=0; Copy_U8ROW <4;Copy_U8ROW++)
			{ // check the current row value
			  u8 x=MDIO_U8GetPinValue(HKPD_PORT , Copy_U8ROW );

			    // if x==0 meaning i press on the switch
			  	  if(x==0)
				{    // the value of each switch
					 Copy_U8Present_Key_value=(4*Copy_U8ROW+(Copy_U8COLOUMN)+1);
				}
			  	  // while i am still pressing on the same switch
			  	  while(MDIO_U8GetPinValue(HKPD_PORT,Copy_U8ROW)==0)
				  { // do nothing
				  }
			  	  // delaying for possing phenomena
			  	_delay_ms(5);
		    }

		//set current column pin HIGH
			MDIO_VoidSetPinValue(HKPD_PORT , 4+Copy_U8COLOUMN, HIGH);
	}
	  return Copy_U8Present_Key_value;
}


//using array
u8 HKPD_U8GetPressKeyUsingArray()
{  // default value for  Present_Key_value in case i want to check if i am not pressing on switch
	u8 Copy_U8Present_Key_value='#';


	for(u8 Copy_U8COLOUMN=0;Copy_U8COLOUMN<4;Copy_U8COLOUMN++)
	{ /*set current column pin low to test all row pins to find out which button has been pressed*/
		MDIO_VoidSetPinValue(HKPD_PORT , 4+Copy_U8COLOUMN, LOW);

		for(u8 Copy_U8ROW=0; Copy_U8ROW <4;Copy_U8ROW++)
			{ // check the current row value
			  u8 x=MDIO_U8GetPinValue(HKPD_PORT , Copy_U8ROW );

			    // if x==0 meaning i press on the switch
			  	  if(x==0)
				{    // the value of each switch
					 Copy_U8Present_Key_value=keys[Copy_U8ROW][Copy_U8COLOUMN];
				}
			  	  // while i am still pressing on the same switch
			  	  while(MDIO_U8GetPinValue(HKPD_PORT,Copy_U8ROW)==0)
				  { // do nothing
				  }
			  	  // delaying for possing phenomena
			  	_delay_ms(10);
		    }

		/*set current column pin HIGH */
			MDIO_VoidSetPinValue(HKPD_PORT , 4+Copy_U8COLOUMN, HIGH);
	}
	  return Copy_U8Present_Key_value;
}







void HKPD_Voidcalculator(u8 Copy_U8ConvertLeftNumToInt,u8 Copy_U8ConvertRightNumToInt,u8 Copy_U8operation)
 { s16 Copy_S16result;
    switch(Copy_U8operation)
    {
        case '+':Copy_S16result=Copy_U8ConvertLeftNumToInt+Copy_U8ConvertRightNumToInt;
        		HLCD_VoidSendChar(Copy_S16result);
                 break;
        case '-':Copy_S16result=Copy_U8ConvertLeftNumToInt-Copy_U8ConvertRightNumToInt;
        		HLCD_VoidSendChar(Copy_S16result);
                 break;
        case '*':Copy_S16result=Copy_U8ConvertLeftNumToInt*Copy_U8ConvertRightNumToInt;
        		HLCD_VoidSendChar(Copy_S16result);
                break;
        case '/':Copy_S16result=Copy_U8ConvertLeftNumToInt-Copy_U8ConvertRightNumToInt;
        		HLCD_VoidSendChar(Copy_S16result);
                break;
    }
 }
