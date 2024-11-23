#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1) 
        return 0;
    if (n <= 3) 
        return 1;
    if (n % 2 == 0 || n % 3 == 0) 
        return 0;
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) 
            return 0;
    }
    return 1;
}

int main() {
    int number;

    printf("=========================================\n");
    printf("           Prime Number Checker\n");
    printf("           Created by @Dypixx\n");
    printf("=========================================\n\n");

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &number);

    printf("\n=========================================\n");

    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    printf("=========================================\n");
    printf("Thank you for using the Prime Number Checker!\n");
    printf("Created by @Dypixx\n");
    return 0;
}
