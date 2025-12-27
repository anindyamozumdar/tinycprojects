#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

void scramble (char p[])
{
    const int length = UPPER + LOWER + NUM + SYM + 1;
    char key[length];
    int x, r;

    srand((unsigned)time(NULL));

    for (x = 0; x < length; x++)
        key[x] = '\0';

    x = 0;
    while (x < (length - 1)) {
        r = rand() % (length - 1);
        if (!key[r]) {
            key[r] = p[x];
            x++;
        }
    }

    for (x = 0; x < length; x++)
        p[x] = key[x];
}

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
    char password[length + 1];

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

        password[x] = ch;
    }
    password[x] = '\0';
    scramble(password);

    printf("%s\n", password);

    return 0;
}