#include <stdio.h>

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main() {
  char s[] = "hbge";
  char t[] = "hbgea";
  printf("%d\n", mystrncmp(s, t, 5));
}

// tの最大n文字をsにコピー
void mystrncpy(char *s, char *t, int n) {
  for (int i = 0; i < n && *t != '\0'; ++i) {
    *s = *t;
    ++s, ++t;
  }
  *s = '\0';
}

/*
tの最大n文字をsに連結
*/
void mystrncat(char *s, char *t, int n) {
  for (; *s != '\0'; ++s)
    ;
  for (int i = 0; i < n && *t != '\0'; ++i) {
    *s = *t;
    ++s, ++t;
  }
  *s = '\0';
}

/*
tの最大n文字をsと比較
*/
int mystrncmp(char *s, char *t, int n) {
  int i;
  for (i = 0; *s == *t && *t != '\0' && *s != '\0' && i < n; s++, t++, i++)
    ;
  if (i == n) {
    return 0;
  } else {
    return *s - *t;
  }
}
