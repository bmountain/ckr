#include <stdio.h>
#include <string.h>
#define MAX 100

int getlines(char *s);
void tailprint(char *s, int n);
int getn(char *s[]);

int main(int argc, char *argv[]) {
  char s[MAX];
  getlines(s);
  tailprint(s, getn(argv));
  return 0;
}

int getn(char *s[]) {
  if (strcmp(s[1], "-n") == 0) {
    char *t;
    int n;
    for (t = s[2], n = 0; *t != '\0'; ++t)
      n = 10 * n + *t - '0';
    return n;
  } else {
    return -1;
  }
}

void tailprint(char *s, int n) {
  //   printf("%c", '\n');
  char *t;
  t = s;
  while (*(s++) != '\0')
    ;
  for (int i = 0; i < n && s > t; --s, i += (*s == '\n'))
    ;
  ++s;
  for (; *s != '\0'; ++s)
    printf("%c", *s);
  printf("%c", '\n');
}

int getlines(char *s) {
  int c;
  while ((c = getchar()) != EOF)
    *s++ = c;
  *s = '\0';
  return 0;
}