/*
 * K&R Exercise 1-22
 *
 * Fold long input lines into multiple shorter lines after the last non-blank
 * character occuring before the maximum column of input. Handle long lines
 * intelligently including those with no blanks or tabs.
 */

#include <stdio.h>

#define MAXLINE 20
#define TAB 8

int main()
{
  int c;
  char word[MAXLINE];
  int cols = 0, word_len = 0, blanks = 0, printword = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      if (word_len > 0)
        printword = 1;
      else
        blanks += (TAB - (cols + word_len + blanks) % TAB);
    else if (c == ' ')
      if (word_len > 0)
        printword = 1;
      else
        ++blanks;
    else if (c == '\n')
      if (word_len > 0)
        printword = 1;
      else {
        putchar(c);
        cols = 0;
        blanks = 0;
      }
    else
      word[word_len++] = c;

    if (printword)
    {
      if (word_len > MAXLINE)
        for (int i = 0; i < word_len; i++)
        {
          if(cols + 1 == MAXLINE)
          {
            printf("-\n");
            cols = 0;
          }
          putchar(word[i]);
          cols++;
        }
      else if (cols + blanks + word_len > MAXLINE)
      {
        printf("\n%s", word);
        cols = word_len, blanks = 0;
      }
      else
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
        printf("%s", word);
        cols += word_len;
      }
      for (int i = 0; i < word_len; i++)
        word[i] = 0;
      word_len = 0;
      if (c=='\t')
        blanks += (TAB - cols % TAB);
      else if (c==' ')
        blanks++;
      else if (c=='\n')
      {
        putchar(c);
        cols = 0;
      }
      printword = 0;
    }
  }

  return 0;
}