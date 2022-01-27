/*
 * K&R Exercise 1-13
 *
 * Trim multiple successive spaces down to one
 */

#include <stdio.h>

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
