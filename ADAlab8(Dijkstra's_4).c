#include <stdio.h>

#define INF 9999

int main() {
    int n, cost[20][20], dist[20], visited[20];
    int i, j, src, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (i = 1; i < n; i++) {
        min = INF;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && (dist[u] + cost[u][j] < dist[j])) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", src);

    for (i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}
