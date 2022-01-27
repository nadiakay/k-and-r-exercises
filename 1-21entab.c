/*
 * K&R Exercise 1-21
 *
 * Replace strings of blanks with the minimum number of tabs and blanks
 * needed to achieve the same spacing.
 */

#include <stdio.h>

#define TAB 8

int main()
{
  int c, cols, blanks;
  cols = 0, blanks = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      blanks += (TAB - (cols + blanks) % TAB);
    else
    {
      if (blanks)
      {
        while (blanks >= TAB - cols % TAB)
        {
          blanks -= (TAB - cols % TAB);
          cols += (TAB - cols % TAB);
          putchar('\t');
        }
        while (blanks > 0)
        {
          --blanks;
          ++cols;
          putchar(' ');
        }
      }
      putchar(c);
      ++cols;
    }
  return 0;
}