#include "echo.h"

#include <genesis.h>

const u8 test_custom[] = {
    /* set inst 1 */ 0x48, 0x08,
    /* set psg vol*/ 0x28, 0x00,
    /* note on */ 0x08, 0x38,
    /* delay */ 0xfe, 0x60,
    0xff };

const u8 instrument[] = { 0x00, 0x01, 0x02, 0x01,
 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x0C, 0x0C, 0xFE, 0x0F, 0xFF };

const void* const instrumentList[] = {
    instrument,
    instrument,
    instrument,
    instrument,
    instrument,
    instrument,
    instrument,
    instrument,
    instrument,
    NULL
};

int main()
{
    VDP_drawText("PSG Envelope Testing", 10, 1);
    echo_init(instrumentList);
    echo_play_bgm(test_custom);
    while (TRUE) {
        VDP_waitVSync();
    }
    return 0;
}
