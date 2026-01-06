#include <stdio.h>

void strupper (char *s)
{
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            *s &= 0xdf;
        }
        s++;
    }
}

int main (void)
{
    char string[] = "Random String sample 123@#$";
    printf("Original string: %s\n", string);
    strupper(string);
    printf("Modified string: %s\n", string);

    return 0;
}