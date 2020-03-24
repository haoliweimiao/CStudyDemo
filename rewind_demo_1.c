#include <stdio.h>

int main() {
  FILE *fp;
  char ch;
  if ((fp = fopen("./abc.txt", "ab+")) == NULL) {
    printf("\nCannot open file\nstrike any key exit\n");
    getchar();
    return 1;
  }
  printf("input a string:\n");
  ch = getchar();
  while (ch != '\n') {
    fputc(ch, fp);
    ch = getchar();
  }
  rewind(fp);
  ch = fgetc(fp);
  while (ch != EOF) {
    putchar(ch);
    ch = fgetc(fp);
  }
  fclose(fp);
  return 0;
}