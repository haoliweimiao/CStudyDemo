#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  FILE *fp;
  char *file_name = "./test.txt";
  fp = fopen(file_name, "w+");

  //将内容写入文本
  fputs("hehehe,hei boy", fp);

  //将文本指针移动至第7位
  fseek(fp, 7, SEEK_SET);

  //将666666从第7位开始覆盖写入
  fputs("666666", fp);

  //指针回归文本开始
  fseek(fp, 0, SEEK_SET);

  struct stat buf;
  stat(file_name, &buf);
  //获取文本内容长度(包含结束符)
  int file_length = buf.st_size + 1;
  char buffer[file_length];
  //读取文本内容并打印
  fread(buffer, file_length, 1, fp);
  printf("file content:%s\n", buffer);

  fclose(fp);

  return 0;
}