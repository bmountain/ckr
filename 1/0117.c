#include <stdio.h>
#define MAXLEN 1000
#define MAXLINE 10
#define THRESHOLD 10

int mygetline(char s[], int maxlen);
void copy(char to[], char from[]);

int main() {
  char line[MAXLEN];
  char lines[MAXLINE][MAXLEN];
  int valid_lines[MAXLINE];
  int l, i;
  i = 0;
  while ((l = mygetline(line, MAXLEN)) > 0) {
    if (l > THRESHOLD) {
      for (int k = 0; k < l; k++) {
        copy(lines[i], line);
      }
      ++i;
    }
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
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\n') {
    i++;
  }
  return;
}