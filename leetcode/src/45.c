#include <stdio.h>
#include <stdbool.h>

int jump(int* nums, int numsSize) {
    int steps[numsSize];
    for (int i = 0; i < numsSize; i++) {
        steps[i] = 0;
    }
    int prevIndex = 0;
    for (int i = 1; i < numsSize; i++) {
        if (prevIndex + nums[prevIndex] >= i) {
            steps[i] = steps[prevIndex] + 1;
            if (prevIndex + nums[prevIndex] == i) {
                prevIndex += 1;
                while (prevIndex <= i) {
                    if ((nums[prevIndex] + prevIndex) > i) break;
                    prevIndex += 1;
                }
            }
        }
    }
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", steps[i]);
    }
    printf("\n");
    return steps[numsSize - 1];
}


int main() {
  int nums[] = {5,9,3,2,1,0,2,3,3,1,0,0};
  int len = sizeof(nums)/sizeof(int);
  int res = jump(nums, len);

  printf("Result: %d\n", res);

  return 0;
}

