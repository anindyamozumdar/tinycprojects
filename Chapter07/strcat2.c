#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strappend(char *dest, char *src)
{
    char *strapp;

    size_t destlen = strlen(dest);
    size_t srclen = strlen(src);
    strapp = (char *) malloc((destlen + srclen + 1) * sizeof(char));
    if (strapp) {
        char *d = strapp;
        char *s = dest;
        while (*s) {
            *d = *s;
            d++;
            s++;
        }
        s = src;
        while (*s) {
            *d = *s;
            d++;
            s++;
        }
        *d = '\0';
    }
    return strapp;
}

int main (void)
{
    char s1[] = "This is another ";
    char s2[] = "fine mess!";
    char *s3;
    s3 = strappend(s1, s2);
    printf("%s\n", s3);
    free(s3);

    return 0;
}