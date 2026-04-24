// Author: Rohit Malik
// Project: Multi-Currency Coin Change Calculator

#include <stdio.h>
#include "coin_calculator.h"

// Display menu function
void display_Menu() {
    printf("Please select a currency:\n");
    printf("1. US Dollar\n");
    printf("2. Australian Dollar\n");
    printf("3. Euro\n");
}

// Select currency function
int select_Currency() {
    int choice;
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 3) {
        printf("Invalid choice. Please enter a number between 1 and 3: ");
        scanf("%d", &choice);
    }

    return choice;
}

// Get amount function
int get_Amount() {
    int amount;
    printf("Enter the amount (1-95): ");
    scanf("%d", &amount);
    return amount;
}

// Validate amount function
int validate_Amount(int amount, int currency) {
    if (currency == 2 && amount % 5 != 0) {
        printf("For Australian Dollar, amount must be a multiple of 5.\n");
        return 0;
    }
    if (amount < 1 || amount > 95) {
        printf("Invalid amount. Please enter an amount between 1 and 95.\n");
        return 0;
    }
    return 1;
}

// Calculate coins function
void calculate_Coins(int amount, int currency, int coins[]) {
    // Coin values for different currencies
    int us_Values[4] = {50, 25, 10, 1};
    int au_Values[4] = {50, 20, 10, 5};
    int euro_Values[4] = {20, 10, 5, 1};

    // Initialize coins array to zero
    for (int i = 0; i < 4; i++) {
        coins[i] = 0;
    }

    // Calculate coins based on currency choice
    if (currency == 1) {
        for (int i = 0; i < 4; i++) {
            coins[i] = amount / us_Values[i];
            amount %= us_Values[i];
        }
    } else if (currency == 2) {
        for (int i = 0; i < 4; i++) {
            coins[i] = amount / au_Values[i];
            amount %= au_Values[i];
        }
    } else if (currency == 3) {
        for (int i = 0; i < 4; i++) {
            coins[i] = amount / euro_Values[i];
            amount %= euro_Values[i];
        }
    }
}

// Display result function
void display_Result(int coins[], int currency) {
    const char *coin_Names[4];

    // Set coin names based on currency choice
    if (currency == 1) {
        coin_Names[0] = "50 cents";
        coin_Names[1] = "25 cents";
        coin_Names[2] = "10 cents";
        coin_Names[3] = "1 cent";
        printf("Optimal distribution of coins for US Dollar:\n");
    } else if (currency == 2) {
        coin_Names[0] = "50 cents";
        coin_Names[1] = "20 cents";
        coin_Names[2] = "10 cents";
        coin_Names[3] = "5 cents";
        printf("Optimal distribution of coins for Australian Dollar:\n");
    } else if (currency == 3) {
        coin_Names[0] = "20 cents";
        coin_Names[1] = "10 cents";
        coin_Names[2] = "5 cents";
        coin_Names[3] = "1 cent";
        printf("Optimal distribution of coins for Euro:\n");
    }

    // Display the result
    for (int i = 0; i < 4; i++) {
        printf("%s: %d\n", coin_Names[i], coins[i]);
    }
}

// Ask to continue function
int ask_To_Continue() {
    char response;
    printf("Do you want to calculate again? (Y/N): ");
    scanf(" %c", &response);
    return (response == 'Y' || response == 'y');
}
