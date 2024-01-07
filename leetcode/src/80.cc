#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int insPointer = 1, iterPointer = 1, count = 1;
    while (iterPointer < numsSize) {
        if (nums[iterPointer] == nums[iterPointer - 1]) {
            count += 1;
        } else {
            count = 1;
        }
        if (count <= 2) {
            nums[insPointer] = nums[iterPointer];
            ++insPointer;
        }
        ++iterPointer;
    }
    return insPointer;
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int len = sizeof(nums) / sizeof(int);
    int k = removeDuplicates(nums, len);
    printf("k=%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
