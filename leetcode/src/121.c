#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
  if (pricesSize <= 1) return 0;
  int minP = prices[0];
  int maxProfit = 0;
  for (int i = 1; i < pricesSize; i++) {
    if (prices[i] < minP) {
      minP = prices[i];
      continue;
    }

    if ((prices[i] - minP) > maxProfit) {
      maxProfit = prices[i] - minP;
    }
  }
  return maxProfit;
}

int main() {
  int nums[] = {7, 6, 4, 3, 1};
  int len = sizeof(nums) / sizeof(int);
  int m = maxProfit(nums, len);
  printf("max profit=%d\n", m);

  return 0;
}

