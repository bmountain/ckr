#include <stdio.h>
#define LIM 20

int readline(char s[]);

int main() {
  char s[LIM], t[LIM * 2];
  int l = readline(s);
  int i, j;
  i = j = 0;
  while (i < l) {
    switch (s[i]) {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    case ' ':
      t[j++] = '_';
      break;
    default:
      t[j++] = s[i];
      break;
    }
    ++i;
  }
  printf("%s\n", t);
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
