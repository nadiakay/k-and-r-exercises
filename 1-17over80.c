/*
 * K&R Exercise 1-17
 *
 * Print all input lines of over 80 characters.
 */
#include <stdio.h>
#define MAXLINE 1000
#define MINLEN 80

int getline2(char line[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];

  while((len = getline2(line, MAXLINE)) > 0)
    if(len > MINLEN)
      printf("line: %s\n", line);
      
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