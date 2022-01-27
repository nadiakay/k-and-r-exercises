/*
 * K&R Exercise 1-13
 *
 * Print a vertical histogram of the lengths of words in input
 */

#include <stdio.h>

#define LIMIT 30

int main()
{
  int c, i, max, col;
  int word[LIMIT];
  
  c = max = 0;
  for (i = 0; i < LIMIT; ++i)
    word[i] = 0;

  i = 0;
  while ((c = getchar()) != EOF)

  /* read lengths of words into word[] array, keeping track of longest word */
    if (c == ' ' || c == '\n' || c == 't')
      i++;
    else
    {
      word[i]++;
      if (word[i] > max)
        max = word[i];
    }
  printf("word count: %d\n", i);

  /* print a histogram with each column height equal to length of that word */
 
  for (; max > 0; --max)
  {
     /* loop thru rows from the highest (corresponding to longest word) on down */
    for (col = 0; col < LIMIT; ++col)
    {
    /* loop thru columns and print a '*' for each word at least as long as current row represents */

      if(word[col] >= max)
        putchar('*');
      else
        putchar(' ');
    }
    putchar('\n');
  }

  return 0;
}