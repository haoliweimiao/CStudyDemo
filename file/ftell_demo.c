#include <stdio.h>

int main() {
  FILE *fp;
  int len;

  char *file_path = "./file.txt";
  fp = fopen(file_path, "r");
  if (fp == NULL) {
    perror("打开文件错误");
    return (-1);
  }
  fseek(fp, 0, SEEK_END);

  len = ftell(fp);
  fclose(fp);

  printf("file.txt 的总大小 = %d 字节\n", len);

  return (0);
}