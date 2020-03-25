#include <stdio.h>

void swap1(int a, int b) {
  printf("swap enter\n");
  printf("a = %d, ptr = %p\n", a, &a);
  printf("b = %d, ptr = %p\n", a, &b);

  int tmp = b;
  b = a;
  a = tmp;

  printf("a = %d, ptr = %p\n", a, &a);
  printf("b = %d, ptr = %p\n", b, &b);
  printf("swap leave\n");
}

void test_1() {
  int x = 1;
  int y = 2;
  printf("x = %d, ptr = %p\n", x, &x);
  printf("y = %d, ptr = %p\n", y, &y);

  swap1(x, y);

  printf("x = %d, ptr = %p\n", x, &x);
  printf("y = %d, ptr = %p\n", y, &y);
}

void swap2(int *a, int *b) {
  printf("swap enter\n");
  printf("a = %d, ptr = %p\n", *a, a);
  printf("b = %d, ptr = %p\n", *a, b);

  int tmp = *b;
  *b = *a;
  *a = tmp;

  printf("a = %d, ptr = %p\n", *a, a);
  printf("b = %d, ptr = %p\n", *b, b);
  printf("swap leave\n");
}

void test_2() {
  int x = 1;
  int y = 2;
  printf("x = %d, ptr = %p\n", x, &x);
  printf("y = %d, ptr = %p\n", y, &y);

  swap2(&x, &y);

  printf("x = %d, ptr = %p\n", x, &x);
  printf("y = %d, ptr = %p\n", y, &y);
}

// void swap3(int &a, int &b) {
//   printf("swap enter\n");
//   printf("a = %d, ptr = %p\n", a, &a);
//   printf("b = %d, ptr = %p\n", a, &b);

//   int tmp = b;
//   b = a;
//   a = tmp;

//   printf("a = %d, ptr = %p\n", a, &a);
//   printf("b = %d, ptr = %p\n", b, &b);
//   printf("swap leave\n");
// }

// void test_3() {
//   int x = 1;
//   int y = 2;
//   printf("x = %d, ptr = %p\n", x, &x);
//   printf("y = %d, ptr = %p\n", y, &y);

//   swap3(x, y);

//   printf("x = %d, ptr = %p\n", x, &x);
//   printf("y = %d, ptr = %p\n", y, &y);
// }


int main() {
  test_1();
  test_2();
  //c 不支持引用传递
//   test_3();
  return 0;
}