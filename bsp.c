#include "bsp.h"

void init(void)
{
    RCC_AHB1ENR |= (1 << 0x0);
    GPIOA_MODER |= (1 << 0xA);

    // Enable TIM1
    RCC_APB2ENR |= (1 << 0x0);

    // Enable TIM1 counter
    TIM1_DIER   |= (1 << 0x0);
    TIM1_PSC     = 45000UL-1UL;
    TIM1_ARR     =  2000UL-1UL;
    TIM1_CR1    |= (1 << 0x0);

    NVIC_ICPR0  |= (1 << 0x19);
    NVIC_ISER0  |= (1 << 0x19);

#if 1
    __asm("CPSIE i");
#else
    __asm("CPSID i");
#endif
}

void tim1update_handler(void)
{
    __asm("CPSID i");
    if (TIM1_SR & (1 << 0x0))
    {
        GPIOA_ODR  ^=  (1 << 0x05);
        NVIC_ICPR0 |=  (1 << 0x19);
        TIM1_SR    &= ~(1 << 0x00);
    }
    __asm("CPSIE i");
}
