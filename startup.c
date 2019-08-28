#include "bsp.h"

extern unsigned long _estack;
extern unsigned long _sidata;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;

extern int main(void);

void default_handler(void);

__attribute__((naked)) void reset()
{
    unsigned long *source = &_sidata;
    unsigned long *destination = &_sdata;

    while (destination < &_edata)
    {
        *destination++ = *source++;
    }

    destination = &_sbss;
    while (destination < &_ebss)
    {
        *destination++ = 0;
    }

    main();
}

__attribute__((section(".vector")))
const unsigned long vector_table[] =
{
    (unsigned long)&_estack,
    (unsigned long)&reset,
    (unsigned long)&nmi_handler,
    (unsigned long)&hardfault_handler,
    (unsigned long)&memfault_handler,
    (unsigned long)&busfault_handler,
    (unsigned long)&usagefault_handler,
    (unsigned long)0,
    (unsigned long)0,
    (unsigned long)0,
    (unsigned long)0,
    (unsigned long)&svc_handler,
    (unsigned long)&debug_handler,
    (unsigned long)0,
    (unsigned long)&pendsv_handler,
    (unsigned long)&systick_handler,

    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (unsigned long)&tim1update_handler,
    (unsigned long)&tim1trigger_handler,
    0,
    (unsigned long)&tim2global_handler
};

void default_handler(void)
{
    while (1);
}

void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hardfault_handler(void) __attribute__((weak, alias("default_handler")));
void memfault_handler(void) __attribute__((weak, alias("default_handler")));
void busfault_handler(void) __attribute__((weak, alias("default_handler")));
void usagefault_handler(void) __attribute__((weak, alias("default_handler")));
void svc_handler(void) __attribute__((weak, alias("default_handler")));
void debug_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));
void tim1update_handler(void) __attribute__((weak, alias("default_handler")));
void tim1trigger_handler(void) __attribute__((weak, alias("default_handler")));
void tim2global_handler(void) __attribute__((weak, alias("default_handler")));
