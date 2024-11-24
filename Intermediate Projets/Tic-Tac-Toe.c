#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '1' + (i * SIZE + j);
        }
    }
}

void displayBoard()
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
        {
            for (int k = 0; k < SIZE; k++)
                printf("--- ");
            printf("\n");
        }
    }
    printf("\n");
}

bool isValidMove(int move)
{
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    return (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int move)
{
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    board[row][col] = currentPlayer;
}

bool checkWin()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

bool checkDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main()
{
    int move;
    initializeBoard();
    printf("=========================\n");
    printf("   Created By @Dypixx\n");
    printf("=========================\n");
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n");

    while (true)
    {
        displayBoard();
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &move);

        if (!isValidMove(move))
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        makeMove(move);

        if (checkWin())
        {
            displayBoard();
            printf("Player %c wins! Congratulations!\n", currentPlayer);
            break;
        }

        if (checkDraw())
        {
            displayBoard();
            printf("It's a draw! Well played.\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
