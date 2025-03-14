#include <stdio.h>
#define LIM 100

int readline(char s[]);
int strrindex(char s[], char t[], int ls, int lt);

char pattern[] = "ould";

int main() {
  char s[LIM];
  char t[LIM];
  int ls = readline(s);
  int lt = readline(t);

  printf("%d\n", strrindex(s, t, ls, lt));
}

// sがtを含むときその一番右のインデックスを返す。無ければ-1を返す。
int strrindex(char s[], char t[], int ls, int lt) {
  int i, j, k;
  for (i = ls - 1; i >= 0; --i) {
    for (j = i, k = lt - 1; j >= 0 && k >= 0 && s[j] == t[k]; --j, --k) {
    }
    if (k == -1) {
      return i;
    }
  }
  return -1;
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
