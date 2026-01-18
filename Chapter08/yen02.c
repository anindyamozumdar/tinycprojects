#include <wchar.h>
#include <locale.h>

int main (void)
{
    wchar_t s[] = L"That will be $500.\n";
    wchar_t yen = 0xa5;
    setlocale(LC_CTYPE, "en_US.UTF-8");
    s[13] = yen;
    wprintf(L"%ls", s);

    return 0;
}