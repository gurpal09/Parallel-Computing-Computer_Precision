/*
 ============================================================================
 Name        : HW2_problem2.c
 Author      : Gurpal Singh
 Version     :
 Copyright   :
 Description : Homework2 Problem2 Parts a and b
 To compile  : gcc -Wall HW2_problem2.c -std=c99 -o HW2_problem2.c -O3
 To execute : ./HW2_problem2.exe
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int main()
{
    int x; // Initialize integer x
    printf("Enter an integer value for x: ");
    scanf("%d", &x); // Get user input integer x
    // SINGLE PRECISION
    float sum_sp = 1.0f; // starting the sum at 1 to account for the first term in the series
    int n_sp = 0; // Initialize integer n
    float fac_sp = 1.0f; // Initialize factorial term
    float a_sp = (pow(x, n_sp) / fac_sp); // Initialize series term
    while (a_sp > FLT_EPSILON) {
        n_sp++;
        fac_sp = fac_sp * n_sp;
        a_sp = (pow(x, n_sp) / fac_sp);
        sum_sp = sum_sp + a_sp;
    }
    printf("Single precision result: %.6f\n", sum_sp); // Print results to screen
    float part_b_sp = 1.0f / sum_sp; // Calculating the result for part b
    printf("Part b Single Precision: %.6f\n", part_b_sp);

    // Double PRECISION
    double sum_dp = 1.0; // Starting sum at 1 to account for first term in series
    int n_dp = 0; // Initialize n for double precision
    double fac_dp = 1.0; // Initialize factorial term
    double a_dp = (pow(x, n_dp) / fac_dp); // Initialize series term
    while (a_dp > DBL_EPSILON) {
        n_dp++;
        fac_dp = fac_dp * n_dp;
        a_dp = (pow(x, n_dp) / fac_dp);
        sum_dp = sum_dp + a_dp;
    }
    printf("Double precision result: %.15lf\n", sum_dp); // Print results to screen
    double part_b_dp = 1.0 / sum_dp; // Calculating the result for part b
    printf("Part b Double Precision: %.15lf\n", part_b_dp);

    double e = exp(x); // Using the built in math function to calculate result
    printf("Built-in math function exp(x) result: %.15lf\n", e); // Print result to screen

    FILE *fptr = fopen("part2_results.txt", "a+"); // Writing the results to a file
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, "For x = %d\n", x);
    fprintf(fptr, "Single Precision Result: %.6f\n", sum_sp);
    fprintf(fptr, "Double Precision Result: %.15lf\n", sum_dp);
    fprintf(fptr, "Built-in math function exp(x) result: %.15lf\n", e);
    fprintf(fptr, "Part b: \n");
    fprintf(fptr, "Single Precision: %.6f\n", part_b_sp);
    fprintf(fptr, "Double Precision: %.15lf\n", part_b_dp);
    fprintf(fptr, "\n");
    fclose(fptr);
    return 0;
}
