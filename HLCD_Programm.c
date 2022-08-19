 /* ******************** Author: mariam farouk ******************************
  * *********************** Data: 24/9/2021 *********************************
  *
  * ************description:we here in HLCD have made call to 3MDIO files
                            as these 3 files helps use to knew which is the output
                            or input from direction ,toggle the output ,
                            get value of input ,take the value of output and so on ...******
---------------------------------------------------------------------------------------------
*/

/*
the project of HLCD_TEST we should insert in the workspace of it the files :
STD_TYPES.h
BIT_MATH.h 
MDIO_Interface.h 
MDIO_Private.h 
MDIO_Program.c
HLCD_Interface.h 
HLCD_Private.h 
HLCD_Program.c

BUT IN main we should include the files:
STD_TYPES.h
MDIO_Interface.h 
HLCD_Interface.h
*/

#include "STD_TYPES.h"
#include "MDIO_Interface.h"
#include "HLCD_private.h" /*here we don't need to include HLCD_private as it empty file */
#include "HLCD_CFG.h"
#include <avr/delay.h>
#include <stdlib.h>

void HLCD_VoidSendChar(u8 Copy_U8Data)
	{
		/*RS=1*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8RSPin,HIGH);

		/*RW=0*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8RWPin,LOW);

		/**************DATA*************/
		MDIO_VoidSetPortValue(HLCD_U8DataPort, Copy_U8Data);

		/*****ENABLE SEQ*****/
		/* ENABLE LOW*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8ENPin,LOW);
		_delay_ms(2);
		/* ENABLE HIGH*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8ENPin,HIGH);
		_delay_ms(2);
		/* ENABLE LOW*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8ENPin,LOW);
		_delay_ms(2); // wait
	}


void HLCD_VoidSendCommand(u8 Copy_U8Command)
	{
			/*RS=0*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8RSPin,LOW);

		/*RW=0*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8RWPin,LOW);

		/**************Command*************/
		MDIO_VoidSetPortValue(HLCD_U8DataPort, Copy_U8Command);

		/*****ENABLE SEQ*****/

		/* ENABLE LOW*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8ENPin,LOW);
		_delay_ms(2);

		/* ENABLE HIGH*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8ENPin,HIGH);
		_delay_ms(2);

		/* ENABLE LOW*/
		MDIO_VoidSetPinValue(HLCD_U8ControlPort,HLCD_U8ENPin,LOW);

		_delay_ms(2); //wait
	}


/* in output case we enter data to labtop then we get action on the kit
but in input case we do action on kit "like in :swtich" then we get data to labtop
*/

//we assigned PORTC,RS,RW and EN as output only in init func so we will call the init func in begining of  main.c


/* HLCD_VoidSendCommand this func refer to one option from many options we can use in LCD
BUT HLCD_VoidInit this func contain all options that we can make on LCD
*from these 2 func we can bulid the setting of LCD
* we need HLCD_VoidSendCommand func in HLCD_VoidInit func
* we can call HLCD_VoidSendCommand in main when we need spacific option to be done*/

void HLCD_VoidInit()
{  
	/*# if Mode==8
	{*/
		// 8 bits intailization

         /*set port c direction output*/
	//we don't need to tell that PORTC is output in the HLCD_VoidSendChar func and HLCD_VoidSendCommand func as we will call HLCD_VoidInit func in the begining of main
		MDIO_VoidSetPortDirection(HLCD_U8DataPort, 0b11111111);

		 /* RS direction output*/
		MDIO_VoidSetPinDirection(HLCD_U8ControlPort ,HLCD_U8RSPin, OUTPUT);

		 /* RW direction output*/
		MDIO_VoidSetPinDirection(HLCD_U8ControlPort ,HLCD_U8RWPin , OUTPUT);

		  /* EN direction output*/
	    MDIO_VoidSetPinDirection(HLCD_U8ControlPort ,HLCD_U8ENPin , OUTPUT);

	    _delay_ms(40);  // wait for more than 30ms   40ms


		//function set
		HLCD_VoidSendCommand(0b00111000); // length is 8 bits, display 2 lines, font types 5*8dots
		_delay_ms(1); // wait for more than 30ms    1m=1000 micro sec   1ms
		

		// display ON/OFF control
		//HLCD_VoidSendCommand(0b00001111); //to set on , make cursor display is on and blinking the cursor
		HLCD_VoidSendCommand(0b00001100); // to set on , make cursor display is off and not blinking the cursor
		_delay_ms(1);
		

		//display clear
		HLCD_VoidSendCommand(0b00000001); // clear all display, and set DDRAM to address 00H
		_delay_ms(2);

		/*//entry mode set
		HLCD_VoidSendCommand(0b00000111);*/
	/*}*/
	
	//#elif(Mode==4)
		// 4 bits intailization

/*		set port c direction output
	    MDIO_VoidSetPortDirection(HLCD_U8DataPort, 0b11110000);  //0 for don't care bits(0,1,2,3)

	     RS direction output
	    MDIO_VoidSetPinDirection(HLCD_U8ControlPort ,HLCD_U8RSPin, OUTPUT);

	     RW direction output
	    MDIO_VoidSetPinDirection(HLCD_U8ControlPort ,HLCD_U8RWPin , OUTPUT);

	     EN direction output
	    MDIO_VoidSetPinDirection(HLCD_U8ControlPort ,HLCD_U8ENPin , OUTPUT);

	    _delay_ms(40);  // wait for more than 30ms   40ms

	   //function set
		HLCD_VoidSendCommand(0b00100000); //0010xxxx  ,//0 for don't care bits(0,1,2,3)
		HLCD_VoidSendCommand(0b00100000);//0010xxxx  ,//0 for don't care bits(0,1,2,3)
		HLCD_VoidSendCommand(0b10000000);//NFxxxxxx ,//0 for don't care bits(0,1,2,3,4,5), 2line,5*8dots
		_delay_ms(1); // wait for more than 30ms    1m=1000 micro sec   1ms



		// display ON/OFF control
		HLCD_VoidSendCommand(0b00000000); //0000xxxx
		HLCD_VoidSendCommand(0b11110000);  //1DCBxxxx  ,// to set on , make cursor display is off and not blinking the cursor
		_delay_ms(1);


		//display clear
		HLCD_VoidSendCommand(0b00000000);  //0000xxxx
		HLCD_VoidSendCommand(0b00010000); //0001xxxx
		_delay_ms(2);*/
}




/* my function to print any nuuber in ture way not in vice versa way*/
void HLCD_VoidMYSendNumber(u32 Copy_U32Number)
{
int reminder,x;
	int i=0;
	int *ptr=&x;

	 HLCD_VoidInit();
	while(Copy_U32Number!=0)
	{

		reminder=Copy_U32Number%10;
		Copy_U32Number=Copy_U32Number/10;

		/* in reallocate new pointer we can save the result in same pointer like here we saved new reallocated pointer in old pointer ptr
		  as we do : ptr=(int*)realloc(ptr,sizeof(int)*(i+1));
		  not :  int *ptrr=(int*)realloc(ptr,sizeof(int)*(i+1));
		         ptr=ptrr;
		*/
		ptr=(int*)realloc(ptr,sizeof(int)*(i+1));
		ptr[i]=	reminder;
	    i++;
	    }
	for(int j=i-1;j>=0;j--)
		{
		HLCD_VoidSendChar((ptr[j])+48);
		}
	}




void HLCD_VoidSendViceVersaNumberr(u32 Copy_U32Data)
{
	int qoutant,reminder;

		qoutant=Copy_U32Data/10;
		reminder=Copy_U32Data%10;
		HLCD_VoidSendChar(reminder+48);
		while(qoutant!=0)
		{
			reminder=qoutant%10;
			qoutant=qoutant/10;
			HLCD_VoidSendChar(reminder+48);
		}
}



//power funcion to be used in HLCD_VoidSendNumber function
u32 HLCD_U32PowerOfTen(u8 Copy_U8Power)
{
	u32 Copy_U32ResultOfPower=1;
	for(u8 i=0; i<Copy_U8Power; i++)
	{
		Copy_U32ResultOfPower=Copy_U32ResultOfPower*10;
	}
	return Copy_U32ResultOfPower;
}



/*function to print numbers(whatever the number of digits)*/

void HLCD_VoidSendNumber(u32 Copy_U32Data)
{
	//while loop to calculate the number of digits of the number
	u8 Copy_U8NumberOfDigits = 1;
	while(Copy_U32Data > (HLCD_U32PowerOfTen(Copy_U8NumberOfDigits)-1))
	{
		Copy_U8NumberOfDigits++;
	}

	u32 Copy_U32Quotient = Copy_U32Data;

	for(u8 i=Copy_U8NumberOfDigits; i>1; i--)
	{
		Copy_U32Quotient /= HLCD_U32PowerOfTen(i-1);
		HLCD_VoidSendChar('0'+Copy_U32Quotient);
		Copy_U32Data=Copy_U32Data-(Copy_U32Quotient*HLCD_U32PowerOfTen(i-1));
		Copy_U32Quotient=Copy_U32Data;
	}
	HLCD_VoidSendChar('0'+Copy_U32Quotient);
}



void HLCD_VoidSendString(char Copy_U8Data[48])
{ u8 i=0;
	while(Copy_U8Data[i]!=0)
	{
		HLCD_VoidSendChar(Copy_U8Data[i]);
	    i++;
    }
}



void HLCD_VoidDisconnectedName(u8 Copy_U8Data[48])
{
    u8 i,j=0;
	while(Copy_U8Data[j]!=0)
	 {
	    j++;
     }
	if(j%2==0)
	  {
		// in case even number of char
		 for(i=0;i<(j/2);i++)
	       {
	         HLCD_VoidSendCommand(0x80+(2*i));
	         _delay_ms(2);
	         HLCD_VoidSendChar(Copy_U8Data[2*i]);

	         HLCD_VoidSendCommand(0xc1+(2*i));
	         _delay_ms(2);
	         HLCD_VoidSendChar(Copy_U8Data[(2*i)+1]);
	       }
	  }
	else
	  {  // in case odd number of char

		for( i=0;i<(j/2);i++)
             {
			     HLCD_VoidSendCommand(0x80+(2*i));
			     _delay_ms(2);
			     HLCD_VoidSendChar(Copy_U8Data[2*i]);

	             HLCD_VoidSendCommand(0xc1+(2*i));
		         _delay_ms(2);
		         HLCD_VoidSendChar(Copy_U8Data[(2*i)+1]);
	    	  }

		     HLCD_VoidSendCommand(0x80+(2*i));
		     _delay_ms(2);
	         HLCD_VoidSendChar(Copy_U8Data[2*i]);
	  }
}



/*
 function to give user access to choice the spacific position that he want to work with it
void HLCD_VoidSetPosition(u8 Copy_U8Row,u8 Copy_U8Coloum)
{
	if(Copy_U8Row==0)
	    {
			HLCD_VoidSendCommand(Copy_U8Coloum+128);
	    }
	else if(Copy_U8Row==1)
		{
			HLCD_VoidSendCommand(Copy_U8Coloum+64+128);
		}
}
*/

void HLCD_VoidGoToXY(u8 Copy_U8XPos,u8 Copy_U8YPos)
{
	u8 Copy_U8Address;
	if( Copy_U8XPos==0)
	{/*loc is at 1 line */
		Copy_U8Address=Copy_U8YPos;
	}
	else if( Copy_U8XPos==1)
		{ /*loc is at 2 line */
			Copy_U8Address=Copy_U8YPos+0x40;
		}
	/*set the 7th bit  and send command*/
	 HLCD_VoidSendCommand(Copy_U8Address+128);
}





/* genral WriteSpecailChar thar draw in CGRAM and disolay the result on LCD
 * the 2 comming func is seprated of it :
 * func to draw in CGRAM
 * func to display on LCD*/
void HLCD_VoidWriteSpecailCharOnce(u8* Copy_U8Pattern,u8 Copy_U8PatternNum,u8 Copy_U8XPos,u8 Copy_U8YPos)
{
	u8 Copy_U8CGRAMAddress=0,Copy_U8Iteration;

	// calculate the CGRAM address whose block is 8 bytes,knowing the address i will draw in it in CGRAM
	Copy_U8CGRAMAddress=Copy_U8PatternNum*8;

//	Force AC to pointer to CG RAM THIS WITH command by setting bit 6 ,clearing bit 7
	 HLCD_VoidSendCommand(Copy_U8CGRAMAddress+64);

	//  write the pattern into CG RAM
	 for(Copy_U8Iteration=0;Copy_U8Iteration<8;Copy_U8Iteration++)
	 {
		 HLCD_VoidSendChar(Copy_U8Pattern[Copy_U8Iteration]);
	 }

	//  go back to DDRAM to display the pattern in spacific loc at LCD
	 HLCD_VoidGoToXY(Copy_U8XPos, Copy_U8YPos);

	// display the pattern which in spacific loc in CGRAM
	 HLCD_VoidSendChar(Copy_U8PatternNum);
}



/*func to draw in CGRAM */
void HLCD_VoidWriteSpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PosInMemory)
{
	u8 localCGramAddress;
	localCGramAddress=Copy_u8PosInMemory*8;
	HLCD_VoidSendCommand(localCGramAddress+64);
	for(u8 i=0;i<8;++i)
	{
		HLCD_VoidSendChar(Copy_u8Pattern[i]);
	}

	HLCD_VoidSendCommand(HLCD_RET_HOME);
}


/*func to display on LCD */
void HLCD_VoidDisplaySpecialCharacter(u8 Copy_u8PosInMemory,u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
    HLCD_VoidGoToXY(Copy_u8XPosition,Copy_u8YPosition);

    HLCD_VoidSendChar(Copy_u8PosInMemory);

}
