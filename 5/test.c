#include <stdio.h>
#define LEN 1000
int getlines(char *s);

int main() {
  char s[LEN];
  getlines(s);
  printf("%s\n", s);
}

int getlines(char *s) {
  int c;
  while ((c = getchar()) != EOF)
    *s++ = c;
  *s = '\0';
  return 0;
}