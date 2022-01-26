#include <stdio.h>

/* trims multiple successive spaces down to one */

int main()
{
	int c, pc;

	pc = '0';
	while ((c = getchar()) != EOF)
  {
		if (!(c == pc && c == ' '))
			putchar(c);
		pc = c;
	}

	return 0;
}
