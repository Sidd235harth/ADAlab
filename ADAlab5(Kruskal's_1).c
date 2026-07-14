 // Kruskal's Algorithm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[100];

// Find function (no path compression for simplicity)
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int a, int b) {
    parent[a] = b;
}

int main() {
    int n, e, i, j;
    Edge edges[100], temp;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // Input edges
    for (i = 0; i < e; i++) {
        printf("Enter u v weight: ");
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges based on weight (Bubble Sort)
    for (i = 0; i < e - 1; i++) {
        for (j = i + 1; j < e; j++) {
            if (edges[i].w > edges[j].w) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    printf("\nEdges in MST:\n");

    int cost = 0;

    // Kruskal's Algorithm
    for (i = 0; i < e; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(a, b);
        }
    }

    printf("Total cost = %d\n", cost);

    return 0;
}
