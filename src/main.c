#include "echo.h"

#include <genesis.h>

void tick(void)
{
}

int main()
{
    VDP_drawText("PSG Envelope Testing", 10, 1);

    const u8 psgInstrument[] = { 0xFE, 0x00, 0xFF};

    const void* const instrumentList[] = {
      psgInstrument,
      NULL
    };

    echo_init(instrumentList);

    while (TRUE) {
        VDP_waitVSync();
        tick();
    }
    return 0;
}
