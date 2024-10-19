#include <stdio.h>

// Recursive function to calculate the sum of natural numbers up to n
int sum_of_natural_numbers(int n) {
    // Base case: if n is 1, return 1
    if (n == 1) {
        return 1;
    }
    // Recursive case: sum current number with the sum of previous numbers
    else {
        return n + sum_of_natural_numbers(n - 1);
    }
}  

int main() {
    int n;
    // Prompt user to enter a value
    printf("Enter a value: ");
    scanf("%d", &n);
    // Ensure the value is positive before calculating the sum
    if(n > 0) {
        // Print the result of sum of natural numbers
        printf("Sum of %d natural numbers: %d\n", n, sum_of_natural_numbers(n));
    }
    return 0;
}