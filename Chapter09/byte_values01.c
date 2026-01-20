#include <stdio.h>

int main (void)
{
    unsigned char a;
    a = 0;
    while (1) {
        printf("%d\n", a);
        if (a == 255) {
            break;
        }
        a++;
    }
    // for (a = 0; a <= 255; a++) {
    //     printf("%d\n", a);
    // }
    return 0;
}