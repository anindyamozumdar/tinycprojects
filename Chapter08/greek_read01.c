#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main (void)
{
    const char *file = "alphabeta.wtxt";
    const int length = 64;
    FILE *fp;
    wchar_t line[length];

    fp = fopen(file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", file);
        exit(1);
    }
    setlocale(LC_CTYPE, "en_US.UTF-8");
    wprintf(L"Reading from %s:\n", file);
    fgetws(line, length, fp);
    wprintf(L"%ls\n", line);

    fclose(fp);

    return 0;
}