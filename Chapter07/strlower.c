#include <stdio.h>

void strlower (char *s)
{
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += 32;
        }
        s++;
    }
}

int main (void)
{
    char string[] = "Random String sample 123@#$";
    printf("Original string: %s\n", string);
    strlower(string);
    printf("Modified string: %s\n", string);

    return 0;
}