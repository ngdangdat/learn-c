#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
  // set the current target to latest one
  if (numsSize <= 1) return true;
  int curTarget = numsSize - 1;
  for (int i = numsSize - 2; i >= 0; i--) {
    int steps = nums[i];
    if ((i + steps) >= curTarget) {
      curTarget = i;
    }
  }
  if (curTarget == 0) return true;
  return false;
}


int main() {
  int nums[] = {2,3,1,1,4};
  int len = sizeof(nums)/sizeof(int);
  bool res = canJump(nums, len);

  printf("Result: %d\n", res);

  return 0;
}

