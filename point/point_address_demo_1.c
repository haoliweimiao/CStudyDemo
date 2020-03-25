#include <stdio.h>

void printf_address_value(int *p, char *name);
void (*fun_point)(int *, char *);

int main() {
  fun_point = printf_address_value;

  int i1 = 2333;
  int i2 = 23;

  printf_address_value(&i1, "i1");
  printf_address_value(&i2, "i2");

  int *p = &i1;

  printf_address_value(p, "p1");

  p = &i2;

  printf_address_value(p, "p2");

  i2 = 6666;
  printf_address_value(&i2, "i2");
  printf_address_value(p, "p3");

  i1 = 32457;
  printf_address_value(&i1, "i1");
  printf_address_value(p, "p4");

  (*fun_point)(p, "p5");

  return 0;
}

void printf_address_value(int *p, char *name) {
  printf("%s address:%p value:%d\n", name, p, *p);
}