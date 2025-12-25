#include <stdio.h>

int main (void)
{
    int ch;
    while ((ch = getchar()) != EOF)
        printf("%02X", ch);
    putchar('\n');

    return 0;
}