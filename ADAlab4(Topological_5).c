// Topological sorting
#include <stdio.h>

int main() {
    int n, a[20][20], indeg[20] = {0};  //indeg = The in-degree of a vertex is the "number of incoming edges to that vertex".
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n > 20) {
        printf("Maximum limit is 20 vertices.\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");

    // Input adjacency matrix and calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            indeg[j] += a[i][j];
        }
    }

    printf("Topological order:\n");

    // Topological sorting
    for (int k = 0; k < n; k++) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                printf("%d ", i);
                indeg[i] = -1;  // Mark as visited

                for (j = 0; j < n; j++) {
                    if (a[i][j] == 1) {
                        indeg[j]--;
                    }
                }

                found = 1;
                break;
            }
        }

        // Cycle detection
        if (found == 0) {
            printf("\nGraph has a cycle! Topological sort not possible.\n");
            return 0;
        }
    }

    printf("\n");
    return 0;
}
