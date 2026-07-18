//merge sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int t[10000];

    while (i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= m)
        t[k++] = a[i++];

    while (j <= r)
        t[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = t[k];

    
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of Elements: ");
    scanf("%d", &n);

    int a[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;

    printf("\nArray before sorting:\n");
    printArray(a, n);

    clock_t s = clock();
    mergesort(a, 0, n - 1);
    clock_t e = clock();

    printf("\nArray after sorting:\n");
    printArray(a, n);

    printf("\nTime = %lf seconds\n",
           (double)(e - s) / CLOCKS_PER_SEC);

    return 0;
}
