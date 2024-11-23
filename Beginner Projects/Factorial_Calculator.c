// Created By @Dypixx

#include <stdio.h>
long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorialRecursive(n - 1);
}
long long factorialIterative(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int number, method;
    long long result;

    printf("=========================================\n");
    printf("          Factorial Calculator\n");
    printf("          Created by @Dypixx\n");
    printf("=========================================\n\n");

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Error: Factorial of a negative number is not defined.\n");
        return 1;
    }

    printf("\nChoose a method:\n");
    printf("1. Recursion\n");
    printf("2. Iteration\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &method);

    printf("\n=========================================\n");

    if (method == 1)
    {
        result = factorialRecursive(number);
        printf("Factorial of %d using recursion is: %lld\n", number, result);
    }
    else if (method == 2)
    {
        result = factorialIterative(number);
        printf("Factorial of %d using iteration is: %lld\n", number, result);
    }
    else
    {
        printf("Error: Invalid choice.\n");
    }

    printf("=========================================\n");
    printf("Thank you for using the Factorial Calculator!\n");
    printf("Created by @Dypixx\n");
    return 0;
}
