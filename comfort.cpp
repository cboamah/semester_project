#include <stdio.h>
#include <string.h>

// Structure to store user information
struct User {
    char username[50];
    char password[50];
};

// Function to register a new user
void registerUser(struct User users[], int *userCount) {
    if (*userCount < 10) {
        printf("Enter username: ");
        scanf("%s", users[*userCount].username);
        printf("Enter password: ");
        scanf("%s", users[*userCount].password);
        (*userCount)++;
        printf("Registration successful!\n");
    } else {
        printf("Maximum number of users reached.\n");
    }
}

// Function to perform login
void loginUser(struct User users[], int userCount) {
    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password.\n");
    }
}

int main() {
    struct User users[10];  // Array to store user information
    int userCount = 0;      // Current number of registered users
    int choice;

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser(users, &userCount);
        } else if (choice == 2) {
            loginUser(users, userCount);
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

