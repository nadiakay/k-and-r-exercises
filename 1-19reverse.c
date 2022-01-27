/*
 * K&R Exercise 1-19
 *
 * Reverse input a line at a time using a function reverse(s)
 */

#include <stdio.h>

#define MAXLINE 1000

int getline2(char str[], int lim);
void reverse(char from[], char to[], int len);

int main()
{
  char line[MAXLINE];
  int len, i;

  while((len = getline2(line, MAXLINE)) > 0)
  {
    char reversed[MAXLINE];
    reverse(line, reversed, len);
    printf("reversed: %s\n", reversed);
  }

  return 0;
}

void reverse(char from[], char to[], int len)
{
  int i;

  for(i = 0; i < len - 1; ++i)
    to[i] = from[len - (i + 2)];

  to[len - 1] = '\n';
  to[len] = '\0';
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