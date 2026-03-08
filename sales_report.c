#include <stdio.h>
#define MONTHS 12

/*
  Function sortSales:
    This function sorts the given sales from highest to lowest.
*/
void sortSales(float sales[], char *months[]){
    float sale;
    char *month;
    int j;
    for (int i = 1; i < MONTHS; i++) {
        sale = sales[i];
        month = months[i];
        j = i - 1;

        while(j >= 0 && sales[j] < sale) {
            sales[j + 1] = sales[j];
            months[j + 1] = months[j];
            j--;
        }
        sales[j + 1] = sale;
        months[j + 1] = month;
    }
}

int main() {
    float sales[MONTHS] = {
    23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
    72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22
    };
    char *months[MONTHS] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    float salesCopy[12];
    char *monthsCopy[12];

    // =====================
    // Monthy Sales Report
    // =====================

    // Output the formatted monthly sales report with a column for 'Month' and 'Sales'
    printf("\nMonthly Sales Report for 2024\n\n");
    printf("%-10s Sales\n", "Month");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s %.2f\n", months[i], sales[i]);
    }

    // =======================
    // Sales Summary Report
    // =======================
    printf("\nSales Summary Report:\n\n");
    float minSale = sales[0], maxSale = sales[0];
    int minIndex = 0, maxIndex = 0;
    float totalSales = sales[0];

    // Find the min, max, and total sales
    for (int i = 1; i < MONTHS; i++) {
        totalSales += sales[i];

        if (sales[i] < minSale) {
            minSale = sales[i];
            minIndex = i;
        } 

        if (sales[i] > maxSale) {
            maxSale = sales[i];
            maxIndex = i;
        }
    }

    // Output the results for min, max, and average sales
    printf("Minimum sales: %10.2f (%s)\n", minSale, months[minIndex]);
    printf("Maximum sales: %10.2f (%s)\n", maxSale, months[maxIndex]);
    printf("Average sales: %10.2f\n", totalSales / MONTHS);

    // ================================
    // Six-Month Moving Average Report
    // ================================
    printf("\nSix-Month moving average report:\n\n");

    // Iterate through 6-month window starts
    for (int i = 0; i <= MONTHS - 6; i++){
        float sumSales = 0;

        // Sum the sales for the 6-month window
        for (int j = i; j < i + 6; j++){
            sumSales += sales[j];
        }

        // Build the string "Start Month-End Month" and use sprintf to write the output into an array
        char monthRange[25];
        sprintf(monthRange, "%s-%s", months[i], months[i + 5]);
        printf("%-18s %.2f\n", monthRange, sumSales / 6);
    }

    // ==================================
    // Sales Report (Highest to Lowest)
    // ==================================

    // Make a copy of each array
    for (int i = 0; i < MONTHS; i++) {
        salesCopy[i] = sales[i];
        monthsCopy[i] = months[i];
    }

    // Sort the copied arrays
    sortSales(salesCopy, monthsCopy);

    printf("\nSales report (highest to lowest)\n\n");
    printf("%-12s Sales\n", "Month");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s $%.2f\n", monthsCopy[i], salesCopy[i]);
    }

    return 0;
}