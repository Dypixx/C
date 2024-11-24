#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct
{
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount()
{
    if (accountCount >= MAX_ACCOUNTS)
    {
        printf("Maximum account limit reached.\n");
        return;
    }
    Account acc;
    printf("=========================\n");
    printf("   Created By @Dypixx\n");
    printf("=========================\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter Account Holder Name: ");
    getchar(); // Clear newline character
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    accounts[accountCount++] = acc;
    printf("Account added successfully!\n");
}

void displayAccounts()
{
    if (accountCount == 0)
    {
        printf("No accounts found.\n");
        return;
    }
    printf("\nAccount Details:\n");
    for (int i = 0; i < accountCount; i++)
    {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("-----------------------------\n");
    }
}

void balanceInquiry()
{
    int accountNumber;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void depositMoney()
{
    int accountNumber;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount deposited successfully!\nCurrent Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawMoney()
{
    int accountNumber;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount)
            {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully!\nCurrent Balance: %.2f\n", accounts[i].balance);
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

int main()
{
    int choice;
    printf("Created By @Dypixx\n");
    while (1)
    {
        printf("\nBanking System Menu:\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Balance Inquiry\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAccount();
            break;
        case 2:
            displayAccounts();
            break;
        case 3:
            balanceInquiry();
            break;
        case 4:
            depositMoney();
            break;
        case 5:
            withdrawMoney();
            break;
        case 6:
            printf("Thank you for using the Banking System. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
