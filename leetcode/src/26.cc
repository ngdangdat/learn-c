#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  if (numsSize <= 1) return numsSize;
  // move to the right
  int insPointer = 1, iterPointer = 1;
  while (iterPointer < numsSize) {
    if (nums[iterPointer - 1] != nums[iterPointer]) {
      nums[insPointer] = nums[iterPointer];
      ++insPointer;
    }
    iterPointer++;
  }
  return insPointer;
}

int main() {
    int nums[] = {1, 1, 2};
    int len = sizeof(nums) / sizeof(int);
    int k = removeDuplicates(nums, len);
    printf("k=%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
