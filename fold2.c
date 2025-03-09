#include <stdio.h>
#define LIM 1000
#define LEN 5

int read(char s[]);

int main() {
  char s[LIM];
  int l = read(s);
  int start, end, i;
  start = end = i = 0;
  while (i < l) {
    // set end to the last non-space char before the next line
    end = end + LEN - 1;
    if (end > l - 1) {
      end = l - 1;
    }
    while (s[end] == ' ' || s[end] == '\t') {
      --end;
    }

    // print characters from start to end
    for (i = start; i <= end; ++i) {
      printf("%c", s[i]);
    }
    printf("\n");

    // set end to the next non-space char
    ++end;
    while (s[end] == ' ' || s[end] == '\t') {
      ++end;
    }
    start = end;
  }
}

// 文字配列sに入力を書き込む。その長さを返す。
int read(char s[]) {
  int c;
  int i = 0;
  while ((c = getchar()) != '\n' && c != EOF && i < LIM - 1) {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}