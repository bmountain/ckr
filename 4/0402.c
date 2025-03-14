#include <ctype.h>
#include <stdio.h>
#define LIM 100

int readline(char s[]);
double atof(char s[]);

int main() {
  char s[LIM];
  int ls = readline(s);
  printf("%g\n", atof(s));
}

double atof(char s[]) {
  int i;
  for (i = 0; isspace(s[i]); ++i) /* skip spaces */
    ;
  int sign = (s[i] == '-') ? -1 : 1;
  double val = 0.0;
  double power = 1.0;
  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + s[i] - '0';
  }
  if (s[i] == '.')
    ++i;
  for (; isdigit(s[i]); ++i) {
    val = 10.0 * val + s[i] - '0';
    power = 10.0 * power;
  }
  if (s[i] == 'e')
    ++i;
  int esign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }
  double epower = 0.0;
  for (; isdigit(s[i]); ++i) {
    epower = 10.0 * epower + s[i] - '0';
  }
  if (esign == -1) {
    power = power * epower;
  } else {
    power = power / epower;
  }
  return val / power;
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
