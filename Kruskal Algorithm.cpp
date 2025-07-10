#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 10

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];
int edgeCount = 0;

int find(int i) {
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (xroot != yroot) {
        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int vertices, i;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    printf("Enter edges (src dest weight):\n");
    for (i = 0; i < edgeCount; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    for (i = 0; i < vertices; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    qsort(edges, edgeCount, sizeof(edges[0]), compareEdges);

    printf("Edge\tWeight\n");
    for (i = 0; i < edgeCount; i++) {
        int x = find(edges[i].src);
        int y = find(edges[i].dest);
        if (x != y) {
            printf("%d - %d\t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            unionSets(x, y);
        }
    }

    return 0;
}

