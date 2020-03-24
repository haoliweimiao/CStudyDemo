#include <stdio.h>

// gcc -g -Wall unused_demo_2.c -o run
int main() {
  int __attribute__((unused)) ai = 10;
  int bi = 11;

  printf("%d\n", bi);

  return 0;
}