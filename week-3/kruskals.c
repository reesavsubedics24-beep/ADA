#include <stdio.h>

int u[10], v[10], w[10];
int parent[10];
int et[10][2];
int n, e, count = 0, sum = 0;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void kruskal() {
    // sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                int temp;
                temp = w[j]; w[j] = w[j + 1]; w[j + 1] = temp;
                temp = u[j]; u[j] = u[j + 1]; u[j + 1] = temp;
                temp = v[j]; v[j] = v[j + 1]; v[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < e; i++) {
        int pu = find(u[i]);
        int pv = find(v[i]);

        if (pu != pv) {
            et[count][0] = u[i];
            et[count][1] = v[i];
            count++;
            sum += w[i];
            parent[pu] = pv;
        }

        if (count == n - 1)
            break;
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    kruskal();

    printf("\nMinimum Spanning Tree:\n");
    for (int i = 0; i < count; i++) {
        printf("%d -> %d\n", et[i][0], et[i][1]);
    }

    printf("Total Cost: %d\n", sum);

    return 0;
}
