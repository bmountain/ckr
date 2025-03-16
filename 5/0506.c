#include <stdio.h>
#define LIM 100

void mygetline(char *s);
int atoi(char *s);
int itoa(char *s, int n);
void reverse(char *s);
int strindex(char *s, char c);

int main() {
  char s[LIM];
  mygetline(s);
  printf("%d\n", strindex(s, 'a'));
}

void mygetline(char *s) {
  int c;
  while ((c = getchar()) != EOF && c != '\n') {
    *s = c;
    s++;
  }
  *s = '\0';
}
int atoi(char *s) {
  int n = 0;
  for (; *s != '\0'; s++) {
    n = 10 * n + *s - '\0';
  }
  return n;
}
int itoa(char *s, int n) {
  if (n < 10) {
    *s = '0' + n;
    ++s;
    *s = '\0';
    return 1;
  }
  int d = itoa(s, n / 10);
  itoa(s + d, n % 10);
  return d + 1;
}
void reverse(char *s) {
  char *t;
  for (t = s; *(t + 1) != '\0'; t++)
    ;
  for (; s < t; ++s, --t) {
    char c = *s;
    *s = *t;
    *t = c;
  }
  return;
}
int strindex(char *s, char c) {
  int i;
  for (i = 0; *s != '\0'; s++, i++) {
    if (*s == c) {
      return i;
    }
  }
  return -1;
}
