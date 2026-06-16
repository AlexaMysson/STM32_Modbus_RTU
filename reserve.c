#include <stdio.h>
#include "init.h"
#include "define.h"
#include "Address.h"

void main(){
SystemInit();
*(unsigned long*)(GPIOD) = (0x55555555);
*(unsigned long*)(GPIOA) = (0x0);
GPIOA->D_PUPDR.PUPDR0 = 0x01;
while(1)
{
      GPIOD->D_ODR.ODR12=1;
      GPIOD->D_ODR.ODR13=1;
      GPIOD->D_ODR.ODR14=1;
      GPIOD->D_ODR.ODR15=1;
   }
}
