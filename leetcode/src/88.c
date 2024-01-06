#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int k = nums1Size - 1, i = m - 1, j = n - 1;
    while (k >= 0 && i >=  0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            --i;
        } else {
            nums1[k] = nums2[j];
            --j;
        }
        --k;
    }

    while (i >= 0) {
        nums1[k] = nums1[i]; 
        --i;
        --k;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        --j;
        --k;
    }
}

int main() {
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};

    int m = 3, n = 3;
    int len1 = sizeof(nums1) / sizeof(int);
    int len2 = sizeof(nums2) / sizeof(int);
    merge(nums1, len1, m, nums2, len2, n);
    for (int i = 0; i < len1; i++) {
        printf("%d", nums1[i]);
        if (i != (len1 - 1)) printf(" ");
    }
    printf("\n");
    return 0;
}
