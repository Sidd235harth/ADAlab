//0/1 Knapsack using Dynamic Programming:
#include <stdio.h>

// Function to return maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n + 1], p[n + 1];

    printf("Enter weights and profits:\n");
    for (int i = 1; i <= n; i++) {
        printf("Item %d (weight profit): ", i);
        scanf("%d %d", &w[i], &p[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // DP table
    int dp[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i] <= j)
                dp[i][j] = max(p[i] + dp[i - 1][j - w[i]],
                               dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    printf("\nMaximum profit = %d\n", dp[n][W]);

    return 0;
}
