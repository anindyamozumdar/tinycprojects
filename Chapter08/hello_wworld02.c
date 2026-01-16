#include <wchar.h>

int main (void)
{
    wchar_t hello[] = L"Hello, wide world!";
    wprintf(L"%ls\n", hello);
    return 0;
}