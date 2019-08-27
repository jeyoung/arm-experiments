#include "bsp.h"
#include "blink.h"

int main(void)
{
    STK_LOAD = SYS_CLOCK_HZ/2U - 1U;
    STK_VAL = 0;
    STK_CTRL |= (1 << 0x2) | (1 << 0x1) | (1 << 0x0);

    RCC_AHB1ENR |= (1 << 0x0);
    GPIOA_MODER |= (1 << 0xA);

    __asm("CPSIE i");

    while (1)
    {
    }
    return 0;
}
