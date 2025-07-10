#include <stdio.h>

int factorial(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n, result;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 0)
        printf("Factorial is not defined for negative numbers.");
    else {
        result = factorial(n);
        printf("Factorial of %d is %d", n, result);
    }

    return 0;
}

