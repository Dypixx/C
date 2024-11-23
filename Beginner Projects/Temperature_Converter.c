// Created By @Dypixx

#include <stdio.h>
int main()
{
    int choice;
    double temp, convertedTemp;

    printf("=========================================\n");
    printf("         Temperature Converter\n");
    printf("         Created by @Dypixx\n");
    printf("=========================================\n\n");

    printf("Choose the conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    printf("\nEnter the temperature 2 convert: ");
    scanf("%lf", &temp);

    printf("\n=========================================\n");

    switch (choice)
    {
    case 1:
        convertedTemp = (temp * 9 / 5) + 32;
        printf("%.2lf Celsius = %.2lf Fahrenheit\n", temp, convertedTemp);
        break;
    case 2:
        convertedTemp = temp + 273.15;
        printf("%.2lf Celsius = %.2lf Kelvin\n", temp, convertedTemp);
        break;
    case 3:
        convertedTemp = (temp - 32) * 5 / 9;
        printf("%.2lf Fahrenheit = %.2lf Celsius\n", temp, convertedTemp);
        break;
    case 4:
        convertedTemp = (temp - 32) * 5 / 9 + 273.15;
        printf("%.2lf Fahrenheit = %.2lf Kelvin\n", temp, convertedTemp);
        break;
    case 5:
        convertedTemp = temp - 273.15;
        printf("%.2lf Kelvin = %.2lf Celsius\n", temp, convertedTemp);
        break;
    case 6:
        convertedTemp = (temp - 273.15) * 9 / 5 + 32;
        printf("%.2lf Kelvin = %.2lf Fahrenheit\n", temp, convertedTemp);
        break;
    default:
        printf("Error: Invalid choice. Please select a valid option.\n");
        break;
    }

    printf("=========================================\n");
    printf("\nThank you for using the Temperature Converter!\n");
    printf("Created by @Dypixx\n");

    return 0;
}
