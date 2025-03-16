#include <ctype.h>
#include <stdio.h>

int getfloat(double *pf);

int main() {
  double f = 42.0;
  getfloat(&f);
  printf("%g\n", f);
}

// 標準入力から読み込んだ数を*pfに代入する
int getfloat(double *pf) {
  int c, sign;
  while (isspace(c = getchar())) // 空白を飛ばす
    ;
  if (c == '+' || c == '-') {
    sign = (c == '+') ? 1 : -1;
    c = getchar();
  }
  int i; // 整数部
  for (i = 0; isdigit(c); c = getchar()) {
    i = 10 * i + c - '0';
  }
  if (c != '.') { // 小数部がなければリターン
    if (c != EOF)
      ungetc(c, stdin);
    *pf = i;
    return 0;
  }
  c = getchar();
  int j, pow; // 小数部とオーダー
  for (j = 0, pow = 1; isdigit(c); c = getchar()) {
    j = 10 * j + c - '0';
    pow *= 10;
  }
  if (c != EOF)
    ungetc(c, stdin);
  *pf = i + (double)j / pow;
  return 0;
}