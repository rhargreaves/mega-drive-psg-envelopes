#include <genesis.h>

int main()
{
    VDP_drawText("PSG Envelope Testing", 10, 1);
    while (TRUE) {
        VDP_waitVSync();
    }
    return 0;
}
