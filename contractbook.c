#include <stdio.h>
#include <string.h>


// Structure definition
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    char address[50];
};

// Global array and count
struct Contact contacts[100];
int count = 0;

// Function declarations
void addContact();
void viewContacts();
void searchContact();
void deleteContact();

int main() {
    int choice;
    while (1) {
        printf("\n--- Contact Book ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to add a contact
void addContact() {
    if (count >= 100) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[count].name, 50, stdin);
    contacts[count].name[strcspn(contacts[count].name, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(contacts[count].phone, 20, stdin);
    contacts[count].phone[strcspn(contacts[count].phone, "\n")] = '\0';

    printf("Enter email: ");
    fgets(contacts[count].email, 50, stdin);
    contacts[count].email[strcspn(contacts[count].email, "\n")] = '\0';
    
    printf("Enter address: ");
    fgets(contacts[count].address, 50, stdin);
    contacts[count].address[strcspn(contacts[count].address, "\n")] = '\0';

    count++;
    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts() {
    if (count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s - %s - %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email,contacts[i].address);
    }
}

// Function to search contact by name
void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s - %s - %s\n", contacts[i].name, contacts[i].phone, contacts[i].email,contacts[i].address);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Function to delete a contact
void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Shift remaining contacts up
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}
