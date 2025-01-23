#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct Book {
    int id;
    char title[100];
    char author[100];
    int available;
};

struct Patron {
    int id;
    char name[100];
};

struct Transaction {
    int bookId;
    int patronId;
    char type[10]; // "borrow" or "return"
};

// Function prototypes
void addBook();
void removeBook();
void updateBook();
void viewBooks();
void addPatron();
void removePatron();
void viewPatrons();
void borrowBook();
void returnBook();
void viewTransactions();

// Global variables
struct Book books[100];
struct Patron patrons[100];
struct Transaction transactions[100];
int bookCount = 0;
int patronCount = 0;
int transactionCount = 0;

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Update Book\n");
        printf("4. View Books\n");
        printf("5. Add Patron\n");
        printf("6. Remove Patron\n");
        printf("7. View Patrons\n");
        printf("8. Borrow Book\n");
        printf("9. Return Book\n");
        printf("10. View Transactions\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                viewBooks();
                break;
            case 5:
                addPatron();
                break;
            case 6:
                removePatron();
                break;
            case 7:
                viewPatrons();
                break;
            case 8:
                borrowBook();
                break;
            case 9:
                returnBook();
                break;
            case 10:
                viewTransactions();
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a book to the library
void addBook() {
    struct Book newBook;
    newBook.id = bookCount + 1;
    printf("Enter book title: ");
    scanf("%s", newBook.title);
    printf("Enter book author: ");
    scanf("%s", newBook.author);
    newBook.available = 1;
    books[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully!\n");
}

// Function to remove a book from the library
void removeBook() {
    int id;
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to update a book in the library
void updateBook() {
    int id;
    printf("Enter book ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("Enter new title: ");
            scanf("%s", books[i].title);
            printf("Enter new author: ");
            scanf("%s", books[i].author);
            printf("Book updated successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to view all books in the library
void viewBooks() {
    printf("\nList of Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s, Available: %d\n", books[i].id, books[i].title, books[i].author, books[i].available);
    }
}

// Function to add a patron to the library
void addPatron() {
    struct Patron newPatron;
    newPatron.id = patronCount + 1;
    printf("Enter patron name: ");
    scanf("%s", newPatron.name);
    patrons[patronCount] = newPatron;
    patronCount++;
    printf("Patron added successfully!\n");
}

// Function to remove a patron from the library
void removePatron() {
    int id;
    printf("Enter patron ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < patronCount; i++) {
        if (patrons[i].id == id) {
            for (int j = i; j < patronCount - 1; j++) {
                patrons[j] = patrons[j + 1];
            }
            patronCount--;
            printf("Patron removed successfully!\n");
            return;
        }
    }
    printf("Patron not found.\n");
}

// Function to view all patrons in the library
void viewPatrons() {
    printf("\nList of Patrons:\n");
    for (int i = 0; i < patronCount; i++) {
        printf("ID: %d, Name: %s\n", patrons[i].id, patrons[i].name);
    }
}

// Function to borrow a book from the library
void borrowBook() {
    int bookId, patronId;
    printf("Enter book ID to borrow: ");
    scanf("%d", &bookId);
    printf("Enter patron ID: ");
    scanf("%d", &patronId);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && books[i].available) {
            books[i].available = 0;
            struct Transaction newTransaction = {bookId, patronId, "borrow"};
            transactions[transactionCount] = newTransaction;
            transactionCount++;
            printf("Book borrowed successfully!\n");
            return;
        }
    }
    printf("Book not available or not found.\n");
}

// Function to return a book to the library
void returnBook() {
    int bookId, patronId;
    printf("Enter book ID to return: ");
    scanf("%d", &bookId);
    printf("Enter patron ID: ");
    scanf("%d", &patronId);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && !books[i].available) {
            books[i].available = 1;
            struct Transaction newTransaction = {bookId, patronId, "return"};
            transactions[transactionCount] = newTransaction;
            transactionCount++;
            printf("Book returned successfully!\n");
            return;
        }
    }
    printf("Book not borrowed or not found.\n");
}

// Function to view all transactions in the library
void viewTransactions() {
    printf("\nList of Transactions:\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("Book ID: %d, Patron ID: %d, Type: %s\n", transactions[i].bookId, transactions[i].patronId, transactions[i].type);
    }
}
