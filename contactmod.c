#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Contact book is full. Cannot add more contacts.\n");
        printf("--------------------\n");
        return;
    }

    struct Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter email: ");
    scanf("%s", newContact.email);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
    printf("--------------------\n");
}

void displayContacts(struct Contact contacts[], int numContacts) {
    printf("Contacts:\n");
    if (numContacts == 0) {
        printf("No contacts found.\n");
        printf("--------------------\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("--------------------\n");
    }
}

void searchContact(struct Contact contacts[], int numContacts) {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s",&searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("--------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
        printf("--------------------\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    do {
        printf("Contact Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                printf("Exiting program.\n");
                printf("--------------------\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                printf("--------------------\n");
        }
    } while (choice != 4);
         
    return 0;
}
