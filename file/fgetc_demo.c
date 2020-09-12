#include <stdio.h>
#include <sys/stat.h>

int main() {
  FILE *fp;
  int c;
  int n = 0;

  char *filepath = "./file.txt";

  fp = fopen(filepath, "r");
  if (fp == NULL) {
    mode_t mode = umask(0);
    mkdir(filepath, 0777);
    // do something
    umask(mode);
    // do something
    perror("打开文件时发生错误");
    return (-1);
  }
  do {
    c = fgetc(fp);
    if (feof(fp)) {
      break;
    }
    printf("%c", c);
  } while (1);

  fclose(fp);
  return (0);
}