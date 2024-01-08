#include <stdio.h>

void merge(int* nums, int left, int mid, int right);
void mergeSort(int* nums, int left, int right);

int majorityElement(int* nums, int numSize) {
  if (numSize == 1) return nums[0];
  mergeSort(nums, 0, numSize);
  int limit = numSize / 2, cnt = 1;
  int num = nums[0];
  for (int i = 1; i < numSize; i++) {
    if (nums[i - 1] == nums[i]) {
      ++cnt;
    } else {
      cnt = 1;
    }
    

    if (cnt > limit) {
      num = nums[i];
      break;
    }
  }
  return num;
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

