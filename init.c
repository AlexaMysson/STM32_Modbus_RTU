#include "Definition.h"

void SystemInit()
{
  RCC_Type* RCC_addr = (RCC_Type*)0x40023800;
  do                                
  {  
  RCC_addr->CR.HSE_ON=0x1;             // Включение тактирования от HSE
  }while(!RCC_addr->CR.HSE_RDY);    
   while(RCC_addr->PLLCFGR.PLLSRC!=1)
  {RCC_addr->PLLCFGR.PLLSRC=0x1;};       // Установка источника PLL в HSE
  do 
  {
    RCC_addr->CFGR.HPRE=0x0;             //   О
  }while(RCC_addr->CFGR.HPRE!=0x0);      //   ч
  do                                     //   и
  {                                      //   с
    RCC_addr->CFGR.I2SSCR=0x0;           //   т
  }while(RCC_addr->CFGR.I2SSCR!=0x0);    //   к        
  do                                     //   а 
  {
    RCC_addr->CFGR.MCO1=0x0;             //   р   к
  }while(RCC_addr->CFGR.MCO1!=0x0);      //   е   о                          
  do                                     //   г   н
  {                                      //   и   ф
    RCC_addr->CFGR.MCO1_PRE=0x0;         //   с   и
  }while(RCC_addr->CFGR.MCO1_PRE!=0);    //   т   г                                                            
  do                                     //   р   у
  {                                      //   а   р
    RCC_addr->CFGR.MCO2=0x0;             //       а
  }while(RCC_addr->CFGR.MCO2!=0x0);      //       ц                      
  do                                     //       и 
  {                                      //       й
    RCC_addr->CFGR.MCO2_PRE=0x0;
  }while(RCC_addr->CFGR.MCO2_PRE!=0x0);  //   с  т                                   
  do                                     //   и  а
  {                                      //   с  к
    RCC_addr->CFGR.PPRE1=0x0;            //   т  т
  }while(RCC_addr->CFGR.PPRE1!=0x0);     //   е  и                                   
  do                                     //   м  р
  {                                      //   н  о
    RCC_addr->CFGR.PPRE2=0x0;            //   о  в
  }while(RCC_addr->CFGR.PPRE2!=0x0);     //   г  а                                 
  do                                     //   о  н
  {                                      //      и
    RCC_addr->CFGR.RTCPRE=0x0;           //      я
  }while(RCC_addr->CFGR.RTCPRE!=0x0);                                      
  do                               
  {
    RCC_addr->CFGR.SW=0x2;
  }while(RCC_addr->CFGR.SW!=0x2);            // Установка System clock switch в PLL                             
  while(RCC_addr->PLLCFGR.PLLM!=0x8)
  {
    RCC_addr->PLLCFGR.PLLM=0x0;
    RCC_addr->PLLCFGR.PLLM=0x8;             // Установка главного делителя PLL 8
  };                           
  while(RCC_addr->PLLCFGR.PLLN!=0xDE)
  {
    RCC_addr->PLLCFGR.PLLN=0xDE;            // Установка главного множителя PLL 363 
  };
  while(RCC_addr->PLLCFGR.PLLP!=0x2)
  {
    RCC_addr->PLLCFGR.PLLP=0x2;             // Установка главного делителя системной частоты 2
  };
   while((RCC_addr->CR.HSE_BYP))
  {
    RCC_addr->CR.HSE_BYP=0x0;               // Сброс установки внешнего источника тактирования
  };    
     while((RCC_addr->AHB1ENR.GPIO_DEN!=0x1)) //Enable port D clocking
  {
    RCC_addr->AHB1ENR.GPIO_DEN=0x1;               
  };   
       while((RCC_addr->AHB1ENR.GPIO_AEN!=0x1)) //Enable port A clocking
  {
    RCC_addr->AHB1ENR.GPIO_AEN=0x1;  
}
       while((RCC_addr->APB2ENR.USART1!=0x1)) //Enable USART clocking
  {
    RCC_addr->APB2ENR.USART1=0x1;  
}
}