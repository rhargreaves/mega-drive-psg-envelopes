#include <genesis.h>

int main()
{
    VDP_drawText("PSG Envelope Testing", 10, 1);

    PSG_setFrequency(0, 440);
    PSG_setEnvelope(0, PSG_ENVELOPE_MAX);

    while (TRUE) {
        VDP_waitVSync();
    }
    return 0;
}
