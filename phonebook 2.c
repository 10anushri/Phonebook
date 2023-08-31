#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a contact
struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
};

// Function to add a contact to the phonebook
void addContact(struct Contact** head, const char* name, const char* phone) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = *head;
    *head = newContact;
    printf("Contact added successfully.\n");
}

// Function to search for a contact by name
void searchContact(struct Contact* head, const char* name) {
    struct Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Contact found: %s, %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

// Function to display all contacts in the phonebook
void displayContacts(struct Contact* head) {
    struct Contact* current = head;
    printf("Phonebook:\n");
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

int main() {
    struct Contact* phonebook = NULL;
    int choice;
    
    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                {
                    char name[50], phone[15];
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter phone: ");
                    scanf("%s", phone);
                    addContact(&phonebook, name, phone);
                }
                break;
            case 2:
                {
                    char name[50];
                    printf("Enter name to search: ");
                    scanf("%s", name);
                    searchContact(phonebook, name);
                }
                break;
            case 3:
                displayContacts(phonebook);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    
    // Free allocated memory for contacts before exiting
    while (phonebook != NULL) {
        struct Contact* temp = phonebook;
        phonebook = phonebook->next;
        free(temp);
    }

    return 0;
}
