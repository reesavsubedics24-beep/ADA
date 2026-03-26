#include <stdio.h>

int cost[10][10], vis[10], et[10][2];
int n, e = 0, sum = 0;

void prim() {
    vis[0] = 1; // start from vertex 0

    for (int k = 0; k < n - 1; k++) {
        int min = 999, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            et[e][0] = u;
            et[e][1] = v;
            e++;
            vis[v] = 1;
            sum += cost[u][v];
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        vis[i] = 0;

    prim();

    printf("\nMinimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d -> %d\n", et[i][0], et[i][1]);
    }

    printf("Total Cost: %d\n", sum);

    return 0;
}
