//Elizabeth Channel//
//Lab 5 - Part one//
//Sales Report//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define variable for number of months
#define MONTHS 12

//list of months
char *months[] = {"January", "February", "March", "April", "May", "June",
                  "July", "August", "September", "October", "November", "December"};

//open and read sales files
void read_file(float sales[]) { //read each line as float
  char buffer[100]; //buffer of 100 entries
  FILE *file = fopen("sales.txt", "r"); //FILE is opened sales file

  //if file is null print error message
  if (file == NULL) {
    perror("Error opening sales.txt"); //error message
    exit(EXIT_FAILURE); //exit
  }

  //loop for reading each line
  for (int i = 0; i < MONTHS; i++) { //for line in file less than number of months
    if (fgets(buffer, sizeof(buffer), file) != NULL) { //if file is not null
      sales[i] = strtof(buffer, NULL); //index is line in file
    } else { //otherwise there is an error
        fprintf(stderr, "Error reading sales data for month %s\n", months[i]);
        sales[i] = 0.0;  //default to 0.0 in case of error
    }
  }
  //close file
  fclose(file);
}

//sales report function
void sales_report(float sales[]) {
    //section title print
    printf("Monthly sales report for 2022:\n");
    //subtitles
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) { //for line in file
        printf("%s\t$%.2f\n", months[i], sales[i]); //print month name and sales number
    }
}

//sales summary function
void sales_summary(float sales[]) {
    //setting min and max index and setting minimum to zero
    float min_sale = sales[0], max_sale = sales[0], total_sales = 0;

    //for line in sales
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] < min_sale) //if number is less than the one before
            min_sale = sales[i]; //set number as minmum
        if (sales[i] > max_sale) //if number is greater than the one before
            max_sale = sales[i]; //set number to max
        total_sales += sales[i]; //add all numbers
    }

    //average is total sales divided by number of months
    float avg_sale = total_sales / MONTHS;

    //print section title
    printf("\nSales summary:\n");
    //minimum subtitle as well as value
    printf("Minimum sales: $%.2f (%s)\n", min_sale, months[0]);
    //maximum subtitle as well as value
    printf("Maximum sales: $%.2f (%s)\n", max_sale, months[MONTHS - 1]);
    //average subtitle as well as value
    printf("Average sales: $%.2f\n", avg_sale);
}

//6 month average function
void six_month_avg(float sales[], float moving_averages[]) {
    for (int i = 0; i < MONTHS - 5; i++) { //for line in file less than number of months minus 5
        float sum = 0; //sum is set to zero as float
        for (int j = i; j < i + 6; j++) { //for line in file less than index plus 6
            sum += sales[j]; //add to sum
        }
        moving_averages[i] = sum / 6; //average is the above sum divided by 6
    }
}

//six month report function
void six_month_report(float moving_averages[]) {
    //section title
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++) { //for line in file minus 5
      //print start month and end month and the average
        printf("%s - %s\t$%.2f\n", months[i], months[i + 5], moving_averages[i]);
    }
}

//high to low function
void sales_report_highest_to_lowest(float sales[]) {
    //month as indices
    int indices[MONTHS];
    for (int i = 0; i < MONTHS; i++) //for line in file
        indices[i] = i; //index is i

    //sort sales and indices in descending order
    for (int i = 0; i < MONTHS - 1; i++) { //for line minus one
        for (int j = i + 1; j < MONTHS; j++) { //for next line in sales
            if (sales[i] < sales[j]) { //compare the lines, if line one less than line two
                float temp = sales[i]; //set tempt to line one
                sales[i] = sales[j]; //line one becomes line 2
                sales[j] = temp; //line two becomes temp

                //temp index becomes line one
                int temp_index = indices[i];
                indices[i] = indices[j]; //line one index becomes line two index
                indices[j] = temp_index; //line two index becomes temp index
            }
        }
    }

    //print section title
    printf("\nSales Report (Highest to Lowest):\n");
    //subtitle
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) { //for line in sales
        printf("%s\t$%.2f\n", months[indices[i]], sales[i]); //print in order
    }
}

//main function
int main() {
    //float sales for number of months
    float sales[MONTHS];
    read_file(sales); //read sales file

    sales_report(sales); //sales report for sales file
    sales_summary(sales); //sales summary for sales file

    float moving_averages[MONTHS - 5]; //6 months
    six_month_avg(sales, moving_averages); //6 month average for sales file
    six_month_report(moving_averages); //6 month report for sales file

    sales_report_highest_to_lowest(sales); //high to low for sales file

    return 0;
}
