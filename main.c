#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
    char name[50];
    int accountNumber;
    char password[20];
    float balance;
};


struct Account accounts[MAX];
int count = 0;


void createAccount();
int login();
void depositMoney(int index);
void checkBalance(int index);
void showMenu();

int main() {
    int choice;
    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create a new account\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            createAccount();
        } else if (choice == 2) {
            int index = login();
            if (index != -1) {
                int option;
                do {
                    printf("\n Hello %s!\n", accounts[index].name);
                    printf("1. Deposit money\n");
                    printf("2. View balance\n");
                    printf("3. Sign out\n");
                    printf("Choose: ");
                    scanf("%d", &option);

                    if (option == 1) {
                        depositMoney(index);
                    } else if (option == 2) {
                        checkBalance(index);
                    }

                } while (option != 3);
            }
        } else if (choice == 3) {
            printf("Thank you for using the system.!\n");
            break;
        } else {
            printf("Incorrect choice, try again..\n");
        }
    }

    return 0;
}

void createAccount() {
    if (count >= MAX) {
        printf("No more accounts can be created..\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", accounts[count].name);

    printf("Enter account number: ");
    scanf("%d", &accounts[count].accountNumber);

    printf("Enter your password: ");
    scanf("%s", accounts[count].password);

    accounts[count].balance = 0.0;
    count++;

    printf("Account created successfully!\n");
}

int login() {
    int accNum;
    char pass[20];
    printf("Enter account number: ");
    scanf("%d", &accNum);

    printf("Enter your password: ");
    scanf("%s", pass);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accNum && strcmp(accounts[i].password, pass) == 0) {
            return i;
        }
    }

    printf("Invalid login data.\n");
    return -1;
}

void depositMoney(int index) {
    float amount;
    printf("Enter the amount you want to deposit:\n");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("the amount is no valid (you are poor).\n");
        return;
    }

    accounts[index].balance += amount;
    printf("the deposit was successful!\n");
}

void checkBalance(int index) {
    printf("you are poor hhhh \n", accounts[index].balance);
}
