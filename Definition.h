/*                              RCC registers                                   */
typedef struct {
  struct type_CR          /*!< RCC clock control register,        Address offset: 0x00 */ 
    {
      int HSI_ON:1;  
      int HSI_RDY:1;
      int reserv0:1;
      int HSITRIM:5;
      int HSICAL:8;
      int HSE_ON:1;
      int HSE_RDY:1;
      int HSE_BYP:1;
      int CSS_ON:1;
      int reserv1:4;
      int PLL_ON:1;
      int PLL_RDY:1;
      int PLLI2S_ON:1;
      int PLLI2S_RDY:1;
      int reserve2:4;
    }CR;                         

  struct type_PLLCFGR     /*!< RCC PLL configuration register,    Address offset: 0x04 */
    {
      unsigned int PLLM:6;
      unsigned int PLLN:9;
      unsigned int reserv0:1;
      unsigned int PLLP:2;
      unsigned int reserv1:4;
      unsigned int PLLSRC:1;
      unsigned int reserv2:1;
      unsigned int PLLQ:4;
      unsigned int reserv3:4;
    }PLLCFGR;                                     
 
  struct type_CFGR        /*!< RCC clock configuration register,  Address offset: 0x08 */ 
    {
      int SW:2;
      int SWS:2;
      int HPRE:4;
      int reserv0:2;
      int PPRE1:3;
      int PPRE2:3;
      int RTCPRE:5;
      int MCO1:2;
      int I2SSCR:1;
      int MCO1_PRE:3;
      int MCO2_PRE:3;
      int MCO2:2;
    }CFGR;                        
 
    unsigned int CIR;             /*!< RCC clock interrupt register,                                Address offset: 0x0C */
    unsigned int AHB1RSTR;        /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
    unsigned int AHB2RSTR;        /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
    unsigned int AHB3RSTR;        /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
    unsigned int RESERVED0;       /*!< Reserved, 0x1C                                                                    */
    unsigned int APB1RSTR;        /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
    unsigned int APB2RSTR;        /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
    unsigned int RESERVED1[2];    /*!< Reserved, 0x28-0x2C                                                               */

  struct type_AHB1ENR     /*!< RCC AHB1 peripheral clock register, Address offset: 0x30 */
    {
      int GPIO_AEN:1;
      int GPIO_BEN:1;
      int GPIO_CEN:1;
      int GPIO_DEN:1;
      int GPIO_EEN:1;
      int GPIO_FEN:1;
      int GPIO_GEN:1;
      int GPIO_HEN:1;
      int GPIO_IEN:1;
      int reserv0:3;
      int CRC_EN:1;              
      int reserv1:5;
      int BKPSRAMEN:1;           
      int reserv2:1; 
      int CCMDATARAMEN:1;
      int DMA1EN:1;
      int DMA2EN:1;
      int resetv2:2;
      int ETHMACEN:1;
      int ETHMACTXEN:1;
      int ETHMACRXEN:1;
      int ETHMACPTPEN:1;
      int OTGHSEN:1;
      int OTGHSULPIEN:1;
      int reserv3:1;
    }AHB1ENR;                   
  
  struct type_AHB2ENR     /*!< RCC AHB2 peripheral clock register,  Address offset: 0x34 */
    {
      int DCMIEN:1;
      int reserv0:3;  
      int CRYPEN:1;
      int HASHEN:1;
      int RNGEN:1;
      int OTGFSEN:1;
      int reserv1:12;
      int reserve2:12;
    }AHB2ENR;

  struct type_AHB3ENR     /*!< RCC AHB3 peripheral clock register,  Address offset: 0x38 */
    {
      int FMCEN:1;
      int QSPIEN:1;
      int reserv0:15;
      int reserv1:15;
    }AHB3ENR;                      
 
  unsigned int RESERVED2; /*!< Reserved, 0x3C */
  
  struct type_APB1ENR     /*!< RCC APB1 peripheral clock enable register,  Address offset: 0x40 */
    {
      int TIM2EN:1;
      int TIM3EN:1;
      int TIM4EN:1;
      int TIM5EN:1;
      int TIM6EN:1;
      int TIM7EN:1;
      int TIM12EN:1;
      int TIM13EN:1;
      int TIM14EN:1;
      int reserv0:2;
      int WWDGEN:1;
      int reserv1:2;
      int SPI2EN:1;
      int SPI3EN:1;
      int reserv2:1;
      int USART2EN:1;
      int USART3EN:1;
      int UART4EN:1;
      int UART5EN:1;
      int I2C1EN:1;
      int I2C2EN:1;
      int I2C3EN:1;
      int reserv3:1;
      int CAN1EN:1;
      int CAN2EN:1;
      int CECEN:1;
      int PWREN:1;
      int DACEN:1;
      int UART7EN:1;
      int UART8EN:1;
    }APB1ENR;                      

  struct type_APB2ENR     /*!< RCC APB2 peripheral clock enable register,  Address offset: 0x44 */
    {
      int TIM1EN:1;
      int TIM8EN:1;
      int reserv0:2;
      int USART1:1;
      int USART6:1;
      int reserv1:2;
      int ADC1EN:1;
      int ADC2EN:1;
      int ADC3EN:1;
      int SDMMC1EN:1;
      int SPI1EN:1;
      int SPI4EN:1;
      int SYSCFGREN:1;
      int reserv2:1;
      int TIM9EN:1;
      int TIM10EN:1;
      int TIM11EN:1;  
      int reserv3:1;
      int SAI1EN:1;
      int SAI2EN:1;
      int reserv4:2;
      int PWREN:1;
      int DACEN:1;
      int reserv5:6;
    }APB2ENR;                      

  unsigned int RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  unsigned int AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  unsigned int AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  unsigned int AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  unsigned int RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  unsigned int APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  unsigned int APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  unsigned int RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */ 
  
  struct BDCR_Type            /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  {
    int LSEON:1;
    int LSERDY:1;
    int LSEBYP:1;
    int reserve:5;
    int RTCSEL:2;
    int reserve1:5;
    int RTCEN:1;
    int BDRST:1;
    int reserve2:15;
  }BDCR;
 
  struct CSR_Type               /*!< RCC clock control & status register,                       Address offset: 0x74 */
  {
    int LSION:1;
    int LSIRDY:1;
    unsigned int reserve:22;
    int RMVF:1;
    int BORRSTF:1;
    int BARRSTF:1;
    int SFTRSTF:1;
    int WDGRSTF:1;
    int WWDGRSTF:1;
    int LPWRRSTF:1;
  }CSR;
  
  unsigned int RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  unsigned int SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  unsigned int PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */

}RCC_Type;

/*                              GPIO registers                                   */
typedef struct
{
    struct type_MODER
  {
    int MODER0:2;
    int MODER1:2;
    int MODER2:2;
    int MODER3:2;
    int MODER4:2;
    int MODER5:2;
    int MODER6:2;
    int MODER7:2;
    int MODER8:2;
    int MODER9:2;
    int MODER10:2;
    int MODER11:2;
    int MODER12:2;
    int MODER13:2;
    int MODER14:2;
    int MODER15:2;
   }x_MODER; /*!< GPIO port mode register,   Address offset: 0x00 */
     
   struct type_OTYPER
  {
    int OT0:1;
    int OT1:1;
    int OT2:1;
    int OT3:1;
    int OT4:1;
    int OT5:1;
    int OT6:1;
    int OT7:1;
    int OT8:1;
    int OT9:1;
    int OT10:1;
    int OT11:1;
    int OT12:1;
    int OT13:1;
    int OT14:1;
    int OT15:1;
    int reserve:16;
   }x_OTYPER; /*!< GPIO port output type register,   Address offset: 0x04 */
   
    struct type_OSPEEDR
    {
      int OSPEEDR0:2;
      int OSPEEDR1:2;
      int OSPEEDR2:2;
      int OSPEEDR3:2;
      int OSPEEDR4:2;
      int OSPEEDR5:2;
      int OSPEEDR6:2;
      int OSPEEDR7:2;
      int OSPEEDR8:2;
      int OSPEEDR9:2;
      int OSPEEDR10:2;
      int OSPEEDR11:2;
      int OSPEEDR12:2;
      int OSPEEDR13:2;
      int OSPEEDR14:2;
      int OSPEEDR15:2;
     }x_OSPEEDR; /*!< GPIO port output speed register,   Address offset: 0x08 */
     
    struct type_PUPDR
    {
      int PUPDR0:2;
      int PUPDR1:2;
      int PUPDR2:2;
      int PUPDR3:2;
      int PUPDR4:2;
      int PUPDR5:2;
      int PUPDR6:2;
      int PUPDR7:2;
      int PUPDR8:2;
      int PUPDR9:2;
      int PUPDR10:2;
      int PUPDR11:2;
      int PUPDR12:2;
      int PUPDR13:2;
      int PUPDR14:2;
      int PUPDR15:2;
     }x_PUPDR; /*!< GPIO port pull-up/pull-down register,   Address offset: 0x0C */
     
       struct type_IDR
    {
      int IDR0:1;
      int IDR1:1;
      int IDR2:1;
      int IDR3:1;
      int IDR4:1;
      int IDR5:1;
      int IDR6:1;
      int IDR7:1;
      int IDR8:1;
      int IDR9:1;
      int IDR10:1;
      int IDR11:1;
      int IDR12:1;
      int IDR13:1;
      int IDR14:1;
      int IDR15:1;
      int reserve:16;
     }x_IDR; /*!< GPIO port input data register,   Address offset: 0x10 */
     
      struct type_ODR
    {
      int ODR0:1;
      int ODR1:1;
      int ODR2:1;
      int ODR3:1;
      int ODR4:1;
      int ODR5:1;
      int ODR6:1;
      int ODR7:1;
      int ODR8:1;
      int ODR9:1;
      int ODR10:1;
      int ODR11:1;
      int ODR12:1;
      int ODR13:1;
      int ODR14:1;
      int ODR15:1;
      int reserve:16;
     }x_ODR;  /*!< GPIO port output data register ,   Address offset: 0x14 */

     struct type_BSRR
  {
    int BS0:1;
    int BS1:1;
    int BS2:1;
    int BS3:1;
    int BS4:1;
    int BS5:1;
    int BS6:1;
    int BS7:1;
    int BS8:1;
    int BS9:1;
    int BS10:1;
    int BS11:1;
    int BS12:1;
    int BS13:1;
    int BS14:1;
    int BS15:1;
    int BR0:1;
    int BR1:1;
    int BR2:1;
    int BR3:1;
    int BR4:1;
    int BR5:1;
    int BR6:1;
    int BR7:1;
    int BR8:1;
    int BR9:1;
    int BR10:1;
    int BR11:1;
    int BR12:1;
    int BR13:1;
    int BR14:1;
    int BR15:1;
   }x_BSRR; /*!< GPIO port bit set/reset register ,   Address offset: 0x18 */
   
       struct type_LCKR
    {
      int LCK0:1;
      int LCK1:1;
      int LCK2:1;
      int LCK3:1;
      int LCK4:1;
      int LCK5:1;
      int LCK6:1;
      int LCK7:1;
      int LCK8:1;
      int LCK9:1;
      int LCK10:1;
      int LCK11:1;
      int LCK12:1;
      int LCK13:1;
      int LCK14:1;
      int LCK15:1;
      int LCKK:1;
      int reserve:15;
     }x_LCKR; /*!< GPIO port configuration lock register ,   Address offset: 0x1Ñ */
  
  struct type_AFRL
    {
      int AFRL0:4;
      int AFRL1:4;
      int AFRL2:4;
      int AFRL3:4;
      int AFRL4:4;
      int AFRL5:4;
      int AFRL6:4;
      int AFRL7:4;
     }x_AFRL; /*!< GPIO alternate function low register ,   Address offset: 0x20 */
     
       struct type_AFRH
    {
      int AFRH8:4;
      int AFRH9:4;
      int AFRH10:4;
      int AFRH11:4;
      int AFRH12:4;
      int AFRH13:4;
      int AFRH14:4;
      int AFRH15:4;
     }x_AFRH;  /*!< GPIO alternate function high register ,   Address offset: 0x24 */
     
}GPIO_Type;

/*                              USART registers                                   */
typedef struct
{
    struct type_SR
  {
    int PE:1;
    int FE:1;
    int NF:1;
    int ORE:1;
    int IDLE:1;
    int RXNE:1;
    int TC:1;
    int TXE:1;
    int LBD:1;
    int CTS:1;
    int reserve:22;
   }x_SR; /*!< Status register ,   Address offset: 0x00 */
     
   struct type_DR
  {
    int DR:9;
    int reserve:23;
   }x_DR; /*!< Data register,   Address offset: 0x04 */
   
    struct type_BRR
    {
      int DIV_Fraction:4;
      int DIV_Mantissa:12;
      int reserve:16;
     }x_BRR; /*!< Baud rate register,   Address offset: 0x08 */
     
    struct type_CR1
    {
      int SBK:1;
      int RWU:1;
      int RE:1;
      int TE:1;
      int IDLEIE:1;
      int RXNEIE:1;
      int TCIE:1;
      int TXEIE:1;
      int PEIE:1;
      int PS:1;
      int PCE:1;
      int WAKE:1;
      int M:1;
      int UE:1;
      int reserve0:1;
      int OVER8:1;
      int reserve1:16;
     }x_CR1; /*!< Control register ,   Address offset: 0x0C */
     
       struct type_CR2
    {
      int ADD:4;
      int reserve0:1;
      int LBDL:1;
      int LBDIE:1;
      int reserve1:1;
      int LBCL:1;
      int CPHA:1;
      int CPOL:1;
      int CLKEN:1;
      int STOP:2;
      int LINEN:1;
      int reserve2:17;
     }x_CR2; /*!< Control register 2,   Address offset: 0x10 */
     
      struct type_CR3
    {
      int EIE:1;
      int IREN:1;
      int IRLP:1;
      int HDSEL:1;
      int NACK:1;
      int SCEN:1;
      int DMAR:1;
      int DMAT:1;
      int RTSE:1;
      int CTSE:1;
      int CTSIE:1;
      int ONEBIT:1;
      int reserve:20;
     }x_CR3;  /*!< Control register 3 ,   Address offset: 0x14 */

     struct type_GTPR
  {
    int PSC:8;
    int GT:8;
    int reserve:16;
   }x_GTPR; /*!< Guard time and prescaler register ,   Address offset: 0x18 */
}USART_Type;


/*                             TIM10,11,13,14 registers                             */     
typedef struct
{
    struct type_TIM10_CR1
  {
    int CEN:1;  
    int UDIS:1;
    int URS:1;
    int OPM:1;
    int reserve0:3;
    int ARPE:1;
    int CKD:2;
    int reserve: 22;
   }CR1; /*!< TIM control register 1,   Address offset: 0x00 */
     
   unsigned int RESERVED1[2];  /*!< Reserved, 0x04-0x08 */       
   
    struct type_TIM10_DIER
    {
     int UIE:1;
     int CC1IE:1;
     int rederve2:30;
    }DIER; 
    /*!< TIM DMA/Interrupt enable register,   Address offset: 0x0C */
     
    struct type_TIM10_SR
    {
     int UIF:1;
     int CC1IF:1;
     int reserve:7;  
     int CC1OF:1;
     int reserve0:22;  
    }SR;  /*!< TIM status register ,   Address offset: 0x10 */
     
       struct type_EGR
    {
     int UG:1;
     int CC1G:1;
     int reserve:30;
     }EGR; 
     /*!< TIM event generation register ,   Address offset: 0x14 */
     
     unsigned int TIMx_CCMR1[1];  /*!< Reserved, 0x18 */ 
     unsigned int RESERVED2[1];   /*!< Reserved, 0x1C */ 
      
     struct type_CCER
    {
      int CC1E:1;
      int CC1P:1;
      int reserve:1;
      int CC1NP:1;
      int reserve1:28;
    }CCER;  
    /*!< TIM counter ,   Address offset: 0x20 */
     
      struct type_CNT
    {
      int CNT:16;
      int reserve:16;
    }CNT;  
    /*!< TIM counter ,   Address offset: 0x24 */

     struct type_PSC
  {
    int PSC:16;
    int reserve:16;
   }PSC; /*!< TIM prescaler ,   Address offset: 0x28 */
   
       struct type_ARR
    {
      int ARR:16;
      int reserve:16;
     }ARR; /*!< TIM auto-reload register ,   Address offset: 0x2Ñ */
     
     unsigned int RESERVED3[1];  /*!< Reserved, 0x30 */ 
     
        struct type_CCR1
    {
      int ARR:16;
      int reserve:16;
    }CCR1; /*!< TIM capture/compare register 1 ,   Address offset: 0x34 */
      
     
       struct type_OR
    {
      int TI1_RMP:2;
      int reserve:30;
     }OR; /*!< TIM  option register 1  ,   Address offset: 0x50 */
      
}TIM_Type;












///*                             TIM6 and TIM7 registers                             */     
//typedef struct
//{
//    struct type_CR1
//  {
//    int CEN:1;  
//    int UDIS:1;
//    int URS:1;
//    int OPM:1;
//    int reserve0:3;
//    int ARPE:1;
//    int reserve: 24;
//   }CR1; /*!< TIM6 and TIM7 control register 1,   Address offset: 0x00 */
//     
//   struct type_CR2
//  {
//    int reserve0:4;
//    int MMS:3;
//    int reserve1:25;
//   }CR2; /*!< TIM6 and TIM7 control register 2 ,   Address offset: 0x04 */
//   
//   unsigned int RESERVED0;  /*!< Reserved, 0x08 */       
//   
//    struct type_DIER
//    {
//     int UIE:1;
//     int reserve:7;
//     int UDE:1;
//     int rederve2:13;
//    }DIER; 
//    /*!< TIM6 and TIM7 DMA/Interrupt enable register,   Address offset: 0x0C */
//     
//    struct type_SR
//    {
//     int UIF:1;
//     int reserve:31;  
//    }SR;  /*!< TIM6 and TIM7 status register ,   Address offset: 0x10 */
//     
//       struct type_EGR
//    {
//     int UG:1;
//     int reserve:31;
//     }EGR; 
//     /*!< TIM6 and TIM7 event generation register ,   Address offset: 0x14 */
//     
//     unsigned int RESERVED1[3];  /*!< Reserved, 0x18-0x20 */     
//     
//      struct type_CNT
//    {
//      int CNT:16;
//      int reserve:16;
//    }CNT;  
//    /*!< TIM6 and TIM7 counter ,   Address offset: 0x24 */
//
//     struct type_PSC
//  {
//    int PSC:16;
//    int reserve:16;
//   }PSC; /*!< TIM6 and TIM7 prescaler ,   Address offset: 0x28 */
//   
//       struct type_ARR
//    {
//      int ARR:16;
//      int reserve:16;
//     }ARR; /*!< TIM6 and TIM7 auto-reload register ,   Address offset: 0x2Ñ */
//      
//}TIM_Type;


///*                            RTC registers                             */     
//typedef struct
//{
//    struct type_TR
//  {
//    int SU:4;  
//    int ST:3;
//    int reserve0:1;
//    int MNU:4;
//    int MNT:3;
//    int reserve1:1;
//    int HU:4;
//    int HT:2;
//    int PM:1;
//    int reserve:9;
//   }TR; /*!< RTC time register,   Address offset: 0x00 */
//   
//    struct type_DR
//  {
//    int DU:4;  
//    int DT:2;
//    int reserve0:2;
//    int MU:4;
//    int MT:1;
//    int WDU:3;
//    int YU:4;
//    int YT:4;
//    int reserve1:8;
//   }DR; /*!< RTC date register,   Address offset: 0x04 */
//     
//    struct type_CR_RTC
//  {
//    int WCKSEL:3;  
//    int TSEDGE:1;
//    int REFCKON:1;
//    int BYPSHAD:1;
//    int FTM:1;
//    int DCE:1;
//    int ALRAE:1;
//    int ALRBE:1;
//    int WUTE:1;
//    int TSE:1;
//    int ALRAIE:1;
//    int ALRBIE:1;
//    int WUTIE:1;
//    int TSIE:1;
//    int ADDH1:1;
//    int SUBH1:1;
//    int BKP:1;
//    int COSEL:1;
//    int POL:1;
//    int OSEL:2;
//    int COE:1;
//    int reserve1:8;
//   }CR; /*!< RTC control register,   Address offset: 0x08 */
//          
//    struct type_ISR
//  {
//    int ALRAWF:1;
//    int ALRBWF:1;
//    int WUTWF:1;
//    int SHPF:1;
//    int INTS:1;
//    int RSF:1;
//    int INITF:1;
//    int INIT:1;
//    int ALRAF:1;
//    int ALRBF:1;
//    int WUTF:1;
//    int TSF:1;
//    int TSOVF:1;
//    int TAMP1F:1;
//    int TAMP2F:1;
//    int reserve0:17;
//   }ISR; /*!< RTC initialization and status register,   Address offset: 0x0C */
//        
//    struct type_PREV
//    {
//     int PREDIV_S:15;
//     int reserve0:1;
//     int PREDIV_A:7;
//     int reserve1:9;
//    }PREV;  /*!< RTC prescaler register,   Address offset: 0x10 */     
//     
//    struct type_WUTR
//    {
//     int WUT:16;
//     int reserve0:16;
//    }WUTR; /*!<  RTC wakeup timer register,   Address offset: 0x14 */
//     
//    struct type_CALIBR
//    {
//     int DC:5;
//     int reserve0:2;
//     int DCS:1;
//     int rederve1:24;
//    }CALIBR; 
//    /*!< RTC calibration register,   Address offset: 0x18 */     
//       
//     struct type_ALRMAR 
//    {
//     int SU:4;
//     int ST:3;
//     int MSK1:1;
//     int MNU:4;
//     int MNT:3;
//     int MSK2:1;
//     int HU:4;
//     int HT:2;
//     int PM:1;
//     int MSK3:1;
//     int DU:4;
//     int DT:2;
//     int WDSEL:1;
//     int MSK4:1;
//    }ALRMAR ; 
//    /*!< RTC alarm A register,   Address offset: 0x1C */     
//     
//     struct type_ALRMBR 
//    {
//     int SU:4;
//     int ST:3;
//     int MSK1:1;
//     int MNU:4;
//     int MNT:3;
//     int MSK2:1;
//     int HU:4;
//     int HT:2;
//     int PM:1;
//     int MSK3:1;
//     int DU:4;
//     int DT:2;
//     int WDSEL:1;
//     int MSK4:1;
//    }ALRMBR; 
//    /*!< RTC alarm B register,   Address offset: 0x20 */   
//     
//    struct type_WPR
//    {
//     int KEY:8;
//     int reserve0:24;
//    }WPR; /*!<  RTC write protection register,   Address offset: 0x24 */     
//     
//    struct type_SSR
//    {
//     int SS:16;
//     int reserve0:16;
//    }SSR; /*!<  RTC sub second register,   Address offset: 0x28 */
//     
//    struct type_SHIFTR
//    {
//     int SUBFS:15;
//     int reserve0:16;
//     int ADD1S:1;
//    }SHIFTR; /*!<  RTC shift control register,   Address offset: 0x2C */ 
//
//    struct type_TSTR
//    {
//     int SU:4;
//     int ST:3;
//     int reserve0:1;
//     int MNU:4;
//     int MNT:3;
//     int reserve1:1;
//     int HU:4;
//     int HT:2;
//     int PM:1;
//     int reserve:9;
//    }TSTR; /*!<  RTC time stamp time register,   Address offset: 0x30 */
//    
//    struct type_TSDR
//    {
//     int DU:4;
//     int DT:2;
//     int reserve0:2;
//     int MU:4;
//     int MT:1;
//     int WDU:3;
//     int reserve:16;
//    }DSTR; /*!<  RTC time stamp date register,   Address offset: 0x34 */    
//    
//    struct type_TSSSR
//    {
//     int SS:16;
//     int reserve0:16;
//    }TSSSR; /*!<  RTC timestamp sub second register (RTC_TSSSR),   Address offset: 0x38 */
//    
//    struct type_CALR
//    {
//     int CALM:9;
//     int reserve0:4;
//     int CALW16:1;
//     int CALW8:1;
//     int CALP:1;
//     int reserve1:16; 
//    }CALR; /*!<  RTC calibration register ,   Address offset: 0x3C */
//   
//    struct type_TAFCR
//    {
//     int TAMP1E:1;
//     int TAMP1ETR:1;
//     int TAMPIE:1;
//     int TAMP2E:1;
//     int TAMP2TRG:1;
//     int reserve0:2;
//     int TAMPTS:1;
//     int TAMPFREQ:3;
//     int TAMPFLT:2;
//     int TAMPPRCH:2;
//     int TAMPPUDIS:1;
//     int TAMP1INSEL:1;
//     int TSINSEL:1;
//     int ALARMOUTTYPE:1;
//     int reserve1:13;
//    }TAFCR; /*!<  RTC tamper and alternate function configuration register,   Address offset: 0x40 */
//   
//      struct type_ALRMASSR
//    {
//      int SS:15;
//      int reserve0:9;
//      int MASKSS:4;
//      int reserve1:4;
//    }ALRMASSR;  
//    /*!< RTC alarm A sub second register,   Address offset: 0x44 */ 
//
//      struct type_ALRMBSSR
//    {
//      int SS:15;
//      int reserve0:9;
//      int MASKSS:4;
//      int reserve1:4;
//    }ALRMBSSR;  
//    /*!< RTC alarm B sub second register,   Address offset: 0x48 */ 
//   
//   unsigned int BKP0R;  /*!< RTC backup registers , 0x50 */       
//   unsigned int BKP1R;  /*!< RTC backup registers , 0x54 */  
//   unsigned int BKP2R;  /*!< RTC backup registers , 0x58 */  
//   unsigned int BKP3R;  /*!< RTC backup registers , 0x5C */  
//   unsigned int BKP4R;  /*!< RTC backup registers , 0x60 */  
//   unsigned int BKP5R;  /*!< RTC backup registers , 0x64 */    
//   unsigned int BKP6R;  /*!< RTC backup registers , 0x68 */  
//   unsigned int BKP7R;  /*!< RTC backup registers , 0x6C */  
//   unsigned int BKP8R;  /*!< RTC backup registers , 0x70 */  
//   unsigned int BKP9R;  /*!< RTC backup registers , 0x74 */  
//   unsigned int BKP10R;  /*!< RTC backup registers ,0x78 */  
//   unsigned int BKP11R;  /*!< RTC backup registers ,0x7C */  
//   unsigned int BKP12R;  /*!< RTC backup registers , 0x80 */  
//   unsigned int BKP13R;  /*!< RTC backup registers , 0x84 */  
//   unsigned int BKP14R;  /*!< RTC backup registers , 0x88 */  
//   unsigned int BKP15R;  /*!< RTC backup registers , 0x8C */  
//   unsigned int BKP16R;  /*!< RTC backup registers , 0x90 */  
//   unsigned int BKP17R;  /*!< RTC backup registers , 0x94 */  
//   unsigned int BKP18R;  /*!< RTC backup registers , 0x98 */  
//   unsigned int BKP19R;  /*!< RTC backup registers , 0x9C */       
//}RTC_Type;
