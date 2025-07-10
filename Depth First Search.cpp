#include <stdio.h>
#define SIZE 5

int visited[SIZE] = {0};

void dfs(int graph[SIZE][SIZE], int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < SIZE; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(graph, i);  
        }
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("DFS Traversal: ");
    dfs(graph, 0); 

    return 0;
}
