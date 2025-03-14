#include <stdio.h>
#define MAX 1000

int isopen(char c);
int isclose(char c);
int ismatch(char c, char d);

int main() {
  char line[MAX];
  line[0] = '\0';

  int c, i;
  i = 0; // 読み込んだ最後の開き括弧の次のインデックス
  while ((c = getchar()) != EOF) {
    if (isopen(c)) {
      line[i] = c;
      ++i;
    } else if (isclose(c) && i > 0) {
      if (ismatch(line[i - 1], c)) { // 括弧がマッチ
        --i;
      } else {
        printf("error\n");
        return 0;
      }
    }
  }
  if (i == 0) {
    printf("ok\n");
  }
  return 0;
}

int isopen(char c) {
  if (c == '(' || c == '{' || c == '[') {
    return 1;
  } else {
    return 0;
  }
}

int isclose(char c) {
  if (c == ')' || c == '}' || c == ']') {
    return 1;
  } else {
    return 0;
  }
}

int ismatch(char c, char d) {
  if (c == '(' && d == ')') {
    return 1;
  }
  if (c == '{' && d == '}') {
    return 1;
  }
  if (c == '[' && d == ']') {
    return 1;
  }
  return 0;
}