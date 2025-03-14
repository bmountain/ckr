#include <ctype.h>
#include <stdio.h>

#define LIM 1000

int readline(char s[]);
int todigit(int n);

int main() {
  char s[LIM];
  int l = readline(s);
  // 小文字に
  for (int i = 0; i < l; ++i) {
    s[i] = tolower(s[i]);
  }
  // 改行文字で終わるなら削除
  if (s[l - 1] == '\n') {
    s[l - 1] = '\0';
    --l;
  }
  // 0xから始まるなら削除する
  if (s[0] == '0' && s[1] == 'x') {
    for (int i = 2; i < l; ++i) {
      s[i - 2] = s[i];
    }
    s[l - 2] = '\0';
    l = l - 2;
  }

  int n = 0;
  for (int i = 0; i < l; i++) {
    n = 16 * n + todigit(s[i]);
  }
  printf("%d\n", n);
  return 0;
}

// 入力を配列に格納しその長さを返す
int readline(char s[]) {
  int c;
  int i;
  for (i = 0; (i < LIM - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

// 16進数のchar0~Fを10進法のintにして返す
int todigit(int n) {
  if ('0' <= n && n <= '9') {
    return n - '0';
  } else if ('a' <= n && n <= 'f') {
    return 10 + n - 'a';
  }
  return 1;
}