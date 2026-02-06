#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    int r;

    srand((unsigned)time(NULL));
    r = rand() % 2;

    if (r) {
        fprintf(stderr, "Failed\n");
        return EXIT_FAILURE;
    } else {
        printf("Success\n");
        return EXIT_SUCCESS;
    }
}