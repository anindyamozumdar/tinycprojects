#include <stdio.h>

int main(void)
{
	int c, c2;
	int i;
	char s;

	printf("Dec Oct Hex C  Dec Oct Hex C  Dec Oct Hex C  Dec Oct Hex C\n");
	for (c = 0; c <= 31; c++) {
		for (i = 0; i <= 3; i++) {
			c2 = (32 * i) + c;
			if (c2 > 31)
				s = c2;
			else
				s = '-';
			printf("%3d %3o %3x %c", c2, c2, c2, s);
			if (i < 3)
				printf(" |");
		}
		printf("\n");
	}
	return 0;
}
