#include <stdio.h>
#include <string.h>

int compare(const char *str1, const char *str2) {
  int ret = strcmp(str1, str2);

  printf("\n");
  printf("str1:%s\nstr2:%s\n", str1, str2);

  if (ret < 0) {
    printf("str1 小于 str2");
  } else if (ret > 0) {
    printf("str1 大于 str2");
  } else {
    printf("str1 等于 str2");
  }
  printf("\n\n");
}

int main() {
  char str1[15];
  char str2[15];
  int ret;

  strcpy(str1, "abcdef");
  strcpy(str2, "ABCDEF");
  compare(str1, str2);

  strcpy(str1, "abcdef");
  strcpy(str2, "abefgh");
  compare(str1, str2);

  strcpy(str1, "abcdef");
  strcpy(str2, "abcdef");
  compare(str1, str2);

  strcpy(str1, "abcdefg");
  strcpy(str2, "abcdef");
  compare(str1, str2);
  /*
str1:abcdef
str2:ABCDEF
str1 大于 str2


str1:abcdef
str2:abefgh
str1 小于 str2


str1:abcdef
str2:abcdef
str1 等于 str2


str1:abcdefg
str2:abcdef
str1 大于 str2
  */

  return (0);
}