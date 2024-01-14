#include <stdio.h>

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


int hIndex(int* citations, int citationsSize) {
    if (citationsSize == 1) {
        if (citations[0] == 0) return 0;
        return 1;
    }
    mergeSort(citations, 0, citationsSize - 1);
    for (int i = 0; i < citationsSize; i++) {
        printf("%d ", citations[i]);
    }
    printf("\n");

    for (int i = citationsSize - 1; i >= 0; i--) {
        int citation = citations[i];
        printf("i=%d, citation=%d, (citationsSize - i + 1)=%d\n", i, citation, (citationsSize - i));
        if (citation == (citationsSize - i)) {
            return citation;
        }
    }
    return 0;
}

int main() {
    int nums[] = {1, 0};
    int len = sizeof(nums)/sizeof(int);
    int h = hIndex(nums, len);
    printf("h index: %d\n", h);
    return 0;
}

