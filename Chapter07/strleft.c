#include <stdio.h>
#include <stdlib.h>

char *strleft (char *s, int len)
{
    char *buf;
    int x;

    buf = (char *) malloc(sizeof(char) * (len + 1));
    if (buf == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    for (x = 0; x < len; x++) {
        if (*(s + x) == '\0') {
            break;
        }
        *(buf + x) = *(s + x);
    }
    *(buf + x) = '\0';

    return buf;
}

int main (void)
{
    char string[] = "Anindya Mozumdar";
    char *l;

    l = strleft(string, 3);
    printf("%s\n", l);
    free(l);

    l = strleft(string, 100);
    printf("%s\n", l);
    free(l);

    l = strleft(string, 16);
    printf("%s\n", l);
    free(l);

    return 0;
}