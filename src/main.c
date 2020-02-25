#include "echo.h"

#include <genesis.h>

void tick(void)
{
}

int main()
{
    VDP_drawText("PSG Envelope Testing", 10, 1);

    const u8 psgInstrument[] = { 0xFE, 0x00, 0xFF };

    const void* const instrumentList[] = { &psgInstrument, NULL };

    echo_init(instrumentList);

    const u8 noteOnPsg1 = 0x08;
    const u8 note = 0x50;
    const u8 endEsf = 0xFF;

    const u8 esf[] = { noteOnPsg1, note, endEsf };

    echo_play_direct(&esf);

    while (TRUE) {
        VDP_waitVSync();
        tick();
    }
    return 0;
}
