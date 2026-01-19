#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    setlocale(LC_CTYPE, "en_US.UTF-8");
    
    FILE *fp;
    fp = fopen("cyrillic.wtxt", "w");
    if (fp == NULL) {
        fwprintf(stderr, L"Error opening file.\n");
        exit(1);
    }

    const wchar_t first = 0x0410;
    const wchar_t last = 0x042F;

    wchar_t a;
    for (a = first; a <= last; a++) {
        fputwc(a, fp);
        fputwc(a, stdout);
    }

    wprintf(L"\n");
    fclose(fp);

    return 0;
}