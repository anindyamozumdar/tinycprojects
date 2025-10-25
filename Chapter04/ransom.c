#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int ch;
	int r;
	srand((unsigned)time(NULL));

	while ((ch = getchar()) != EOF) {
		r = rand();
		if (r % 2 == 0)
			ch = toupper(ch);
		else
			ch = tolower(ch);
		putchar(ch);
	}

	return(0);
}
