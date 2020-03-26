#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp;
  char *c = "This is runoob";
  char buffer[20];

  char *filePath = "./file.txt";
  //打开文件用于读写
  fp = fopen(filePath, "w+");

  //写入数据到文件
  fwrite(c, strlen(c) + 1, 1, fp);

  //查找文件的开头
  fseek(fp, 0, SEEK_SET);

  // 读取并显示数据
  fread(buffer, strlen(c) + 1, 1, fp);
  printf("%s\n", buffer);
  fclose(fp);

  int ret = remove(filePath);

  if (ret == 0) {
    printf("文件%s删除成功\n", filePath);
  } else {
    printf("错误！不能删除该%s文件\n", filePath);
  }

  return 0;
}