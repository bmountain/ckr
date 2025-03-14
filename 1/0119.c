#include <stdio.h>
#define MAXLEN 100
#define MAXLINE 100

void reverse(char s[], int length);
int readline(char s[]);

int main() {
  char line[MAXLEN];
  char lines[MAXLEN][MAXLINE];
  int length;
  int i;
  for (i = 0; (i < MAXLINE) && ((length = readline(line)) > 0); ++i) {
    reverse(line, length);
    for (int j = 0; j < length; ++j) {
      lines[i][j] = line[j];
    }
  }

  printf("reversing...");
  for (int k = 0; k < i; k++) {
    printf("%s", lines[k]);
  }
  printf("\n");
}

// 文字列sとその長さlengthを受け取り逆転させる
void reverse(char s[], int length) {
  int n_swap = length / 2;
  for (int i = 0; i < n_swap; ++i) {
    int temp = s[length - i - 1];
    s[length - i - 1] = s[i];
    s[i] = temp;
  }
  return;
}

// 入力を配列に格納しその長さを返す
int readline(char s[]) {
  int c;
  int i;
  for (i = 0; (i < MAXLEN - 1) && ((c = getchar()) != EOF) && (c != '\n');
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