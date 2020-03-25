#include <stdio.h>
#include <stdlib.h>

struct Foo {
  int n;
  double d[2];
  char *p_c;
} foo1, foo2;

int main() {
  char *c = (char *)malloc(4 * sizeof(char));
  c[0] = 'a';
  c[1] = 'b';
  c[2] = 'c';
  c[3] = '\0';

  foo1.n = 1;
  foo1.d[0] = 2;
  foo1.d[1] = 3;
  foo1.p_c = c;

  foo2 = foo1; // assign foo1 to foo2

  printf("%d %.2f %lf %s\n", foo2.n, foo2.d[0], foo2.d[1], foo2.p_c);

  return 0;
}