#include <stdio.h>

void merge(int* nums, int left, int mid, int right);
void mergeSort(int* nums, int left, int right);

int main() {
  int nums[] = {2, 4, 1, 3, 7, 6, 5};
  int len = sizeof(nums) / sizeof(int);
  mergeSort(nums, 0, len);
  for (int i = 0; i < len; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}


void merge(int* nums, int left, int mid, int right) {
  int leftNum = mid - left;
  int rightNum = right - mid;
  int leftArr[leftNum], rightArr[rightNum];
  for (int i = left; i < mid; i++) {
    leftArr[i - left] = nums[i];
  }
  for (int i = mid; i < right; i++) {
    rightArr[i - mid] = nums[i];
  }
  int i = 0, j = 0, k = left;
  while ((i < leftNum) && (j < rightNum)) {
    if (leftArr[i] < rightArr[j]) {
      nums[k] = leftArr[i];
      ++i;
    } else {
      nums[k] = rightArr[j];
      ++j;
    }
    k++;
  }
  while (i < leftNum) {
    nums[k] = leftArr[i];
    ++i;
    ++k;
  }

  while (j < rightNum) {
    nums[k] = rightArr[j];
    ++j;
    ++k;
  }
}


void mergeSort(int* nums, int left, int right) {
  if (left < right - 1) {
    int mid = (right + left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid, right);
    merge(nums, left, mid, right);
  }
}

