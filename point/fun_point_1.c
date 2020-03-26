#include <stdio.h>

int add(int *i, int *j) {
  (*i)++;
  (*j)++;
  return (*i) + (*j);
}

typedef int (*Fun_add)(int *, int *);

void printf_test(int *i, int *j, Fun_add fun) {
  // i,j 为地址
  int k = (*fun)(i, j);
  printf("i:%d j:%d k:%d \n", i, j, k);
}

int main() {
  int a = 2;
  int b = 22;
  int c = add(&a, &b);
  printf("a:%d b:%d c:%d \n", a, b, c);

  printf_test(&a, &b, &add);
  printf("a:%d b:%d c:%d \n", a, b, c);
  return 0;
}