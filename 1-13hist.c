#include <stdio.h>

/* print a histogram of lengths of inputted words */

#define LIMIT 30

int main()
{
  int c, i, max, w;
  int word[LIMIT];
  
  c = max = 0;
  for (i = 0; i < LIMIT; ++i)
    word[i] = 0;

  i = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == 't')
      i++;
    else {
      word[i]++;
      if (word[i] > max)
        max = word[i];
    }
  printf("word count: %d\n", i);
  for (; max > 0; --max) {
    for (w = 0; w < LIMIT; ++w) {
      if(word[w] >= max)
        putchar('*');
      else
        putchar(' ');
    }
    putchar('\n');
  }

  return 0;
}