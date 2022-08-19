#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

/// Bit Manipulation
#define  SET_BIT(val,index) val=val|(1<<index)
#define  TOGGLE_BIT(val,index) val=val^(1<<index)
#define  CLR_BIT(val,index) val=val&~(1<<index)

#define  GET_BIT(val,index) ((val>>index)&1)
/* the valult will be 0 or 1   **the ture way to get bit**

 ex: get the 4th bit that is one as we count 0 1 2 3....
val=00010101
val>>index = val>>4 = 00000001
  ((val>>index)&1)= ((val>>4)&1) = 00000001 &00000001=1
   so here we get the bit from index 0 as here is 1&1=1
*/

#define  GET_BIT(val,index) val&(1<<index)
/*the valult will be 0 or the valet on the number  **the false way to get bit**

 ex: get the 4th bit that is one as we count 0 1 2 3....
val=00010101
1<<index == 1<<4 =00010000
(val&(1<<index))= (val&(1<<4))=00010101 &00010000=00010000 =64 not 1 *that is the problem*
*/

#endif