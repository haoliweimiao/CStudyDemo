// gcc struct_demo_1.c -o struct_demo_1_run
// run method ./struct_demo_1_run
#include <stdio.h>

struct Foo {
  char a;
  int b;
  double c;
} foo1, foo2; // define two structs with three different fields

void struct_assign(void) {
  foo2 = foo1; // structure directly assignment
}

void printf_Foo(struct Foo *f);

int main() {
  foo1.a = 'a';
  foo1.b = 1;
  foo1.c = 3.14;
  printf_Foo(&foo1);
  printf_Foo(&foo2);
  struct_assign();
  printf_Foo(&foo1);
  printf_Foo(&foo2);

  return 0;
}

void printf_Foo(struct Foo *f) {
  printf("address:%p \n a:%c b:%d c:%f\n", &((*f)), (*f).a, (*f).b, (*f).c);
}