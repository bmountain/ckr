#include <stdio.h>

int strend(char *s, char *t);

int main() {
  char s[] = "hoge";
  char t[] = "g";
  printf("%d\n", strend(s, t));
}

int strend(char *s, char *t) {
  char *ps, *pt;
  for (ps = s; *ps != '\0'; ++ps)
    ;
  for (pt = t; *pt != '\0'; ++pt)
    ;
  for (; *ps == *pt && ps >= s && pt >= t; ps--, pt--)
    ;
  if (pt < t) {
    return 1;
  } else {
    return 0;
  }
}