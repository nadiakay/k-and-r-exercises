/* from text */

#include <stdio.h>
#define MAXLINE 40

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline2(void);
void copy(void);

/* print longest input line */
int main()
{
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while((len = getline2()) > 0) {
    if (line[len - 1] != '\n') 
      while(getchar() != '\n')
        len++;
      printf("line length: %d\n", len);
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0)
    printf("%s\n", longest);
  return 0;
}

/* getline: read a line into s, return length */
int getline2(void)
{
  extern char line[];
  int c, i;

  for (i=0; i<MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to' */
void copy(void)
{
  extern char line[];
  extern char longest[];
  int i;

  i=0;
  while((longest[i] = line[i]) != '\0')
    ++i;
}