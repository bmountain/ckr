#include <stdio.h>
#define TABSTOP 4
#define MAXLINE 1000

void detab(char line[]);

int main() {
  int c;
  char line[MAXLINE]; // タブのスペースへの置換後の一行
  detab(line);
  printf("%s\n", line);
}

// 一行読み込んでタブをスペースに置き換える
void detab(char line[]) {
  int c;
  for (int i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n';) {
    if (c == '\t') {
      int j = i;
      while (j < i + TABSTOP) {
        line[j] = '-';
        ++j;
      }
      i = j;
    } else {
      line[i] = c;
      ++i;
    }
  }
}