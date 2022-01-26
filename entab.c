#include <stdio.h>

#define TAB 8
#define MAXLINE 80

int main()
{
  int c, i, blanks;
  blanks = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ')
      ++blanks;
    else
    {
      if (blanks)
      {
        while (blanks - TAB >= 0) {
          blanks -= TAB;
          printf("\t");
        }
        while (blanks > 0) {
          blanks--;
          printf(" ");
        }
      }
      putchar(c);
    }
  return 0;
}