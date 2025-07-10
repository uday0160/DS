#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(int value) {
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        position++;
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, position);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found\n", value);
}

int main() {
    int choice, value;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n2. Insert at end\n");
        printf("3. Delete a node\n4. Display list\n");
        printf("5. Search a value\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                displayList();
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

