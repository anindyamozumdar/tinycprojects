#include <stdio.h>

int main()
{
	int ch;

	while ((ch = getchar()) != EOF) {
		switch (ch) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				putchar('*');
				break;
			default:
				putchar(ch);
				break;
		}
	}

	return(0);
}
