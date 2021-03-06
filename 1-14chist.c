/*
 * K&R Exercise 1-14
 *
 * Print a histogram of the frequency of different characters in input
 */

#include <stdio.h>

int main()
{

  int c, i, j;
  int ca[128];

  for(i = 0; i < 128; ++i)
    ca[i] = 0;

  while((c = getchar()) != EOF)
    ca[c]++;
  
  for(i = 0; i < 128; ++i)
  {
    putchar(i);
    putchar('\t');
    for(j = 0; j < ca[i]; j++)
      putchar('*');
    putchar('\n');
  }

  return 0;
}