#include <genesis.h>

#define VIB_LENGTH 4

static s16 freq = 440;
static s16 vibDeltas[VIB_LENGTH] = { 0, 3, 0, -3 };
static u16 curTick = 0;
static u16 phase = 0;

void tick(void)
{
    if (curTick == 0) {
        PSG_setFrequency(0, freq + vibDeltas[phase]);

        phase++;
        if (phase == VIB_LENGTH) {
            phase = 0;
        }
    }
    curTick++;
    if (curTick == 2) {
        curTick = 0;
    }
}

int main()
{
    VDP_drawText("PSG Envelope Testing", 10, 1);

    PSG_setEnvelope(0, PSG_ENVELOPE_MAX);

    while (TRUE) {
        VDP_waitVSync();
        tick();
    }
    return 0;
}
