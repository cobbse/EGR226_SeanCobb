#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "stats_lib.h"
#include <stdlib.h>

//find largest number and output value
float maximum(float nums[], int n){
    int i;
    float max;
    max = nums[0];
    for(i = 1; i < n; i++){
        if(nums[1] > max){
            max = nums[i];
        }
    }
    return max;
}

//find smallest number and output value
float minimum(float nums[], int n){
    int i;
    float min;
    min = nums[0];
    for(i = 1; i < n; i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    return min;
}

//within a set of numbers, find the mean and output the value
float mean(float nums[], int n){
    int i;
    float sum;
    sum = 0;
    for(i = 0; i < n;  i++){
        sum = sum + nums[i];
    }
    return sum/n;
}

//sort the numbers into numerical order from least to greatest, then find median and output the value
float median(float nums[], int n){
    int i, j, number;
    float middle;
    if(nums[0] > nums[1]){
        float temp;
        temp = nums[0];
        nums[0] = nums[1];
        nums[1] = temp;
    }
    for(i = 2; i < n; i++){
        for(j = 0; j < i; j++){
            if(nums[j] > nums[i]){
                float temp;
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
    number = n/2;
    middle = nums[number];
    return middle;
}

//find the variance and return the value
float variance(float nums[], int n){
    int i;
    float sum = 0, ave;
    ave = mean(nums, n);
    for(i = 0; i < n; i++){
        sum = sum + (pow((nums[i] - ave), 2));
    }
    return sum/(n-1);
}

//find the standard deviation and output the value
float standard_deviation(float nums[], int n){
    float sd, vary;
    vary = variance(nums, n);
    sd = sqrt(vary);
    return sd;
}
