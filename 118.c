#include <stdio.h>
#define MAXLEN 1000
#define MAXLINE 10
#define THRESHOLD 10

int mygetline(char s[], int maxlen);
int get_nonblank_len(char s[], int len);

int main() {
  char line[MAXLEN];
  char lines[MAXLINE][MAXLEN];
  int valid_lines[MAXLINE];
  int l, i;
  i = 0;
  while ((l = mygetline(line, MAXLEN)) > 0) {
    int nl = get_nonblank_len(line, l);
    for (int j = 0; j < nl; ++j) {
      lines[i][j] = line[j];
    }
    ++i;
  }

  printf("\n");
  for (int j = 0; j < i; ++j) {
    printf("%s", lines[j]);
  }

  return 0;
}

// sに行を保存する。その長さを返す。
int mygetline(char s[], int maxlen) {
  int c, i;
  for (i = 0; (i < maxlen - 1) && ((c = getchar()) != EOF) && (c != '\n');
       ++i) {
    s[i] = c;
  }
  if ((c == '\n') && i > 1) {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int get_nonblank_len(char s[], int len) {
  int i = len - 1;
  int c;
  while (((c = s[i]) == '\t') && (c == ' ')) {
    --i;
  }
  ++i;
  s[i] = '\n';
  return i;
}