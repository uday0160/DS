#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int queue[MAX];
    int front = -1, rear = -1, choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == MAX - 1) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    if (front == -1) {
                        front = 0;
                    }
                    rear++;
                    queue[rear] = value;
                    printf("Enqueued: %d\n", value);
                }
                break;

            case 2:
                if (front == -1 || front > rear) {
                    printf("Queue is empty\n");
                } else {
                    value = queue[front];
                    front++;
                    if (front > rear) {
                        front = rear = -1;
                    }
                    printf("Dequeued: %d\n", value);
                }
                break;

            case 3:
                if (front == -1 || front > rear) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

