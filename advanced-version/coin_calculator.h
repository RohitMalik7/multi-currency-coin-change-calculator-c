/*Student Name : Rohit Kumar Malik
	Student ID : 35363998 
	ICT 159 
	Assignment- 2
*/
#ifndef COIN_CALCULATOR_H
#define COIN_CALCULATOR_H

#define MAX_NAME 50
#define MAX_CURRENCY 5
#define MAX_RECORDS 100

#define NUM_DENOMINATIONS 4

typedef struct {
    char name[MAX_NAME];
    int cents;
    char currency[MAX_CURRENCY];
} Record;

// Function prototypes
int read_n(FILE *file);
void read_data(FILE *file, Record records[], int *N);
void display_coins(const Record records[], int N, const char *input_name);
void calculate_total_cents(const Record records[], int N, const char *input_name, int *totalCoinsAU, int *totalCoinsUS, int *totalCoinsEUR);
void print_customer_summary(const char *input_name, int totalCoinsAU, int totalCoinsUS, int totalCoinsEUR);
void print_change(const char *currency, int cents);
void write_output(const char *output_file, const Record records[], int N);
void write_record_change(FILE *file, const Record *record);
void print_file_content(const char *filename);
void handle_input(const Record records[], int N);
int get_option();
void process_option(int option, const Record records[], int N);

#endif // COIN_CALCULATOR_H
