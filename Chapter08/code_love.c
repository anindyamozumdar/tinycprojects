#include <wchar.h>
#include <locale.h>

int main (void)
{
    wchar_t s[] = L"I l to code";
    wchar_t lv = 0x2665;
    s[2] = lv;
    setlocale(LC_CTYPE, "en_US.UTF-8");
    wprintf(L"%ls\n", s);

    return 0;
}