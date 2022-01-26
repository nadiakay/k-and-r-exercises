#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void trimcopy(char to[], char from[], int len);

/* getline: read a line into s, return length */

int main()
{
  char line[MAXLINE];
  char c;
  int n;
  int len;

  while ((len = getline2(line, MAXLINE)) > 0)
  {
    while ((c=line[len - 1]) == ' ' || c == '\t' || c == '\n' || c == EOF)
    {
      --len;
        line[len] = EOF;
    }
    char trimmed[len];
    trimcopy(trimmed, line, len);
    printf("line: %s", trimmed);
  }

  return 0;
}

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
void trimcopy(char to[], char from[], int len)
{
  int i;
  for(i=0; i<len; ++i)
    to[i] = from[i];
  to[i] = '\n';
}