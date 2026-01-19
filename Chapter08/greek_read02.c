#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main (void)
{
    const char *file = "alphabeta.wtxt";
    FILE *fp;
    wint_t ch;

    fp = fopen(file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", file);
        exit(1);
    }
    setlocale(LC_CTYPE, "en_US.UTF-8");
    wprintf(L"Reading from %s:\n", file);
    while ((ch = fgetwc(fp)) != WEOF) {
        putwchar(ch);
    }
    putwchar('\n');

    fclose(fp);

    return 0;
}