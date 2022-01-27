/*
 * K&R Exercise 1-13
 *
 * Prints input one word per line
 */

#include <stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF) 
		if (c == ' ' || c == '\t')
			putchar('\n');
		else
			putchar(c);
	
	return 0;
}
