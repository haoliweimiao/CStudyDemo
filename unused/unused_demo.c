#include <stdio.h>

// gcc -g -Wall unused_demo.c -o run
// unused_demo.c: In function 'main':
// unused_demo.c:7:7: warning: unused variable 'ai' [-Wunused-variable]
//    int ai = 10;
//        ^
int main() {
  int ai = 10;
  int bi = 11;

  printf("%d\n", bi);

  return 0;
}