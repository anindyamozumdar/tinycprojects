#include <stdio.h>
#include <ctype.h>

int main()
{
	int shift, ch;
	shift = 'A' - 'D';

	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			ch += shift;
			if ((ch > 'Z' && ch < 'a') || (ch < 'A'))
				ch += 26;
		}
		putchar(ch);
	}

	return(0);
}
