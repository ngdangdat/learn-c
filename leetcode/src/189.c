#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
  // edge case
  if (numsSize == 1 || k == 0 || numsSize == k) return;
  
  // preprocess in case K > numsSize
  int K = k % numsSize;
  int offset = 1;
  int p = 0; 
  int curr = nums[p];
  long distance = 0;
  for (int i = 0; i < numsSize; i++) {
    int newIndex = (p + K) % (numsSize);
    int temp = nums[newIndex];
    printf("p=%d, K=%d, newIndex=%d, temp=%d, curr=%d\n", p, K, newIndex, temp, curr);
    for (int j = 0; j < numsSize; j++) {
      if (j == p) printf(">%d ", nums[j]);
      else printf("%d ", nums[j]);
    }
    printf("\n----\n");
    distance += K;
    nums[newIndex] = curr;
    curr = temp;
    p = newIndex;
    if (distance % numsSize == 0) {
      p += offset;
      curr = nums[p];
    }
  }
}

int main() {
  int nums[] = {1, 2, 3, 4};
  int len = sizeof(nums) / sizeof(int);
  int k = 2;
  printf("before\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n------------\n");
  rotate(nums, len, k);
  printf("k=%d\n", k);
  for (int i = 0; i < len; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}

