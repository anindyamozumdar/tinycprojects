#include <stdio.h>
#include <stdlib.h>

char* strrev (char *s)
{
    int len = 0;
    char *srev;

    while (*s) {
        len++;
        s++;
    }

    srev = (char *) malloc (sizeof(char) * len);
    if (!srev) {
        fprintf(stderr, "Unable to allocate memory.\n");
        exit(1);
    }

    int i = 0;
    s--;
    while (len > 0) {
        *(srev + i) = *s;
        s--;
        i++;
        len--;
    }
    *(srev + i) = '\0';

    return srev;
}

int main (void)
{
    char string[] = "Anindya Mozumdar";
    char *rev = strrev(string);
    printf("Original: %s\n", string);
    printf("Reversed: %s\n", rev);
    free(rev);

    return 0;
}