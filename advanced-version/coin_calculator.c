/*Student Name : Rohit Kumar Malik
	Student ID : 35363998 
	ICT 159 
	Assignment- 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "coin_calculator.h"

// Define coin denominations for different currencies
const int denominations_AU[] = {50, 20, 10, 5};
const int denominations_US[] = {50, 25, 10, 1};
const int denominations_EUR[] = {20, 10, 5, 1};
const char *currencies[] = {"AU$", "US$", "EUR"};

int read_n(FILE *file) {
    int N;
    fscanf(file, "%d", &N);
    return N;
}

void read_data(FILE *file, Record records[], int *N) {
    int count = 0;
    while (fscanf(file, "%s %d cents in %s\n", records[count].name, &records[count].cents, records[count].currency) == 3) {
        if (records[count].cents > 95 || records[count].cents < 1) {
            printf("Skipping record %d: Invalid amount %d cents\n", count + 1, records[count].cents);
        } else {
            for (int j = 0; records[count].name[j]; j++) {
                records[count].name[j] = tolower(records[count].name[j]);
            }
            count++;
        }
    }
    *N = count;
}

void display_coins(const Record records[], int N, const char *input_name) {
    int totalCoinsAU = 0, totalCoinsUS = 0, totalCoinsEUR = 0;

    calculate_total_cents(records, N, input_name, &totalCoinsAU, &totalCoinsUS, &totalCoinsEUR);

    print_customer_summary(input_name, totalCoinsAU, totalCoinsUS, totalCoinsEUR);
}

void calculate_total_cents(const Record records[], int N, const char *input_name, int *totalCoinsAU, int *totalCoinsUS, int *totalCoinsEUR) {
    char lowercase_name[MAX_NAME];
    strcpy(lowercase_name, input_name);
    for (int i = 0; lowercase_name[i]; i++) {
        lowercase_name[i] = tolower(lowercase_name[i]);
    }

    for (int i = 0; i < N; i++) {
        if (strcmp(records[i].name, lowercase_name) == 0) {
            if (strcmp(records[i].currency, "AU$") == 0) {
                *totalCoinsAU += records[i].cents;
            } else if (strcmp(records[i].currency, "US$") == 0) {
                *totalCoinsUS += records[i].cents;
            } else if (strcmp(records[i].currency, "EUR") == 0) {
                *totalCoinsEUR += records[i].cents;
            }
        }
    }
}

void print_customer_summary(const char *input_name, int totalCoinsAU, int totalCoinsUS, int totalCoinsEUR) {
    if (totalCoinsAU > 0) {
        printf("Customer:\n%s %d cents in AU$\n", input_name, totalCoinsAU);
        printf("Change:\n");
        print_change("AU$", totalCoinsAU);
    }

    if (totalCoinsUS > 0) {
        printf("\n%s %d cents in US$\n", input_name, totalCoinsUS);
        printf("Change:\n");
        print_change("US$", totalCoinsUS);
    }

    if (totalCoinsEUR > 0) {
        printf("\n%s %d cents in EUR\n", input_name, totalCoinsEUR);
        printf("Change:\n");
        print_change("EUR", totalCoinsEUR);
    }

    if (totalCoinsAU == 0 && totalCoinsUS == 0 && totalCoinsEUR == 0) {
        printf("Name: %s\nNot found\n", input_name);
    }
}

void print_change(const char *currency, int cents) {
    const int *denominations;
    int num_denominations;

    if (strcmp(currency, "AU$") == 0) {
        denominations = denominations_AU;
        num_denominations = sizeof(denominations_AU) / sizeof(denominations_AU[0]);
    } else if (strcmp(currency, "US$") == 0) {
        denominations = denominations_US;
        num_denominations = sizeof(denominations_US) / sizeof(denominations_US[0]);
    } else if (strcmp(currency, "EUR") == 0) {
        denominations = denominations_EUR;
        num_denominations = sizeof(denominations_EUR) / sizeof(denominations_EUR[0]);
    } else {
        return; // Unknown currency
    }

    for (int i = 0; i < num_denominations; i++) {
        int count = cents / denominations[i];
        cents %= denominations[i];
        if (count > 0) {
            printf("%d cents: %d\n", denominations[i], count);
        }
    }
}

void write_output(const char *output_file, const Record records[], int N) {
    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        write_record_change(file, &records[i]);
    }

    fclose(file);
}

void write_record_change(FILE *file, const Record *record) {
    int remaining = record->cents;
    const int *denominations;
    int num_denominations;

    if (strcmp(record->currency, "AU$") == 0) {
        denominations = denominations_AU;
        num_denominations = sizeof(denominations_AU) / sizeof(denominations_AU[0]);
    } else if (strcmp(record->currency, "US$") == 0) {
        denominations = denominations_US;
        num_denominations = sizeof(denominations_US) / sizeof(denominations_US[0]);
    } else if (strcmp(record->currency, "EUR") == 0) {
        denominations = denominations_EUR;
        num_denominations = sizeof(denominations_EUR) / sizeof(denominations_EUR[0]);
    } else {
        return; // Unknown currency
    }

    fprintf(file, "%s, the change for %d cents in %s is ", record->name, record->cents, record->currency);
    for (int j = 0; j < num_denominations; j++) {
        int count = remaining / denominations[j];
        remaining %= denominations[j];
        fprintf(file, "%d,", count); // Print the count of each denomination
    }
    fprintf(file, "\n");
}

void print_file_content(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void handle_input(const Record records[], int N) {
    int option;

    do {
        option = get_option();
        process_option(option, records, N);

    } while (option != 2);
}

int get_option() {
    int option;
    printf("\nChoose one option:\n");
    printf("1. Enter name\n");
    printf("2. Exit\n");

    printf("Enter option (1 or 2): ");
    scanf("%d", &option);
    getchar(); // consume newline
    return option;
}

void process_option(int option, const Record records[], int N) {
    if (option == 1) {
        char input_name[MAX_NAME];
        printf("Enter name: ");
        fgets(input_name, MAX_NAME, stdin);
        input_name[strcspn(input_name, "\n")] = '\0'; // Remove newline character

        display_coins(records, N, input_name);
        
    } else if (option == 2) {
        write_output("change.csv", records, N);
        printf("Change has been written to change.csv\n");
    } else {
        printf("Invalid option. Please try again.\n");
    }
}
