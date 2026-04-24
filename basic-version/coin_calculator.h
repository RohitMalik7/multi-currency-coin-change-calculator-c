// Author: Rohit Malik
// Project: Multi-Currency Coin Change Calculator

// Function prototypes
void display_Menu();
int select_Currency();
int get_Amount();
int validate_Amount(int amount, int currency);
void calculate_Coins(int amount, int currency, int coins[]);
void display_Result(int coins[], int currency);
int ask_To_Continue();
