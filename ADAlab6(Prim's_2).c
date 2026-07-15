//Prim's Algorithm
#include <stdio.h>

#define INF 9999

int main() {
    int n, cost[20][20], visited[20] = {0};
    int i, j;
    int min, u, v, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    // Input matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Convert 0 (no edge) to INF except diagonal
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1; // Start from vertex 0

    printf("\nEdges in MST:\n");

    for (int k = 0; k < n - 1; k++) {
        min = INF;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        total += min;

        printf("%d - %d : %d\n", u, v, min);
    }

    printf("Total cost = %d\n", total);

    return 0;
}
