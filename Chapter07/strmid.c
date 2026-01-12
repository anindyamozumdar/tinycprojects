#include <stdio.h>
#include <stdlib.h>

char* mid(char *s, int offset, int len)
{
    char *buf;
    int x;

    buf = (char *)malloc(sizeof(char) * len + 1);
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    for (x = 0; x < len; x++) {
        *(buf + x) = *(s + offset - 1 + x);
        if (*(buf + x) == '\0') {
            break;
        }
    }
    *(buf + x) = '\0';

    return buf;
}

int main (void)
{
    char s[] = "Anindya Mozumdar";
    char *ret;

    ret = mid(s, 3, 3);
    printf("%s\n", ret);
    free(ret);

    ret = mid(s, 3, 100);
    printf("%s\n", ret);
    free(ret);

    ret = mid(s, 200, 5);
    printf("%s\n", ret);
    free(ret);

    return 0;
}