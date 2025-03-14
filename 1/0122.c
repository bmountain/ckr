#include <stdio.h>
#define MAXLINE 1000
#define LIM 5

int main() {
  char line[MAXLINE]; // タブのスペースへの置換後の一行
  int c, l;
  for (l = 0; l < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++l) {
    line[l] = c;
  }

  int N;
  if (l % LIM == 0) {
    N = l / LIM;
  } else {
    N = l / LIM + 1;
  }
  char lines[N][LIM + 1];
  int start, end, i, n; // n: 何行目, i: n行目の何番目
  start = end = i = n = 0;
  while (start < l) {
    // endを現在行の最後の非空白文字直後にセット
    end = end + LIM;
    while (line[end - 1] == ' ' || line[end - 1] == '\t') {
      --end;
    }
    if (end > l) {
      end = l;
    }
    // endまで書き込む
    while (start < end && i < LIM) {
      lines[n][i] = line[start];
      ++start;
      ++i;
    }
    lines[n][i] = '\0';

    if (start < l - 1) {
      ++end;
      // end, startを次の非空白文字にセット
      while (line[end] == ' ' || line[end] == '\t') {
        ++end;
      }
      start = end;
      ++n; // 改行
      i = 0;
    }
  }
  printf("printing...\n");
  for (int n = 0; n < N; ++n) {
    printf("%s", lines[n]);
    printf("\n");
  }
}