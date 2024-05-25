#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Expense {
    char date[20];
    float amount;
    char category[50];
};
void addExpense(struct Expense *expenses, int *count) {
    printf("\nEnter the date (YYYY-MM-DD):");
    scanf("%s", expenses[*count].date);
    printf("\nEnter the amount:");
    scanf("%f", &expenses[*count].amount);
    printf("\nEnter the category:");
    scanf("%s", expenses[*count].category);
    (*count)++;
}
void displayExpenses(const struct Expense *expenses, int count) {
    printf("\nExpense List:\n");
    for (int i = 0; i < count; i++) 
    {
        printf("\nDate: %s \nAmount: $%.2f \nCategory: %s",expenses[i].date, expenses[i].amount, expenses[i].category);
    }
}
int main() {
    struct Expense expenses[100]; 
    int count = 0; 
    int choice;
    do {
        printf("\nExpense Tracker Menu:");
        printf("\n1. Add Expense");
        printf("\n2. Display Expenses");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                printf("\nThanks for using this expense tracker!");
                break;
            default:
                printf("\nInvalid choice.Please try again.");
        }
    } while (choice != 3);
     return 0;
}