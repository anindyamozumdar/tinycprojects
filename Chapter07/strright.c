#include <stdio.h>
#include <stdlib.h>

char *strright (char *s, int len)
{
    char *buf, *start;
    int x;

    buf = (char *) malloc(sizeof(char) * (len + 1));
    if (buf == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    start = s;
    while (*start != '\0') {
        start++;
    }
    start -= len;
    if (start < s) {
        start = s;
    }

    for (x = 0; x < len; x++) {
        if (*(s + x) == '\0') {
            break;
        }
        *(buf + x) = *(start + x);
    }
    *(buf + x) = '\0';

    return buf;
}

int main (void)
{
    char string[] = "Anindya Mozumdar";
    char *l;

    l = strright(string, 3);
    printf("%s\n", l);
    free(l);

    l = strright(string, 100);
    printf("%s\n", l);
    free(l);

    l = strright(string, 16);
    printf("%s\n", l);
    free(l);

    return 0;
}