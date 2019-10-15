/*
 ============================================================================
 Name        : HW2.c
 Author      : Gurpal Singh
 Version     :
 Copyright   :
 Description : Homework2 Problem1
 To compile  : gcc -Wall HW2.c -std=c99 -o HW2.c -O3
 To execute : ./HW2.exe
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include "timer.h"

int main()
{

    // Part a
    printf("The largest positive integer that can be represented on a 64-bit computer = %u\n",
           UINT_MAX);

    // Part b
    printf("The machine epsilon for single precision = %.4e\n", FLT_EPSILON);
    printf("The machine epsilon for double precision = %.4e\n", DBL_EPSILON);

    // Part c
    // Single Precision
    int n_sp = 1.0; // Define int n
    float sum_sp = 0.0f; // Define sum single precision
    float a_sp = 1.0f / n_sp; // Define term
    StartTimer();
    while ((a_sp) > FLT_EPSILON) {
        sum_sp += a_sp;
        n_sp++;
        a_sp = 1.0f / n_sp;
    }

    double elapsedTime_sp = GetTimer(); // Get the time to execute single precision calculation

    printf("Sum_sp = %.6f\n", sum_sp); // Print Results to screen
    printf("n_sp = %d\n", n_sp);
    printf("Time elapsed in single precision: %f s\n", elapsedTime_sp);

    // Double Precision

    long n_dp = 1; // Defining n for double precision
    double sum_dp = 0.0; // Defining sum for double precision
    double a_dp = 1.0 / n_dp; // Defining series term
    StartTimer(); // Starting the timer
    char stringNAME[30]; // Initializing char to stop while loop if needed
    long count = 1000000000000; // Increment n by this much if user chooses to continue when
                                // prompted
    while ((a_dp) > DBL_EPSILON || n_dp < UINT_MAX) {

        if (n_dp > count) { // Allows user to stop if desired when n_dp passes count
            printf("n_dp = %lu\n", n_dp);
            printf("To continue press any key\n");
            printf("To stop the program type 'stop'\n");
            scanf("%s", stringNAME);
            if (strcmp(stringNAME, "stop") == 0) {
                break; // If the user enters stop, the loop will break
            } else {
                count = count + 1000000000000;
                continue;
            }
        }
        sum_dp += a_dp; // Calculation of the series sum
        n_dp++;
        a_dp = 1.0 / n_dp;
    }

    double elapsedTime_dp = GetTimer(); // Get the time elapsed for double precision calculation

    printf("Sum_dp = %.6f\n", sum_dp); // Printing the results to screen
    printf("n_dp = %lu\n", n_dp);
    printf("Time elapsed in double precision: %f s\n", elapsedTime_dp);

    FILE *fptr = fopen("Homework2.txt", "a+"); // Creating/Appending to a file
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "Part a:\n");
    fprintf(fptr,
            "The largest positive integer that can be represented on a 64-bit computer = %u\n",
            UINT_MAX);
    fprintf(fptr, "\n");
    fprintf(fptr, "Part b:\n");
    fprintf(fptr, "The machine epsilon for single precision = %.4e\n", FLT_EPSILON);
    fprintf(fptr, "The machine epsilon for double precision = %.4e\n", DBL_EPSILON);
    fprintf(fptr, "\n");
    fprintf(fptr, "Part c:\n");
    fprintf(fptr, "Value of n for single precision: %d\n", n_sp);
    fprintf(fptr, "Value of sum for single precision: %.6f\n", sum_sp);
    fprintf(fptr, "Time elapsed for single precision: %f s\n", elapsedTime_sp);
    fprintf(fptr, "\n");
    fprintf(fptr, "Value of n for double precision: %lu\n", n_dp);
    fprintf(fptr, "Value of sum for double precision: %.16f\n", sum_dp);
    fprintf(fptr, "Time elapsed for double precision: %f s\n", elapsedTime_dp);
    fprintf(fptr, "\n");
    fclose(fptr);
    return (0);
}

