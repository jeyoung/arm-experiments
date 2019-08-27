#include "bsp.h"

void init(void)
{
    STK_LOAD = SYS_CLOCK_HZ/2U - 1U;
    STK_VAL = 0;
    STK_CTRL |= (1 << 0x2) | (1 << 0x1) | (1 << 0x0);

    RCC_AHB1ENR |= (1 << 0x0);
    GPIOA_MODER |= (1 << 0xA);

    __asm("CPSIE i");

}

void systick_handler(void)
{
    __asm("CPSID i");
    GPIOA_ODR ^= (1 << 0x5);
    __asm("CPSIE i");
}
