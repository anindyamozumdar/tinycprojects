#include <stdio.h>
#include <string.h>

int flip (char *c, int pos)
{
    *(c + pos) = *(c + pos) + 1;
    if (*(c + pos) > 'z') {
        *(c + pos) = 'a';
        if (pos != 0) {
            if (!flip(c, pos - 1))
                return 0;
        }
        else
            return 0;
    }
    return 1;
}

int main (void)
{
    char password[] = "password";
    char guess[] = "aaaaaaaa";
    char *p, *g;

    do {
        p = password;
        g = guess;
        while (*p) {
            if (*p == *g) {
                p++;
                g++;
            }
            else
                break;
        }
        if (*p == '\0' && *g == '\0') {
            printf("Found password '%s'\n", guess);
            break;
        }
    } while (flip(guess, 7));
    return 0;
}