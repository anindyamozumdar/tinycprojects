#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;

	while ((ch = getchar()) != EOF) {
		ch = toupper(ch);
		putchar(ch);
	}

	return(0);
}
