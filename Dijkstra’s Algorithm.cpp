#include <stdio.h>
#include <limits.h>

#define V 5

int main() {
    int graph[V][V] = {
        {0, 10, 3, 0, 0},
        {10, 0, 1, 2, 0},
        {3, 1, 0, 8, 2},
        {0, 2, 8, 0, 7},
        {0, 0, 2, 7, 0}
    };

    int dist[V];
    int visited[V] = {0};
    int i, j, count, minIndex, minDist;

    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[0] = 0;

    for (count = 0; count < V - 1; count++) {
        minDist = INT_MAX;

        for (i = 0; i < V; i++) {
            if (visited[i] == 0 && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }

        visited[minIndex] = 1;

        for (j = 0; j < V; j++) {
            if (!visited[j] && graph[minIndex][j] && dist[minIndex] != INT_MAX && dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}

