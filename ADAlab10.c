//Fractional Knapsack program in C:
#include <stdio.h>

int main() {
    int n;
    float W;
    float w[20], p[20], ratio[20], total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &w[i], &p[i]);
        ratio[i] = p[i] / w[i];
    }

    printf("Enter capacity: ");
    scanf("%f", &W);

    /* Sort items by decreasing profit/weight ratio (bubble sort) */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float temp;
                // swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                // swap weight
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
                // swap profit
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    /* Fractional Knapsack */
    for (int i = 0; i < n; i++) {
        if (w[i] <= W) {
            W -= w[i];
            total += p[i];
        } else {
            total += ratio[i] * W;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", total);

    return 0;
}
