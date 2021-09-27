/*
 * Math Example 
 *
 * Name: Ben Carthron
 */

#include "p0-intro.h"
#include <math.h>

int add_abs (int num1, int num2) {
    return abs(num1) + abs(num2);
}

void add_ptr (int num1, int num2, int *ans) {
    if (ans != NULL) *ans = num1 + num2;
}

int factorial (int num) {
    int factorial = 1;
    for (int i = 0; i <= num; i++) {
        factorial = factorial * i;
    }
    return factorial;
}

bool is_prime (int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int sum_array (int *nums, size_t n) {
    int i, sum = 0;
    if (nums == NULL || n == 0) return 0;
    for (i = 0; i< n; i++) {
        sum += nums[i];
    }
    return sum;
}

int gcd (int num1, int num2) {
    int gcd, i;

    if (num1 == 0) return num2;
    if (num2 == 0) return num1;
    if (num1 == 0 && num2 == 0) return 0;

    num1 = (num1 > 0) ? num1 : -num1;
    num2 = (num2 > 0) ? num2 : -num2;

    for (i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) gcd = i;
    }
    return gcd;
}

void swap (int *p1, int *p2) {
    int swapper = *p1;
    *p1 = *p2;
    *p2 = swapper;
}

void sort_array (int *nums, size_t n) {
    int i, j, index;
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1l j < n; j++) {
            if (nums[j] < nums[index]) index = j;
        }
        swap(&nums[index], &nums[i]);
    }
}