//Subset Sum Problem using Backtracking:
#include <stdio.h>

int set[20], subsetArr[20];
int n, sum;// sum= Target sum
int found = 0;// Flag to check whether a subset is found

// Backtracking function
void subset(int i, int curr, int size) // size=number of elements currently included in the subset.
{                                     //curr = currentSum
    if (curr == sum)
    {
        found = 1;
        printf("Subset found: ");
        for (int j = 0; j < size; j++)
            printf("%d ", subsetArr[j]);
        printf("\n");
        return;
    }

    if (i == n || curr > sum) // Stop if all elements are processed or current sum exceeds target sum
        return;

    // Include current element
    subsetArr[size] = set[i];
    subset(i + 1, curr + set[i], size + 1);

    // Exclude current element
    subset(i + 1, curr, size);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter sum: ");
    scanf("%d", &sum);

    subset(0, 0, 0);

    if (found == 0)
        printf("No subset found with the given sum\n");

    return 0;
}
