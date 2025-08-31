#include <stdio.h>
#include <stdlib.h>

typedef enum {
  STATUS_GOOD,
  STATUS_BAD,
} status_t;

status_t foo(int **arr, size_t new_size) {
  int *temp = realloc(*arr, new_size);
  if (temp == NULL) {
    printf("memory allocation failed\n");
    return STATUS_BAD;
  }
  *arr = temp;
  return STATUS_GOOD;
}

int main() {
  int *arr = malloc(64);
  status_t res = foo(&arr, 32);
  if (res == STATUS_BAD) {
    printf("Uh oh!\n");
    return -1;
  }
  printf("Ok!\n");
  return 0;
}
