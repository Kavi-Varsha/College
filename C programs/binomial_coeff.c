#include <stdio.h>

// Recursive function to calculate factorial of n
int fact(int n) {
    // Base case: if n is 1 or 0, return 1
    if (n == 1 || n == 0) {
        return 1;
    }
    // Recursive case: multiply current number with factorial of previous numbers
    else {
        return n * fact(n - 1);
    }
}

int main() { 
    int n, r, result;
    // Prompt user to enter values for n and r
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of r: ");
    scanf("%d", &r);
    
    // Ensure that n and r are positive and n >= r
    if (n >= 0 && n >= r && r >= 0) {
        // Calculate binomial coefficient
        result = fact(n) / (fact(r) * fact(n - r));
        // Print the result
        printf("Binomial coefficient of (%d, %d): %d\n", n, r, result);
    } 
    else {
        printf("Invalid input. Please ensure n and r are non-negative and n >= r.\n");
    }
    
    return 0;
}
