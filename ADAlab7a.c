//Floyd's algorithm
#include <stdio.h>

#define INF 999

int main() {
    int vertices;
    int graph[20][20];
    int i, j, k;

    // Read number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Read cost matrix
    printf("Enter the cost matrix (999 for INF):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Floyd-Warshall Algorithm
    for (k = 0; k < vertices; k++) {
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j] ) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Display shortest path matrix
    printf("\nShortest Path Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
