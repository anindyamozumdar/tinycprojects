#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void line_out (int offset, int length, unsigned char *data)
{
    int a;

    printf("%05X ", offset);

    for (a = 0; a < length; a++) {
        printf(" %02X", *(data + a));
        if ((a + 1) % 8 == 0) {
            putchar(' ');
        }
    }

    putchar(' ');
    for (a = 0; a < length; a++) {
        if (*(data + a) >= ' ' && *(data + a) <= '~') {
            putchar(*(data + a));
        } else {
            putchar(' ');
        }
    }

    putchar('\n');
}

int main (void)
{
    unsigned char data[256];
    int b;

    srand(time(NULL));
    for (b = 0; b <= 255; b++) {
        data[b] = rand() % 256;
    }

    for (b = 0; b <= 255; b += 16) {
        line_out(b * 16, 16, data + b);
    }

    return 0;
}