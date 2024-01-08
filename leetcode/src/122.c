#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
  if (pricesSize <= 1) return 0;
  int profit = 0;
  int hold = prices[0];
  for (int i = 1; i < pricesSize; i++) {
    // if the price changes direction, sell
    if (prices[i] < prices[i-1]) {
      if (prices[i-1] > hold) {
        profit += prices[i - 1] - hold;
      }
      hold = prices[i];
    }
    if (i == (pricesSize - 1) && prices[i] > hold) {
      profit += prices[i] - hold;
    }
  }
  return profit;
}

int main() {
  int nums[] = {1, 2, 3, 4, 5};
  int len = sizeof(nums) / sizeof(int);
  int m = maxProfit(nums, len);
  printf("max profit=%d\n", m);

  return 0;
}

