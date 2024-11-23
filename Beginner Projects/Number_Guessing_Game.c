// Created By @Dypixx

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int randomNumber, guess, attempts = 0;
    char playAgain;
    srand(time(0));

    printf("=====================================\n");
    printf("         Number Guessing Game\n");
    printf("         Created by @Dypixx\n");
    printf("=====================================\n\n");

    do
    {
        randomNumber = rand() % 100 + 1;
        attempts = 0;

        printf("I have generated a random number between 1 and 100.\n");
        printf("Can you guess it?\n\n");

        do
        {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess > randomNumber)
            {
                printf("Too high! Try again.\n");
            }
            else if (guess < randomNumber)
            {
                printf("Too low! Try again.\n");
            }
            else
            {
                printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            }
        } while (guess != randomNumber);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        printf("\n=====================================\n");

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing the Number Guessing Game!\n");
    printf("Created by @Dypixx\n");
    return 0;
}
