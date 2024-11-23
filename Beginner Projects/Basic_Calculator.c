// Created by @Dypixx

#include <stdio.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("=================================\n");
    printf("      Basic Calculator\n");
    printf("     Created by @Dypixx\n");
    printf("=================================\n\n");

    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("\nEnter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("\n=================================\n");

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
            printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
        }
        else
        {
            printf("Error: Division by zero is not allowed.\n");
        }
        break;
    default:
        printf("Error: Invalid operator.\n");
        break;
    }

    printf("=================================\n");
    printf("\nThank you for using the calculator!\n");
    printf("Created by @Dypixx\n");

    return 0;
}
