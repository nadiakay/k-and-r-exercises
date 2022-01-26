#include <stdio.h>

#define TAB 8
#define MAXLINE 80

int main()
{
  int c, count;
  count = 0;
  while ((c = getchar()) != EOF && count < MAXLINE) {
    if (c == '\t') {
      int i;
      for (i=0; i<TAB - count % TAB; ++i)
        putchar(' ');
      count += i;
    }
    else 
    {
      putchar(c);
      if (c == '\n')
        count = 0;
      else
        ++count;
    }
  }
  return 0;
}