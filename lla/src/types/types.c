#include <stdio.h>

int main() {
  short ashort = -1; // 0xffff 1111
  int wasashort = (int) ashort;
  printf("wasashort: %i\n", wasashort);
  return 0;
}
