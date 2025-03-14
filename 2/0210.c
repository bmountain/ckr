// 文字列s2の任意の文字と等しい文字s1の文字のインデックスを返す
#include <stdio.h>
#define LIM 10
int readline(char s[]);
int lower(char c);

int main() {
  char s[LIM];
  readline(s);
  for (int i = 0; s[i] != '\0'; ++i) {
    s[i] = lower(s[i]);
  }
  printf("%s\n", s);
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

int lower(char c) { return ('A' <= c && c <= 'Z') ? c + 'a' - 'A' : c; }