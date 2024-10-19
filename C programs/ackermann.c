// The Ackermann function is a well-known example of a recursive function
// that is not primitive recursive. It grows very quickly.

#include <stdio.h>
int A(int m, int n) {
    // Base case: If m is 0, return n + 1
    if(m == 0) {
        return n + 1;
    }
    // Recursive case: If m > 0 and n is 0, A(m-1,1)
    else if(m > 0 && n == 0) {
        return A(m - 1, 1);
    }
    // Recursive case: If m > 0 and n > 0, A(m-1,A(m, n-1))
    else {
        return A(m - 1, A(m, n - 1));
    }
}
 
int main() {
    int m, n, res; 
    // Prompt the user to enter two values
    printf("Enter two values (m and n) : ");
    scanf("%d %d", &m, &n);
    // Calculate the Ackermann function result
    res = A(m, n);
    // Display the result
    printf("Result is : %d \n", res);
    return 0;
}
