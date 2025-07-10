#include <stdio.h>

int main() {
    int n, i, j, mid, left, right, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (left = 1; left < n; left *= 2) {
        for (i = 0; i < n; i += 2 * left) {
            mid = i + left - 1;
            right = i + 2 * left - 1;

            if (right >= n) {
                right = n - 1;
            }

            int l = i, r = mid + 1, t = i;

            while (l <= mid && r <= right) {
                if (arr[l] <= arr[r]) {
                    temp[t++] = arr[l++];
                } else {
                    temp[t++] = arr[r++];
                }
            }

            while (l <= mid) {
                temp[t++] = arr[l++];
            }

            while (r <= right) {
                temp[t++] = arr[r++];
            }

            for (j = i; j <= right; j++) {
                arr[j] = temp[j];
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

