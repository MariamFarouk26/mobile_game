#include "STD_TYPES.h"
#include "MDIO_Interface.h"
#include "HLCD_Interface.h"
#include "HKPD_Interface.h"
#include "avr/delay.h"


void main(void)
{
	   u8 ArrayOfHuman[8]={0b00001110
					     ,0b00001110
					     ,0b00000100
					     ,0b00011111
					     ,0b00000100
					     ,0b00001110
					     ,0b00010001
					     ,0b00000000};

	  u8 ArrayOfBall[8]={0b00000000
					  ,0b00000000
					  ,0b00001100
					  ,0b00001100
					  ,0b00000000
					  ,0b00000000
					  ,0b00000000
					  ,0b00000000};

  //    (0, 18, 10, 7, 10, 18, 0, 0)
	  u8 ArrayOfDeidHuman[8]={0b00000000
						   ,0b00010010
						   ,0b00001010
						   ,0b00000111
						   ,0b00001010
						   ,0b00010010
						   ,0b00000000
						   ,0b00000000};

	  u8 ArrayOfWhash[8]={0b00010000
					   ,0b00011100
					   ,0b00010010
					   ,0b00011101
					   ,0b00010010
					   ,0b00011100
					   ,0b00010000
					   ,0b00000000};

	HLCD_VoidInit();



	HLCD_VoidWriteSpecailCharOnce(ArrayOfHuman,1,0,15);
	HLCD_VoidWriteSpecailCharOnce(ArrayOfWhash,3,0,0);
    HLCD_VoidWriteSpecialCharacter(ArrayOfBall,0);
    HLCD_VoidWriteSpecialCharacter(ArrayOfDeidHuman,2);
for(int i=1;i<=15;i++)
{	if(i==15)
			{
				//HLCD_VoidWriteSpecailChar(ArrayOfDeidHuman,2,0,15);
				//HLCD_VoidWriteSpecialCharacter(ArrayOfDeidHuman,2);
				HLCD_VoidDisplaySpecialCharacter(2,0,15);
				_delay_ms(200);
				HLCD_VoidSendCommand(0x01);
				HLCD_VoidGoToXY(0,4);
				HLCD_VoidSendString("Game Over");

			}
	    else
			{
				//HLCD_VoidWriteSpecailChar(ArrayOfBall,0,0,i);
		       // HLCD_VoidWriteSpecialCharacter(ArrayOfBall,0);
				HLCD_VoidDisplaySpecialCharacter(0,0,i);
				_delay_ms(200);
				HLCD_VoidGoToXY(0,i);
		     	HLCD_VoidSendChar(' ');
				//HLCD_VoidSendCommand(0x01);
				HLCD_VoidWriteSpecailCharOnce(ArrayOfHuman,1,0,15);
				HLCD_VoidWriteSpecailCharOnce(ArrayOfWhash,3,0,0);
			}
	}
}



/*
#include "STD_TYPES.h"
#include "MDIO_Interface.h"
#include "HLCD_Interface.h"
#include "HKPD_Interface.h"
//#include "HLCD_CFG.h"
#include "avr/delay.h"


void main(void)
{
	   u8 ArrayOfHuman[8]={0b00001110
					     ,0b00001110
					     ,0b00000100
					     ,0b00011111
					     ,0b00000100
					     ,0b00001110
					     ,0b00010001
					     ,0b00000000};

	  u8 ArrayOfBall[8]={0b00000000
					  ,0b00000000
					  ,0b00001100
					  ,0b00001100
					  ,0b00000000
					  ,0b00000000
					  ,0b00000000
					  ,0b00000000};

  //    (0, 18, 10, 7, 10, 18, 0, 0)
	  u8 ArrayOfDeidHuman[8]={0b00000000
						   ,0b00010010
						   ,0b00001010
						   ,0b00000111
						   ,0b00001010
						   ,0b00010010
						   ,0b00000000
						   ,0b00000000};

	  u8 ArrayOfWhash[8]={0b00010000
					   ,0b00011100
					   ,0b00010010
					   ,0b00011101
					   ,0b00010010
					   ,0b00011100
					   ,0b00010000
					   ,0b00000000};

	HLCD_VoidInit();
	HKPD_VoidInit();
	u8 result,i=1;

	HLCD_VoidWriteSpecailCharOnce(ArrayOfHuman,1,0,15);
	HLCD_VoidWriteSpecailCharOnce(ArrayOfWhash,3,0,0);
HLCD_VoidWriteSpecialCharacter(ArrayOfBall,0);
HLCD_VoidWriteSpecialCharacter(ArrayOfDeidHuman,2);
while(i!=15)
	{
	if(result!='#')
		  {
				result=HKPD_U8GetPressKeyUsingArray();

				if(result=='+')
					{ HLCD_VoidGoToXY(0,15);
					  HLCD_VoidSendChar(' ');
					  HLCD_VoidDisplaySpecialCharacter(0,1,15);
					  _delay_ms(300);
					  HLCD_VoidSendCommand(0X01);
					  HLCD_VoidDisplaySpecialCharacter(0,0,15);
					}

		if(i==15)
			{
				//HLCD_VoidWriteSpecailChar(ArrayOfDeidHuman,2,0,15);
				//HLCD_VoidWriteSpecialCharacter(ArrayOfDeidHuman,2);
				HLCD_VoidDisplaySpecialCharacter(2,0,15);
				_delay_ms(200);
				HLCD_VoidSendCommand(0x01);
				HLCD_VoidGoToXY(0,4);
				HLCD_VoidSendString("Game Over");

			}
	    else
			{
				//HLCD_VoidWriteSpecailChar(ArrayOfBall,0,0,i);
		       // HLCD_VoidWriteSpecialCharacter(ArrayOfBall,0);
				HLCD_VoidDisplaySpecialCharacter(0,0,i);
				_delay_ms(200);
				HLCD_VoidGoToXY(0,i);
		     	HLCD_VoidSendChar(' ');
				//HLCD_VoidSendCommand(0x01);
				HLCD_VoidWriteSpecailCharOnce(ArrayOfHuman,1,0,15);
				HLCD_VoidWriteSpecailCharOnce(ArrayOfWhash,3,0,0);
			}
	}
}
}

*/

/*  ** up/down human**
#include"STD_TYPES.h"
#include "MDIO_Interface.h"
#include"HLCD_Interface.h"
#include<avr/delay.h>
#include "HKPD_Interface.h"


int main (void)
{
	u8 ArrayOfHuman[8]={0b00001110
						     ,0b00001110
						     ,0b00000100
						     ,0b00011111
						     ,0b00000100
						     ,0b00001110
						     ,0b00010001
						     ,0b00000000};

	HLCD_VoidInit();
	HKPD_VoidInit();
	u8 result;
	HLCD_VoidWriteSpecialCharacter(ArrayOfHuman,0);

	while(1)
		{
	            result=HKPD_U8GetPressKeyUsingArray();

				HLCD_VoidDisplaySpecialCharacter(0,0,15);
				_delay_ms(100);
				//HLCD_VoidDisplaySpecialCharacter(0,1,15);
						if(result!='#')
						{
							if(result=='+')
								{ HLCD_VoidGoToXY(0,15);
							      HLCD_VoidSendChar(' ');
								  HLCD_VoidDisplaySpecialCharacter(0,1,15);
								  _delay_ms(300);
								  HLCD_VoidSendCommand(0X01);
								}

						}
		}

	 return 0;
}*/




/*

#include "STD_TYPES.h"
#include "MDIO_Interface.h"
#include "HLCD_Interface.h"
#include "HLCD_CFG.h"
#include "avr/delay.h"


void main(void)
{
	   u8 ArrayOfHuman[8]={0b00001110
					     ,0b00001110
					     ,0b00000100
					     ,0b00011111
					     ,0b00000100
					     ,0b00001110
					     ,0b00010001
					     ,0b00000000};

	  u8 ArrayOfBall[8]={0b00000000
					  ,0b00000000
					  ,0b00001100
					  ,0b00001100
					  ,0b00000000
					  ,0b00000000
					  ,0b00000000
					  ,0b00000000};

  //    (0, 18, 10, 7, 10, 18, 0, 0)
	  u8 ArrayOfDeidHuman[8]={0b00000000
						   ,0b00010010
						   ,0b00001010
						   ,0b00000111
						   ,0b00001010
						   ,0b00010010
						   ,0b00000000
						   ,0b00000000};

	  u8 ArrayOfWhash[8]={0b00010000
					   ,0b00011100
					   ,0b00010010
					   ,0b00011101
					   ,0b00010010
					   ,0b00011100
					   ,0b00010000
					   ,0b00000000};

	HLCD_VoidInit();
	u8 i=0,flag=0,result;

	HLCD_VoidWriteSpecailCharOnce(ArrayOfHuman,1,0,15);
	HLCD_VoidWriteSpecailCharOnce(ArrayOfWhash,3,0,0);


	while(i==15&&flag==1)
	{
		flag=0;
		result=HKPD_U8GetPressKeyUsingArray();
		HLCD_VoidDisplaySpecialCharacter(0,0,15);
		_delay_ms(100);
		//HLCD_VoidDisplaySpecialCharacter(0,1,15);
				if(result!='#')
				{
					if(result=='+')
						{ HLCD_VoidGoToXY(0,15);
						  HLCD_VoidSendChar(' ');
						  HLCD_VoidDisplaySpecialCharacter(0,1,15);
						  _delay_ms(300);
						  HLCD_VoidSendCommand(0X01);
						  flag=1;
						}
				}
			    HLCD_VoidWriteSpecialCharacter(ArrayOfBall,0);
				HLCD_VoidDisplaySpecialCharacter(0,0,i+1);
				_delay_ms(200);
				HLCD_VoidGoToXY(0,i+1);
				HLCD_VoidSendChar(' ');
				//HLCD_VoidSendCommand(0x01);
				HLCD_VoidWriteSpecailCharOnce(ArrayOfHuman,1,0,15);
				HLCD_VoidWriteSpecailCharOnce(ArrayOfWhash,3,0,0);
				i++;
	}
				HLCD_VoidWriteSpecialCharacter(ArrayOfDeidHuman,2);
				HLCD_VoidDisplaySpecialCharacter(2,0,15);
				_delay_ms(200);
				HLCD_VoidSendCommand(0x01);
				HLCD_VoidGoToXY(0,4);
				HLCD_VoidSendString("Game Over");
}
*/



