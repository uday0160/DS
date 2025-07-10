#include <stdio.h>

int main() {
    int arr[100], size, element, index;

    printf("Enter array size: ");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &element);
    index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    printf("Enter element to delete: ");
    scanf("%d", &element);
    index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; i++) arr[i] = arr[i + 1];
        size--;
        printf("Element deleted successfully\n");
    } else {
        printf("Element not found\n");
    }

    printf("Updated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

