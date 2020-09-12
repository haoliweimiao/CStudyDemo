#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int print(const long value) {
  char buffer[64] = {0};
  snprintf(buffer, sizeof(buffer), "%u", (unsigned long)value);
  printf("%s\n", buffer);
}

int main(void) {
  int i;
  struct timeval tv;

  for (i = 0; i < 4; i++) {
    gettimeofday(&tv, NULL);
    printf("%d\t%d\n", tv.tv_usec, tv.tv_sec);
    print(tv.tv_sec);
    // print(tv.tv_nsec);
    print(tv.tv_usec);
    // #include <unistd.h>
    sleep(1);
  }

  return 0;
}