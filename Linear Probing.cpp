#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->left->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->data = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->right->data = 5;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;
    root->right->left = (struct Node*)malloc(sizeof(struct Node));
    root->right->left->data = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->right->data = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    printf("Inorder Traversal: ");
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");

    printf("Preorder Traversal: ");
    top = -1;
    current = root;
    stack[++top] = current;

    while (top != -1) {
        current = stack[top--];
        if (current != NULL) {
            printf("%d ", current->data);
            stack[++top] = current->right;
            stack[++top] = current->left;
        }
    }
    printf("\n");

    printf("Postorder Traversal: ");
    top = -1;
    current = root;
    struct Node* lastVisited = NULL;

    while (top != -1 || current != NULL) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top];
        if (current->right == NULL || current->right == lastVisited) {
            printf("%d ", current->data);
            lastVisited = current;
            top--;
            current = NULL;
        } else {
            current = current->right;
        }
    }
    printf("\n");

    return 0;
}

