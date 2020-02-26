#include "echo.h"

#include <genesis.h>

static void printStatus(void)
{
    static u16 y = 1;
    u16 status = echo_get_status();
    char buffer[15];
    sprintf(buffer, "Status: %d", status);
    VDP_drawText(buffer, 1, ++y);
}

const u8 test_psg_esf[] = {
    /* set inst 1 */ 0x48, 0x08,
    /* set psg vol*/ 0x28, 0x00,
    /* note on */ 0x08, 0x38,
    /* set inst 2 */ 0x49, 0x08,
    /* set psg vol 2*/ 0x29, 0x00,
    /* note on 2 */ 0x09, 0x00,
    /* delay */ 0xfe, 0x0f,
    /* note off 1*/ 0x18,
    /* note on */ 0x08, 0x34,
    /* note off 2 */ 0x19,
    /* note on psg 2 */ 0x09, 0x04,
    /* delay */ 0xfe, 0x0f,
    0x18,
    0x08, 0x30,
    0x19,
    0x09, 0x00,
    0xfe, 0x0f,
    0x18, 0x08,
    0x34, 0x19, 0x09, 0x04, 0xfe, 0x0f, 0x18, 0x08, 0x38, 0x19, 0x09, 0x00,
    0xfe, 0x0f, 0x18, 0x08, 0x34, 0x19, 0x09, 0x04, 0xfe, 0x0f, 0x18, 0x08,
    0x30, 0x19, 0x09, 0x00, 0xfe, 0x0f, 0x18, 0x08, 0x34, 0x19, 0x09, 0x04,
    0xfe, 0x0f, 0x18, 0x08, 0x38, 0x19, 0x09, 0x00, 0xfe, 0x0f, 0x18, 0x08,
    0x34, 0x19, 0x09, 0x08, 0xfe, 0x0f, 0x18, 0x08, 0x38, 0x19, 0x09, 0x00,
    0xfe, 0x0f, 0x18, 0x08, 0x34, 0x19, 0x09, 0x08, 0xfe, 0x0f, 0x18, 0x08,
    0x38, 0x19, 0x09, 0x00, 0xfe, 0x0f, 0x18, 0x08, 0x34, 0x19, 0x09, 0x08,
    0xfe, 0x0f, 0x18, 0x08, 0x30, 0x19, 0x09, 0x00, 0xfe, 0x0f, 0x18, 0x08,
    0x34, 0x19, 0x09, 0x08, 0xfe, 0x0f, 0x18, 0x19, 0xff };

const u8 test_custom[] = {
    /* set inst 1 */ 0x48, 0x08,
    /* set psg vol*/ 0x28, 0x00,
    /* note on */ 0x08, 0x38,
    /* delay */ 0xfe, 0x00,
    0xff };

int main()
{
    VDP_drawText("PSG Envelope Testing", 10, 1);

    const void* const instrumentList[] = { NULL };

    echo_init(instrumentList);
    echo_play_bgm(test_custom);
    printStatus();

    while (TRUE) {
        VDP_waitVSync();
    }
    return 0;
}
