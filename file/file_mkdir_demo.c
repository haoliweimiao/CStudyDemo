#include <stdio.h>
#include <sys/stat.h>

int main() {

  char *filepath = "./mkdir_file_test";

  mode_t mode = umask(0);
  mkdir(filepath, 0777);
  // do something
  umask(mode);
  // do something
  return (0);
}