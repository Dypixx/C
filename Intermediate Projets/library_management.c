#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 1000

typedef struct
{
    int id;
    char title[100];
    char author[100];
} Book;

Book library[MAX_BOOKS];
int totalBooks = 0;

void addBook()
{
    if (totalBooks >= MAX_BOOKS)
    {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    getchar();
    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    library[totalBooks++] = newBook;
    printf("Book added successfully!\n");
}

void deleteBook()
{
    int id, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].id == id)
        {
            found = 1;
            for (int j = i; j < totalBooks - 1; j++)
            {
                library[j] = library[j + 1];
            }
            totalBooks--;
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found)
    {
        printf("Book with ID %d not found.\n", id);
    }
}

void searchBook()
{
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < totalBooks; i++)
    {
        if (library[i].id == id)
        {
            printf("Book Found:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Book with ID %d not found.\n", id);
    }
}

void displayBooks()
{
    if (totalBooks == 0)
    {
        printf("No books in the library.\n");
        return;
    }
    printf("\nBooks in Library:\n");
    for (int i = 0; i < totalBooks; i++)
    {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

int main()
{
    int choice;

    do
    {
        printf("=========================\n");
        printf("   Created By @Dypixx\n");
        printf("=========================\n\n");
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            displayBooks();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
