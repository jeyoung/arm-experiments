#include "bsp.h"

void systick_handler(void)
{
    GPIOA_ODR ^= (1 << 0x5);
}
