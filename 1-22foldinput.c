/* !! incomplete !!
 *
 * K&R Exercise 1-22
 *
 * Fold long input lines into multiple shorter lines after the last non-blank
 * character occuring before the maximum column of input. Handle long lines
 * intelligently including those with no blanks or tabs.
 */

#include <stdio.h>

#define MAXLINE 20
#define TAB 8

void print_word (char word[], int cols, int blanks, int word_len);

int main()
{
  int c;
  char word[MAXLINE];
  int cols = 0, word_len = 0, blanks = 0, printword = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      if (word_len > 0)
        printword = 1;
      else
        blanks += (TAB - (cols + word_len + blanks) % TAB);
    }
    else if (c == ' ')
    {
      if (word_len > 0)
        printword = 1;
      else
        ++blanks;
    }
    else if (c == '\n')
    {
      putchar(c);
      if (word_len > 0)
        printword = 1;
    }
    else
    {
      word[word_len++] = c;
    }
    if (printword)
    {
      if (cols + blanks + word_len > MAXLINE)
      {
        printf("\n%s", word);
        cols = 0, blanks = 0;
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
        blanks += (TAB - (cols + word_len + blanks) % TAB);
      else if (c==' ')
        blanks++;
    }
  }

  return 0;
}

void print_word (char word[], int cols, int blanks, int word_len)
{
  if (cols + blanks + word_len > MAXLINE)
  {
    printf("\n%s", word);
    cols = 0, blanks = 0;
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
}