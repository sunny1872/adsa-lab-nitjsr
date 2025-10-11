#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT 10002  // equivalent to 1e4 + 2

int dp[LIMIT];
int visited[LIMIT];

// Recursive function for coin change
int recur(int amount, int* coins, int n) {
    if (visited[amount]) 
        return dp[amount];
    
    if (amount == 0) {
        dp[amount] = 0;
        visited[amount] = 1;
        return 0;
    }

    int minCoins = LIMIT;
    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            int res = recur(amount - coins[i], coins, n);
            if (res != LIMIT && res + 1 < minCoins)
                minCoins = res + 1;
        }
    }

    dp[amount] = minCoins;
    visited[amount] = 1;
    return dp[amount];
}

// Comparison function for qsort (ascending order)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int coinChange(int* coins, int n, int amount) {
    for (int i = 0; i <= amount; i++) {
        dp[i] = LIMIT;
        visited[i] = 0;
    }

    // Sort the coins (like std::sort)
    qsort(coins, n, sizeof(int), compare);

    int ans = recur(amount, coins, n);
    if (ans == LIMIT) return -1;
    return ans;
}

int main() {
    int n, amount;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int* coins = (int*)malloc(n * sizeof(int));
    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);

    printf("Enter target amount: ");
    scanf("%d", &amount);

    int result = coinChange(coins, n, amount);
    printf("Minimum coins required = %d\n", result);

    free(coins);
    return 0;
}
