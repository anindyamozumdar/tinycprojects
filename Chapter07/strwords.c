#include <stdio.h>
#include <ctype.h>

int strwords(char *s)
{
    enum {FALSE, TRUE};
    int inword = FALSE;

    int count = 0;
    while (*s) {
        if (isalpha(*s)) {
            if (!inword) {
                count++;
                inword = TRUE;
            }
        } else {
            inword = FALSE;
        }
        s++;
    }

    return count;
}

int main(void)
{
    char s[] = "This is a sample string.";
    printf("'%s' has %d words\n", s, strwords(s));

    return 0;
}