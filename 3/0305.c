#include <stdio.h>
#include <string.h>
#define LIM 100

int readline(char s[]);
int readint(void);
void itox(int n, char s[]);
void reverse(char s[]);

int main() {
  int n = readint();
  char s[LIM];
  itox(n, s);
  printf("%s\n", s);
}

// 整数nの16進法表記をsに格納する
void itox(int n, char s[]) {
  int i = 0;
  do {
    int c;
    int d = n % 16;
    if (d < 10) {
      c = '0' + d;
    } else {
      c = 'A' + d - 10;
    }
    s[i++] = c;
  } while ((n /= 16) > 0);
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// 1行の入力を配列に格納しその長さを返す
int readline(char s[]) {
  int c;
  int i;
  for (i = 0; (i < LIM - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
    s[i] = c;
  }
  s[i] = '\0';
  return i;
}

// 整数の入力を受け取る
int readint(void) {
  char s[LIM];
  readline(s);
  int n = 0;
  for (int i = 0; s[i] != '\0' && s[i] != '\n'; ++i) {
    n = 10 * n + s[i] - '0';
  }
  return n;
}