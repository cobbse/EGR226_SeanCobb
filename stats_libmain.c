#include <stdio.h>
#include <stdlib.h>
#include "stats_lib.h"
#include "stats_lib.c"
#define MAX_SIZE 500

int main(void)
{
    //declare variables
    int i, number;
    FILE* fp;
    float nums[MAX_SIZE], large, small, avg, middle, variation, sd;

    //open file and check if it exists
    fp = fopen("data.txt", "rt");
    if(fp == NULL){
        printf("File does not exist.\n");
        return 0;
    }

    //read data from file into array and keep track of how many numbers there are
    i = 0;
    number = 0;
    while(fscanf(fp, "%g", &nums[i]) == 1){
        i++;
        number++;
    }
    if(! feof(fp)){
        printf("Floating point number did not form correctly");
    }

    //call maximum function and print value
    large = maximum(nums, number);
    printf("Maximum: %0.3lf\n", large);

    //call minimum function and print value
    small = minimum(nums, number);
    printf("Minimum: %0.3lf\n", small);

    //call mean function and print value
    avg = mean(nums, number);
    printf("Mean: %0.3lf\n", avg);

    //call median function and print value
    middle = median(nums, number);
    printf("Median: %0.3lf\n", middle);

    //call variance function and print value
    variation = variance(nums, number);
    printf("Variance: %0.3lf\n", variation);

    //call standard deviation function and print value
    sd = standard_deviation(nums, number);
    printf("Standard Deviation: %0.3lf\n", sd);

    return 0;
}
