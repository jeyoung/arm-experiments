#define SYS_CLOCK_HZ    8000000UL

#define AHB1            0x40023800UL
#define RCC_AHB1RSTR    *((unsigned long *)((AHB1)+0x10UL))
#define RCC_AHB1ENR     *((unsigned long *)((AHB1)+0x30UL))

#define GPIOA           0x40020000UL
#define GPIOA_MODER     *((unsigned long *)((GPIOA)+0x00UL))
#define GPIOA_OTYPER    *((unsigned long *)((GPIOA)+0x04UL))
#define GPIOA_ODR       *((unsigned long *)((GPIOA)+0x14UL))

#define STK             0xE000E010
#define STK_CTRL        *((unsigned long *)((STK)+0x00UL))
#define STK_LOAD        *((unsigned long *)((STK)+0x04UL))
#define STK_VAL         *((unsigned long *)((STK)+0x08UL))
#define STK_CALIB       *((unsigned long *)((STK)+0x0CUL))

#define NVIC_ISE        0xE000E100
#define NVIC_ISER0      *((unsigned long *)((NVIC_ISE)+0x00UL))

#define NVIC_ICE        0xE000E180
#define NVIC_ICER0      *((unsigned long *)((NVIC_ICE)+0x00UL))

#define NVIC_ISP        0xE000E200
#define NVIC_ISPR0      *((unsigned long *)((NVIC_ISP)+0x00UL))

#define NVIC_ICP        0xE000E280
#define NVIC_ICPR0      *((unsigned long *)((NVIC_ICP)+0x00UL))

void nmi_handler(void);
void hardfault_handler(void);
void memfault_handler(void);
void busfault_handler(void);
void usagefault_handler(void);
void svc_handler(void);
void debug_handler(void);
void pendsv_handler(void);
void systick_handler(void);
