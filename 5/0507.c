#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[], int left, int right);

int main() {
  int nlines;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    myqsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error");
    return 0;
  }
}

#define MAXLEN 1000
int mygetline(char *, int);

/* readlines: read lines from input */
int redlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = mygetline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = malloc(len * sizeof(char)))) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
}