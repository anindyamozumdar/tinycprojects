#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strinsert(char *org, char *ins, int offset)
{
    char *new;
    int size, index, append;

    size = strlen(org) + strlen(ins);
    if (offset < 0) {
        return NULL;
    }
    new = malloc(sizeof(char) * size + 1);
    if (new == NULL) {
        fprintf(stderr, "Memory allocation error");
        exit(1);
    }

    offset -= 1;
    index = 0;
    append = 0;

    while (*org) {
        if (index == offset) {
            while (*ins) {
                *(new + index) = *ins;
                index++;
                ins++;
            }
            append = 1;
        }
        *(new + index) = *org;
        index++;
        org++;
    }

    if (!append) {
        while (*ins) {
            *(new + index) = *ins;
            index++;
            ins++;
        }
    }

    *(new + index) = '\0';

    return new;
}

int main(void)
{
    char s[] = "Anindya Mozumdar";
    char t[] = "123";
    char *ret;

    ret = strinsert(s, t, 16);
    printf("%s\n", ret);
    free(ret);

    ret = strinsert(s, t, 7);
    printf("%s\n", ret);
    free(ret);

    ret = strinsert(s, t, 50);
    printf("%s\n", ret);
    free(ret);

    return 0;
}