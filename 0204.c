// 文字列s2の任意の文字に等しい文字をs1から除去するプログラム
#include <stdio.h>
#define LIM 10
int readline(char s[]);
int contain(char s[], char c);

int main() {
  char s1[LIM], s2[LIM];
  readline(s1);
  readline(s2);
  int i, j; // i: reading index, j: writing index
  for (i = j = 0; s1[i] != '\0'; ++i) {
    if (!contain(s2, s1[i])) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
  printf("%s\n", s1);
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

// 文字列sに文字cが含まれるか判定する
int contain(char s[], char c) {
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c) {
      return 1;
    }
  }
  return 0;
}