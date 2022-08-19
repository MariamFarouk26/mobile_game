#ifndef _HLCD_Interface_H_
#define _HLCD_Interface_H_

void HLCD_VoidSendChar(u8 Copy_U8Data);

void HLCD_VoidSendCommand(u8 Copy_U8Command);

void HLCD_VoidInit();

void HLCD_VoidSendViceVersaNumberr(u32 Copy_U32Data);

void HLCD_VoidMYSendNumber(u32 Copy_U32Number);


u32 HLCD_U32PowerOfTen(u8 Copy_U8Power);
void HLCD_VoidSendNumber(u32 Copy_U32Data);

void HLCD_VoidSendString(char Copy_U8Data[48]);

void HLCD_VoidDisconnectedName(u8 Copy_U8Data[48]);

/*
void HLCD_VoidSetPosition(u8 Copy_U8Row,u8 Copy_U8Coloum);
*/

// TO DRAW CHAR
void HLCD_VoidWriteSpecialCharacter(u8* Copy_u8Pattern,u8 Copy_u8PosInMemory);

//TO Display CHAR several times
void HLCD_VoidDisplaySpecialCharacter(u8 Copy_u8PosInMemory,u8 Copy_u8XPosition,u8 Copy_u8YPosition);

// TO define the position of displaying char
void HLCD_VoidGoToXY(u8 Copy_U8XPos,u8 Copy_U8YPos);



/* TO DRAW CHAR ONCE AND USE IT ONCE * the upper 2 func is more accurate than this func as it draw the char only once and display it times as u want
 *  but this one any time you call it draw at mem then display so these take time to display*/

   void HLCD_VoidWriteSpecailCharOnce(u8 Copy_U8Pattern,u8 Copy_U8PatternNum,u8 Copy_U8XPos,u8 Copy_U8YPos);



#endif
