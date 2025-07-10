#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = n / 2 - 1; i >= 0; i--) {
        for (j = 2 * i + 1; j < n;) {
            if (j + 1 < n && arr[j] < arr[j + 1]) {
                j++;
            }
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        for (j = 0; j < i;) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < i && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < i && arr[right] > arr[largest]) {
                largest = right;
            }
            if (largest != j) {
                temp = arr[j];
                arr[j] = arr[largest];
                arr[largest] = temp;
                j = largest;
            } else {
                break;
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

