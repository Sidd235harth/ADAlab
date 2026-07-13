//Warshall's Algorithm
#include <stdio.h>

int main() {
    int vertices;
    int graph[20][20];
    int i, j, k;

    // Read the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Read the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Warshall's Algorithm for Transitive Closure
    for (k = 0; k < vertices; k++) {
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }

    // Display the transitive closure matrix
    printf("\nTransitive Closure Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
