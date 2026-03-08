#include <stdio.h>
#define SIZE 5

// ======================
// Function Prototypes
// ======================

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int m[SIZE][SIZE]);

// ===============
// Main Function
// ===============

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose[SIZE][SIZE];

    // Output the original matrices
    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("Matrix 2:\n");
    printMatrix(m2);

    // Add the matrices and display the result
    addMatrices(m1, m2, sum);
    printf("Sum of matrices:\n");
    printMatrix(sum);

    // Multiply the matrices and display the result
    multiplyMatrices(m1, m2, product);
    printf("\nProduct of matrices:\n");
    printMatrix(product);

    // Find the transpose of matrix 1 and display the result
    transposeMatrix(m1, transpose);
    printf("\nTranspose of matrix 1:\n");
    printMatrix(transpose);

    return 0;
}

// ======================
// Function Definitions
// ======================

/*
  Function addMatrices:
    This function adds two given matrices and stores them in a result matrix.
    Possible Error: The numbers of rows and cols must be equal.
*/
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {

    // Loop through the two dimensional array 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            // Add the elements together at the proper index into the result
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

/*
  Function multiplyMatrices:
    This function multiplies two given matrices and stores them in a result matrix.
    Possible Error: The number of columns of the first matrix must equal the number of rows in the second matrix.
*/
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {

    // Initialize the result matrix with all 0's
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    // Loop through the two dimensional array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) { // Loop for summing products

                // Multiply and add together the sum
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

}

/*
  Function transposeMatrix:
    This function finds the transpose of a matrix and stores it in a result matrix.
*/
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {

    // Loop through the two dimensional array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            // Swap the row and column for transpose
            result[j][i] = m[i][j];
        }
    }
}

/*
  Function printMatrix:
    This function prints a matrix.
*/
void printMatrix(int m[SIZE][SIZE]) {

    // Loop through the two dimensional array and print the element
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%5d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}