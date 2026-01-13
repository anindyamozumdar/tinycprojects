#include <stdio.h>
#include "strlib.h"

int main (void)
{
    char string[] = "the great russian novel";
    strcaps(string);
    printf("%s\n", string);

    return 0;
}