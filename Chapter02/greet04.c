#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	time_t now;
	struct tm *clock;
	int hour;
	char time_string[64];

	time(&now);
	clock = localtime(&now);
	hour = clock ->tm_hour;

	printf("Good ");
	if (hour < 12)
		printf("morning");
	else if (hour < 17)
		printf("afternoon");
	else
		printf("evening");

	if (argc > 1)
		printf(", %s!", argv[1]);

	putchar('\n');

	strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);
	printf("%s", time_string);

	return(0);
}
