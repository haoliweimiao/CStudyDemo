#include <stdio.h>

#ifndef Object
#define Object void *
#endif

typedef struct Node {
  int *data;
  struct Node *next;
} Node;

Object add(Node o1);

int main() {
  int i1 = 2;
  int i2 = 22;

  Object o = add(&i1, &i2);
  PInteger test = (PInteger)o;
  int result = test;
  // printf("%d", result);

  return 0;
}

Object add(Object o1, Object o2) {
  PInteger i1 = (PInteger)o1;
  PInteger i2 = (PInteger)o2;
  PInteger result;
  *result = *i1 + *i2;
  return (Object)result;
}