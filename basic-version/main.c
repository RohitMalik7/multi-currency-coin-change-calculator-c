/*Student Name : Rohit Kumar Malik
	Student ID : 35363998 
	ICT 159 
	 Assignment 1
*/

#include <stdio.h>
#include "coin_calculator.h"

int main() {
    int currency_Choice, amount, coins[4];
    int continue_Flag = 1;

    while (continue_Flag) {
        display_Menu();
        currency_Choice = select_Currency();
        amount = get_Amount();

        if (validate_Amount(amount, currency_Choice)) {
            calculate_Coins(amount, currency_Choice, coins);
            display_Result(coins, currency_Choice);
        }

        continue_Flag = ask_To_Continue();
    }

    printf("Thank you!\n");
    return 0;
}