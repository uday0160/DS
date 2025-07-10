#include <stdio.h>

int main() {
    int arr[100], size, element, left, right, mid;

    printf("Enter array size (must be sorted): ");
    scanf("%d", &size);

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &element);

    left = 0;
    right = size - 1;
    int found = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == element) {
            printf("Element %d found at index %d\n", element, mid);
            found = 1;
            break;
        } else if (arr[mid] < element) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found\n", element);
    }

    return 0;
}

