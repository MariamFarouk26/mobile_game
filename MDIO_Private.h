/*file instead of these line    >>   #include <avr/io.h>
all of these addreses like : *((u8*)0X3A) we get it from datasheet section"register summry" */
#ifndef _MDIO_Private_H_
#define _MDIO_Private_H_

#define DDRA_REG  *((u8*)0X3A)
#define DDRB_REG  *((u8*)0X37)
#define DDRC_REG  *((u8*)0X34)
#define DDRD_REG  *((u8*)0X31)


#define PINA_REG   *((u8*)0X39)
#define PINB_REG   *((u8*)0X36)
#define PINC_REG   *((u8*)0X33)
#define PIND_REG   *((u8*)0X30)

#define PORTA_REG  *((u8*)0X3B)
#define PORTB_REG  *((u8*)0X38)
#define PORTC_REG  *((u8*)0X35)
#define PORTD_REG  *((u8*)0X32)

#endif
