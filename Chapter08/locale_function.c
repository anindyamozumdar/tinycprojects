#include <stdio.h>
#include <locale.h>

int main (void)
{
    char *locale;
    locale = setlocale(LC_ALL, "");
    printf("The current locale is %s\n", locale);

    return 0;
}