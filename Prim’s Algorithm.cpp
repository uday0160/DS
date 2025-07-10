#include <stdio.h>
#include <limits.h>

#define V 5

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int parent[V];
    int key[V];
    int mstSet[V];
    int i, j, count, minIndex, minKey;

    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < V - 1; count++) {
        minKey = INT_MAX;

        for (i = 0; i < V; i++) {
            if (mstSet[i] == 0 && key[i] < minKey) {
                minKey = key[i];
                minIndex = i;
            }
        }

        mstSet[minIndex] = 1;

        for (j = 0; j < V; j++) {
            if (graph[minIndex][j] && mstSet[j] == 0 && graph[minIndex][j] < key[j]) {
                parent[j] = minIndex;
                key[j] = graph[minIndex][j];
            }
        }
    }

    printf("Edge\tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[parent[i]][i]);
    }

    return 0;
}

