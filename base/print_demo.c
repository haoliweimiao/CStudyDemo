#include <stdio.h>
#include <string.h>

int snprintf_() {
  printf("\n\n snprintf_ function execute");
  char buffer[50];
  char *s = "haoliweitest";

  // 读取字符串并存储在 buffer 中 "haoli'\0'"
  int j = snprintf(buffer, 6, "%s\n", s);

  // 输出 buffer及字符数
  // string:
  // haoli
  // character count = 13
  printf("string:\n%s\ncharacter count = %d\n", buffer, j);

  int test = 2333;
  int length = snprintf(buffer, sizeof(buffer), "%u", (unsigned int)test);
  printf("test = 2333, snprintf result:%d %u, buffer length:%d %d", test, test,
         strlen(buffer), length);

  return 1;
}

int printf_() {
  printf("\n\n printf_ function execute");
  char ch = 'A';
  char str[20] = "www.runoob.com";
  float flt = 10.234;
  int no = 150;
  double dbl = 20.123456;
  printf("字符为 %c \n", ch);
  printf("字符串为 %s \n", str);
  printf("浮点数为 %f \n", flt);
  printf("整数为 %d\n", no);
  printf("双精度值为 %lf \n", dbl);
  printf("八进制值为 %o \n", no);
  printf("十六进制值为 %x \n", no);
  return 1;
}

int main() {
  snprintf_();
  printf_();
  return 0;
}