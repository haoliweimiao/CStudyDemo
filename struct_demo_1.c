//gcc struct_demo_1.c -o struct_demo_1_run
//run method ./struct_demo_1_run
#include <stdio.h>

struct Foo {
    char a;
    int b;
    double c;
}foo1, foo2;          //define two structs with three different fields

void struct_assign(void)
{
    foo2 = foo1;       //structure directly assignment
}

int main()
{
    foo1.a = 'a';
    foo1.b = 1;
    foo1.c = 3.14;
    struct_assign();
    printf("%c %d %lf\n", foo2.a, foo2.b, foo2.c);

    return 0;   
}