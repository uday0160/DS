#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = 0, rear = 0;
int visited[SIZE] = {0};

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int startNode = 0;
    visited[startNode] = 1;
    enqueue(startNode);

    printf("BFS Traversal: ");

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < SIZE; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
