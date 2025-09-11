#include <stdio.h>

int main()
{
	int ch;
	int np = 0;

	while ((ch = getchar()) != EOF) {
		if (++np > 25) {
			np = 1;
			printf("\n");
		}
		if (ch == '\n')
			printf("\n");
		printf("%02X ", ch);
	}

	return(0);
}
