/*
 * K&R Exercise 1-21
 *
 * Print the length of arbitrarily long input lines, along with as much
 * as possible of the text within the given limit.
 */

#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = getline2(line, MAXLINE)) > 0)
  {
    if (line[len - 1] != '\n')
      while(getchar() != '\n')
        len++;
    printf("line length: %d\n", len);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0)
    printf("%s\n", longest);
  return 0;
}

/* getline: read a line into s, return length */
int getline2(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to' */
void copy(char to[], char from[])
{
  int i;

  i=0;
  while((to[i] = from[i]) != '\0')
    ++i;
}