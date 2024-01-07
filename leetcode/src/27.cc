#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    /**
     * 2 pointers
     * - remove pointer from left to right
     * - iteration pointer from right to left
    */
    int i = numsSize - 1, r = 0;
    if ((numsSize == 1) && nums[0] == val) {
        return 0;
    }
    
    while (i >= 0 && i > r) {
        if (nums[r] == val) {
            while (nums[i] == val) {
                --i;
            }
            if (i <= r) break;
            nums[r] = nums[i];
            nums[i] = val;
            --i;
        }
        ++r;
    }
    return i + 1;
}


int main() {
    int nums[] = {3, 3};
    int val = 3;
    int len = sizeof(nums) / sizeof(nums[0]);
    int remain = removeElement(nums, len, val);
    printf("remain=%d\n", remain);
    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
