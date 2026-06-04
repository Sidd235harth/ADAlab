//0/1 Knapsack using Dynamic Programming:
#include <stdio.h>

// Function to return the maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W;

    // Arrays for weights and profits
    int w[20], p[20];

    // DP table
    int dp[21][41];

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input weights and profits
    printf("Enter weights and profits:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &w[i], &p[i]);
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // Build DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            // Base case
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            // If current item can be included
            else if (w[i] <= j)
            {
                dp[i][j] = max(
                    p[i] + dp[i - 1][j - w[i]], // Include item
                    dp[i - 1][j]                // Exclude item
                );
            }
            // If item cannot be included
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Display maximum profit
    printf("Maximum profit = %d\n", dp[n][W]);

    return 0;
}
