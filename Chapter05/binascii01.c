#include <stdio.h>

char* bin_string(char a)
{
    static char b[9];
    int i = 0;
    while (i < 8) {
        b[i] = a & 0x80 ? '1' : '0';
        a <<= 1;
        i++;
    }
    b[i] = '\0';

    return b;
}

int main(void)
{
	int c;
	char s;

	printf("Dec Binary C\n");
	for (c = 0; c <= 127; c++) {
		if (c > 31)
			s = c;
		else
			s = '-';
		printf("%3d %s %c \n", c, bin_string(c), s);
	}

	return 0;
}