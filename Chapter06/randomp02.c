#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

char uppercase(void)
{
    return ('A' + (rand() % ('Z' - 'A' + 1)));
}

char lowercase(void)
{
    return ('a' + (rand() % ('z' - 'a' + 1)));
}

char number(void)
{
    return ('0' + (rand() % ('9' - '0' + 1)));
}

char symbol(void)
{
    char *symbols = "!@#$%*_-";
    return (symbols[(rand() % 8)]);
}

int main (void)
{
    int x;
    char ch;
    const int length = UPPER + LOWER + NUM + SYM;

    srand((unsigned)time(NULL));
    for (x = 0; x < length; x++) {
        if (x < UPPER)
            ch = uppercase();
        else if (x < UPPER + LOWER)
            ch = lowercase();
        else if (x < UPPER + LOWER + NUM)
            ch = number();
        else
            ch = symbol();

        putchar(ch);
    }
    putchar('\n');

    return 0;
}