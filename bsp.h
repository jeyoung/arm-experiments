#define RCC             0x40023800UL
#define RCC_CR          *((volatile unsigned long *)((RCC)+0x00UL))
#define RCC_PLLCFGR     *((volatile unsigned long *)((RCC)+0x04UL))
#define RCC_CFGR        *((volatile unsigned long *)((RCC)+0x08UL))
#define RCC_AHB1ENR     *((volatile unsigned long *)((RCC)+0x30UL))
#define RCC_APB1ENR     *((volatile unsigned long *)((RCC)+0x40UL))
#define RCC_APB2ENR     *((volatile unsigned long *)((RCC)+0x44UL))

#define FLASH           0x40023C00UL
#define FLASH_ACR       *((volatile unsigned long *)((FLASH)+0x00UL))

#define GPIOA           0x40020000UL
#define GPIOA_MODER     *((volatile unsigned long *)((GPIOA)+0x00UL))
#define GPIOA_OTYPER    *((volatile unsigned long *)((GPIOA)+0x04UL))
#define GPIOA_OSPEEDR   *((volatile unsigned long *)((GPIOA)+0x08UL))
#define GPIOA_ODR       *((volatile unsigned long *)((GPIOA)+0x14UL))

#define GPIOC           0x40020800UL
#define GPIOC_MODER     *((volatile unsigned long *)((GPIOC)+0x00UL))
#define GPIOC_OTYPER    *((volatile unsigned long *)((GPIOC)+0x04UL))
#define GPIOC_OSPEEDR   *((volatile unsigned long *)((GPIOC)+0x08UL))
#define GPIOC_ODR       *((volatile unsigned long *)((GPIOC)+0x14UL))

#define STK             0xE000E010UL
#define STK_CTRL        *((volatile unsigned long *)((STK)+0x00UL))
#define STK_LOAD        *((volatile unsigned long *)((STK)+0x04UL))
#define STK_VAL         *((volatile unsigned long *)((STK)+0x08UL))
#define STK_CALIB       *((volatile unsigned long *)((STK)+0x0CUL))

#define NVIC_ISE        0xE000E100UL
#define NVIC_ISER0      *((volatile unsigned long *)((NVIC_ISE)+0x00UL))

#define NVIC_ICE        0xE000E180UL
#define NVIC_ICER0      *((volatile unsigned long *)((NVIC_ICE)+0x00UL))

#define NVIC_ISP        0xE000E200UL
#define NVIC_ISPR0      *((volatile unsigned long *)((NVIC_ISP)+0x00UL))

#define NVIC_ICP        0xE000E280UL
#define NVIC_ICPR0      *((volatile unsigned long *)((NVIC_ICP)+0x00UL))

#define NVIC_IAB        0xE000E300UL
#define NVIC_IABR0      *((volatile unsigned long *)((NVIC_IAB)+0x00UL))

#define TIM1            0x40010000UL
#define TIM1_CR1        *((volatile unsigned long *)((TIM1)+0x00UL))
#define TIM1_DIER       *((volatile unsigned long *)((TIM1)+0x0CUL))
#define TIM1_SR         *((volatile unsigned long *)((TIM1)+0x10UL))
#define TIM1_EGR        *((volatile unsigned long *)((TIM1)+0x14UL))
#define TIM1_CNT        *((volatile unsigned long *)((TIM1)+0x24UL))
#define TIM1_PSC        *((volatile unsigned long *)((TIM1)+0x28UL))
#define TIM1_ARR        *((volatile unsigned long *)((TIM1)+0x2CUL))
#define TIM1_RCR        *((volatile unsigned long *)((TIM1)+0x30UL))

#define TIM2            0x40000000UL
#define TIM2_CR1        *((volatile unsigned long *)((TIM2)+0x00UL))
#define TIM2_DIER       *((volatile unsigned long *)((TIM2)+0x0CUL))
#define TIM2_SR         *((volatile unsigned long *)((TIM2)+0x10UL))
#define TIM2_EGR        *((volatile unsigned long *)((TIM2)+0x14UL))
#define TIM2_CNT        *((volatile unsigned long *)((TIM2)+0x24UL))
#define TIM2_PSC        *((volatile unsigned long *)((TIM2)+0x28UL))
#define TIM2_ARR        *((volatile unsigned long *)((TIM2)+0x2CUL))

void init(void);
