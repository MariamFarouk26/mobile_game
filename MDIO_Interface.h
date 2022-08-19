// this file contain all functions' prototypes and all #defines
#ifndef _MDIO_Interface_H_
#define _MDIO_Interface_H_

void MDIO_VoidSetPinDirection( u8 copy_U8Port , u8 copy_U8Pin , u8 copy_U8Dircation);
u8 MDIO_U8GetPinValue(u8 copy_U8Port , u8 copy_U8Pin );
void MDIO_VoidSetPortDirection(u8 copy_U8Port , u8 copy_U8Dircation);
void MDIO_VoidSetPinValue(u8 copy_U8Port , u8 copy_U8Pin , u8 copy_U8Value);
void MDIO_VoidSetPortValue(u8 copy_U8Port  , u8 copy_U8Value);
void MDIO_VoidTogglePin(u8 copy_U8Port , u8 copy_U8Pin );


#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW  0


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#endif

