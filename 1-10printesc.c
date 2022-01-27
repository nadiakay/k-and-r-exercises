/*
 * K&R Exercise 1-13
 *
 * Copy input to output, revealing escape sequences
 */

#include <stdio.h>

int main()
{
  int c;
  while ((c=getchar()) != EOF)
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);

  return 0;
}