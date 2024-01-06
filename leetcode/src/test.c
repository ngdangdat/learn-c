#include <stdio.h>

int main() {

    int nums[] = {1, 4, 3};
    int *p = &nums;
    printf("0. pointer == 0: %d\n", p == &nums[0]);
    printf("1. what is this %d\n", *p);
    p += 2;
    printf("2. what is this %d\n", *p);

    printf("3. sizeof p: %d\n", sizeof(*p));
    p[0] = 10;
    printf("4. direct assignment: %d\n", p[0]);

    return 0;
}