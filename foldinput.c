#include <stdio.h>

#define maxline 80

int c;
int line, blanks, skip_blanks = 0;

int main()
{
  while ((c = getchar()) != EOF)
    if(line < maxline)
      if (( || c=='\t') && !skip_blanks)
        if (c==' ')
          ++blanks;
        else if (c=='\t')
          blanks += tab_length;
      else
      {
        while (blanks > 0)
        {
          putchar()
        }
      }

  return 0;
}