#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strsplit(char *org, int offset, char **s1, char **s2)
{
    int len;

    len = strlen(org);
    if (offset > len) {
        return 0;
    }

    *s1 = malloc(sizeof(char) * offset + 1);
    *s2 = malloc(sizeof(char) * (len - offset) + 1);
    if (s1 == NULL || s2 == NULL) {
        return 0;
    }

    strncpy(*s1, org, offset);
    strncpy(*s2, org + offset, len - offset);
    return 1;
}

int main(void)
{
    char s[] = "Anindya Mozumdar";
    char *s1;
    char *s2;

    strsplit(s, 8, &s1, &s2);
    printf("%s, %s\n", s1, s2);
    free(s1);
    free(s2);

    if (strsplit(s, 100, &s1, &s2)) {
        printf("%s, %s\n", s1, s2);
        free(s1);
        free(s2);
    }

    return 0;
}