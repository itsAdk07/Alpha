#include <stdio.h>
#include <stdlib.h>

int* mixedCongruential(int n) {
    int x0, a, c, m;
    printf("Enter Seed Multiplier x0: ");
    scanf("%d", &x0);
    printf("Enter Constant Multiplier a: ");
    scanf("%d", &a);
    printf("Enter increment c: ");
    scanf("%d", &c);
    printf("Enter modulus m: ");
    scanf("%d", &m);

    int* Arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        x0 = (a * x0 + c) % m;
        Arr[i] = x0;
    }
    return Arr;
}

int main() {
    int n;
    printf("How many random numbers do you need? ");
    scanf("%d", &n);
    int* randomNumbers = mixedCongruential(n);
    printf("The random numbers are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", randomNumbers[i]);
    }
    free(randomNumbers);
    return 0;
}


