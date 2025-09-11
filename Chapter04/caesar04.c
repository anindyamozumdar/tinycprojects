#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	char s, e;
	if (argc != 3) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		exit(1);
	} else {
		s = *argv[1];
		e = *argv[2];
		if (!((s >= 'A') && (s <= 'Z'))) {
			fprintf(stderr, "Argument 1 not in range.\n");
			exit(1);
		}
		if (!((e >= 'A') && (e <= 'Z'))) {
			fprintf(stderr, "Argument 2 not in range.\n");
			exit(1);
		}
	}

	int shift, ch;
	shift = e - s;

	while ((ch = getchar()) != EOF) {
		if (isupper(ch)) {
			ch += shift;
			if (ch > 'Z') ch -= 26;
			if (ch < 'A') ch += 26;
			putchar(ch);
		}
		else if (islower(ch)) {
			ch += shift;
			if (ch > 'z') ch -= 26;
			if (ch < 'a') ch += 26;
			putchar(ch);
		}
		else {
			putchar(ch);
		}
	}

	return(0);
}
