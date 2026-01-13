#include <stdio.h>
#include <string.h>

int main (void)
{
    struct str {
        char *string;
        unsigned long (*length) (const char *);
    };

    struct str s1;
    char s[] = "Anindya Mozumdar";
    s1.string = s;
    s1.length = &strlen;

    printf("The string '%s' is %lu characters long.\n", s1.string, s1.length(s1.string));

    return 0;
}