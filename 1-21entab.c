#include <stdio.h>

#define TAB 8

int main()
{
  int c, cols, blanks;
  cols = 0, blanks = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ')
    {
      ++blanks;
    }
    else if (c == '\t')
    {
      blanks += (TAB - (cols + blanks) % TAB);
    }
    else
    {
      if (blanks)
      {
        while (blanks >= TAB - cols % TAB)
        {
          blanks -= (TAB - cols % TAB);
          cols += (TAB - cols % TAB);
          printf("\t");
        }
        while (blanks > 0)
        {
          --blanks;
          ++cols;
          printf(" ");
        }
      }
      putchar(c);
      ++cols;
    }
  return 0;
}