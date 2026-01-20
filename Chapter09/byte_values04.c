#include <stdio.h>

int main (void)
{
    unsigned char data[256];
    int b;

    for (b = 0; b <= 255; b++) {
        data[b] = b;
    }

    for (b = 0; b <= 255; b++) {
        if (b % 16 == 0) {
            printf("%05X ", (16 * b));
        }
        printf(" %02X", data[b]);
        if ((b + 1) % 8 == 0) {
            putchar(' ');
        }
        if ((b + 1) % 16 == 0) {
            putchar('\n');
        }
    }
    putchar('\n');

    return 0;
}