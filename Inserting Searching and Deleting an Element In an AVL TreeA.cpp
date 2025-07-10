#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter key to insert: ");
            scanf("%d", &key);
            struct Node* new_node = newNode(key);
            if (root == NULL) {
                root = new_node;
            } else {
                struct Node* current = root;
                struct Node* parent = NULL;
                while (1) {
                    parent = current;
                    if (key < current->key) {
                        current = current->left;
                        if (current == NULL) {
                            parent->left = new_node;
                            break;
                        }
                    } else if (key > current->key) {
                        current = current->right;
                        if (current == NULL) {
                            parent->right = new_node;
                            break;
                        }
                    } else {
                        free(new_node);
                        break;
                    }
                }
                current = root;
                while (current != NULL) {
                    current->height = 1 + max(height(current->left), height(current->right));
                    int balance = getBalance(current);
                    if (balance > 1 && key < current->left->key) {
                        current = rightRotate(current);
                    }
                    if (balance < -1 && key > current->right->key) {
                        current = leftRotate(current);
                    }
                    if (balance > 1 && key > current->left->key) {
                        current->left = leftRotate(current->left);
                        current = rightRotate(current);
                    }
                    if (balance < -1 && key < current->right->key) {
                        current->right = rightRotate(current->right);
                        current = leftRotate(current);
                    }
                    current = (key < current->key) ? current->left : current->right;
                }
            }
        } else if (choice == 2) {
            printf("Enter key to delete: ");
            scanf("%d", &key);
            struct Node* current = root;
            struct Node* parent = NULL;
            while (current != NULL && current->key != key) {
                parent = current;
                if (key < current->key) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (current == NULL) {
                printf("Key not found.\n");
            } else {
                struct Node* temp;
                if (current->left == NULL || current->right == NULL) {
                    temp = current->left ? current->left : current->right;
                    if (parent == NULL) {
                        root = temp;
                    } else if (current == parent->left) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                    free(current);
                } else {
                    struct Node* successor = current->right;
                    struct Node* successorParent = current;
                    while (successor->left != NULL) {
                        successorParent = successor;
                        successor = successor->left;
                    }
                    current->key = successor->key;
                    if (successorParent->left == successor) {
                        successorParent->left = successor->right;
                    } else {
                        successorParent->right = successor->right;
                    }
                    free(successor);
                }
                current = root;
                while (current != NULL) {
                    current->height = 1 + max(height(current->left), height(current->right));
                    int balance = getBalance(current);
                    if (balance > 1 && getBalance(current->left) >= 0) {
                        current = rightRotate(current);
                    }
                    if (balance < -1 && getBalance(current->right) <= 0) {
                        current = leftRotate(current);
                    }
                    if (balance > 1 && getBalance(current->left) < 0) {
                        current->left = leftRotate(current->left);
                        current = rightRotate(current);
                    }
                    if (balance < -1 && getBalance(current->right) > 0) {
                        current->right = rightRotate(current->right);
                        current = leftRotate(current);
                    }
                    current = (key < current->key) ? current->left : current->right;
                }
            }
        } else if (choice == 3) {
            printf("Enter key to search: ");
            scanf("%d", &key);
            struct Node* current = root;
            int found = 0;
            while (current != NULL) {
                if (current->key == key) {
                    found = 1;
                    break;
                }
                current = (key < current->key) ? current->left : current->right;
            }
            if (found) {
                printf("Key %d found in the AVL tree.\n", key);
            } else {
                printf("Key %d not found in the AVL tree.\n", key);
            }
        } else if (choice == 4) {
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

