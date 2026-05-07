#include <stdio.h>

int main() {

    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int indegree[n];
    int visited[n];

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize indegree and visited
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        visited[i] = 0;
    }

    // Calculate indegree
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    printf("Topological Ordering:\n");

    // Source Removal Method
    for(i = 0; i < n; i++) {

        int found = 0;

        for(j = 0; j < n; j++) {

            if(indegree[j] == 0 && visited[j] == 0) {

                printf("%d ", j);

                visited[j] = 1;
                found = 1;

                // Remove outgoing edges
                for(int k = 0; k < n; k++) {
                    if(graph[j][k] == 1) {
                        indegree[k]--;
                    }
                }

                break;
            }
        }

        // Cycle detection
        if(found == 0) {
            printf("\nGraph contains cycle. Topological ordering not possible.\n");
            return 0;
        }
    }

    return 0;
}
