#include "bsp.h"

void init(void)
{
    // Set Flash latency
    FLASH_ACR |= (0x04 << 0x00);
    while ((FLASH_ACR & (0x0F << 0x00)) != 0x04)
        ;

    // Clock debugging
    RCC_CFGR |=  (0x03 << 0x1E); // Output PLL to MCO2 (PC9)
    RCC_CFGR |=  (0x02 << 0x15); // Output HSE to MCO1 (PA8)

    // Enable HSE
    RCC_CR      |= (0x01 << 0x10);
    while (((RCC_CR & (0x01 << 0x11)) >> 0x11) == 0)
        ;

    // Disable, then configure PLL
    // M = 4, N = 200, P = 4, source = HSE
    // (8,000,000 / 4) * (200 / 4) = 100,000,000 Hz
    RCC_CR &= ~(0x01 << 0x18);
    while (((RCC_CR & (0x01 << 0x19)) >> 0x19))
        ;

    // Important -- clear existing bits
    RCC_PLLCFGR &= ~(0x3F  << 0x00);
    RCC_PLLCFGR |=  (0x04  << 0x00);

    // Important -- clear existing bits
    RCC_PLLCFGR &= ~(0x1FF << 0x06);
    RCC_PLLCFGR |=  (0xC8  << 0x06);

    // Important -- clear existing bits
    RCC_PLLCFGR &= ~(0x03  << 0x10);
    RCC_PLLCFGR |=  (0x01  << 0x10);

    RCC_PLLCFGR |=  (0x01  << 0x16);

    // Enable PLL and wait for it to lock
    RCC_CR |= (0x01 << 0x18);
    while (((RCC_CR & (0x01 << 0x19)) >> 0x19) == 0)
        ;

    // Set source of System Clock to PLL
    RCC_CFGR |= (0x02 << 0x00);
    while (((RCC_CFGR & (0x03 << 0x02)) >> 0x02) != 0x02)
        ;

    // Configure GPIOA
    RCC_AHB1ENR   |= (0x01 << 0x00);
    GPIOA_MODER   |= (0x01 << 0x0A);
    // Set PA8 for alternate function
    GPIOA_MODER   |= (0x02 << 0x10);
    // ... and set it to high-speed
    GPIOA_OSPEEDR |= (0x11 << 0x10);

    // Configure GPIOC
    RCC_AHB1ENR   |= (0x01 << 0x02);
    // Set PC9 for alternate function
    GPIOC_MODER   |= (0x02 << 0x12);
    // ... and set it to high-speed
    GPIOC_OSPEEDR |= (0x11 << 0x12);

    // Configure TIM1
    RCC_APB2ENR   |= (0x01 << 0x00);
    TIM1_DIER     |= (0x01 << 0x00);
    TIM1_PSC       =    40000UL-1UL;
    TIM1_ARR       =     2500UL-1UL;
    TIM1_CR1      |= (0x01 << 0x00);
    TIM1_CNT       =           0x00;

    // Enable IRQ 25
    NVIC_ICPR0  |= (0x01 << 0x19);
    NVIC_ISER0  |= (0x01 << 0x19);

    __asm("CPSIE i");
}

void TIM1_UP_TIM9_Handler(void)
{
    __asm("CPSID i");
    NVIC_ICPR0 |=  (0x01 << 0x19);

    // Need to check that this IRQ is indeed from the TIM1 'update' event.
    if (TIM1_SR & (0x01 << 0x00))
    {
        GPIOA_ODR  ^=  (0x01 << 0x05);
        TIM1_SR    &= ~(0x01 << 0x00);
    }
    __asm("CPSIE i");
}
