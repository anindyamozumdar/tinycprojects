#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    setlocale(LC_CTYPE, "en_US.UTF-8");
    
    FILE *fp;
    fp = fopen("alphabeta.wtxt", "w");
    if (fp == NULL) {
        fwprintf(stderr, L"Error opening file.\n");
        exit(1);
    }

    const wchar_t alpha = 0x391;
    const wchar_t omega = 0x3a9;
    const wchar_t no_sigma = 0x3a2;

    wchar_t a;
    for (a = alpha; a <= omega; a++) {
        if (a == no_sigma) {
            continue;
        }
        fputwc(a, fp);
        fputwc(a, stdout);
    }

    wprintf(L"\n");
    fclose(fp);

    return 0;
}