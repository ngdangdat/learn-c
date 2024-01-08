#include <stdio.h>

int majorityElement(int* nums, int numSize) {
  int vote = 0, leader = 0;

  for (int i = 0; i < numSize; i++) {
    if (vote == 0) leader = nums[i];
    if (nums[i] == leader) {
      ++vote;
    } else {
      --vote;
    }
  }
  return leader;
}

int main() {
  int nums[] = {-1, 1, 1, 1, 2, 1};
  int len = sizeof(nums) / sizeof(int);
  int majorityEl = majorityElement(nums, len);
  printf("major=%d\n", majorityEl);
  for (int i = 0; i < len; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
