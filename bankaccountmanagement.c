#include <stdio.h>
#include <stdlib.h>
struct BankAccount {
    char name[100];
    char address[200];
    char acc_type; 
    float balance;
};
void open_account(struct BankAccount *account) {
    printf("\nEnter your full name:");
    scanf("%s", &account->name);
    printf("\nEnter your address:");
    scanf("%s", &account->address);
    printf("\nwhich type of account you want to open (S for Savings, C for Current):");
    scanf(" %c", &account->acc_type);
    printf("\nEnter the initial deposit amount:");
    scanf("%f", &account->balance);
    printf("\nAccount created successfully!:)");
}
void deposit_money(struct BankAccount *account) {
    float amount;
    printf("\nEnter the amount to deposit:");
    scanf("%f", &amount);
    account->balance += amount;
    printf("\nAvailable balance: $%.2f", account->balance);
}
void withdraw_money(struct BankAccount *account) {
    float amount;
    printf("\nEnter the amount to withdraw:$");
    scanf("%f", &amount);
    if (amount > account->balance)  {
        printf("\nInsufficient balance!");
    } else {
        account->balance -= amount;
        printf("\nAvailable balance: $%.2f", account->balance);
    }
}
void display_account(struct BankAccount *account) {
    printf("\nName: %s", account->name);
    printf("\nAddress: %s", account->address);
    if(account->acc_type == 'C')
    {
        printf("\nAccount Type:Current");
    }
    else{
        printf("\nAccount Type:Savings");
    }
    printf("\nAvailable balance: $%.2f", account->balance);
}
int main() {
    struct BankAccount account;
    int choice;
    do {
        printf("\nMenu: \n1.Open Account \n2.Deposit Money \n3.Withdraw Money \n4.Display Account \n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                open_account(&account);
                break;
            case 2:
                deposit_money(&account);
                break;
            case 3:
                withdraw_money(&account);
                break;
            case 4:
                display_account(&account);
                break;
            case 5:
                printf("Thank you for using our bank management system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}