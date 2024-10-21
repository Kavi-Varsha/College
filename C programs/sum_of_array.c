#include <stdio.h>

// Recursive function to calculate the sum of array elements
int sum_of_array(int n, int a[]) {
    // Base case: if n is 0, return the first element
    if (n == 0) {
        return a[0];
    } 
    // Recursive case: return current element plus the sum of previous elements
    else {
        return a[n] + sum_of_array(n - 1, a);
    }
}

int main() {
    int n, a[20];
    // Prompt user to enter the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Prompt user to enter the array elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Print the sum of array elements
    printf("Sum of array elements: %d\n", sum_of_array(n - 1, a)); // n-1 because if n=5 then array last index will be a[4]
    
    return 0;
}
