#include <stdio.h>
#include <string.h>

typedef struct Books {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
} Book;

void printf_book_detail(Book *book);

int main() {
  Book book;

  strcpy(book.title, "C 教程");
  strcpy(book.author, "Runoob");
  strcpy(book.subject, "编程语言");
  book.book_id = 12345;

  printf_book_detail(&book);

  Book b;
  printf_book_detail(&b);

  Book b2;
  printf_book_detail(&b2);

  b = book;
  printf_book_detail(&b);

  return 0;
}

void printf_book_detail(Book *book) {
  printf("书标题 : %s\n", (*book).title);
  printf("书作者 : %s\n", (*book).author);
  printf("书类目 : %s\n", (*book).subject);
  printf("书 ID : %d\n", (*book).book_id);
  printf("book address:%p\n", &(*book));
}