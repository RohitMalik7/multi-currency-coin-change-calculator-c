// Author: Rohit Malik
// Project: Multi-Currency Coin Change Calculator

#include <stdio.h>
#include <stdlib.h>
#include "coin_calculator.h"

int main() {
    const char *filename = "coins.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the number of records
    int N = read_n(file);

    // Allocate array for records and read data
    Record records[MAX_RECORDS];
    read_data(file, records, &N);
    fclose(file);

    // Print the file content
    printf("File content:\n");
    print_file_content(filename);

    // Handle user input and options
    handle_input(records, N);

    return 0;
}
