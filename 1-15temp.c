/*
 * K&R Exercise 1-15
 *
 * Revised temperature program using a function for conversion.
 */
#include <stdio.h>

#define	LOWER	0
#define	UPPER	300
#define	STEP	20

double temp(int fahr);

int main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	printf("%3d %6.1f\n", fahr, temp(fahr));

return 0;
}

double temp(int fahr)
{
  return (5.0/9.0) * (fahr - 32);
}