#include <stdio.h>

int main (void)
{
    unsigned char data[256];
    int b;

    for (b = 0; b <= 255; b++) {
        data[b] = b;
    }

    for (b = 0; b <= 255; b++) {
        printf("%d\n", data[b]);
    }

    return 0;
}