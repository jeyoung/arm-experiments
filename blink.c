#include "blink.h"
#include "bsp.h"

int main(void)
{
    init();

    while (1)
    {
        __asm("nop");
    }
    return 0;
}
