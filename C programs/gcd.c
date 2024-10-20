#include <stdio.h>

int main() {
    int m, n, i;
    int r1[40], r2[40], q[15], r[15];

    // Prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &m, &n);

    // Initialize the larger number as r2[0] and the smaller as r1[0]
    if (m > n) {
        r2[0] = m;
        r1[0] = n;
    } else {
        r1[0] = m;
        r2[0] = n;
    }

    // Loop to apply Euclid's algorithm
    for (i = 0; r1[i] != 0; i++) {
        q[i] = r2[i] / r1[i];     // Calculate quotient
        r[i] = r2[i] % r1[i];     // Calculate remainder
        r2[i + 1] = r1[i];        // Move current r1 value to r2 position
        r1[i + 1] = r[i];         // Move current remainder to next r1 position
    }

    // Print the GCD, which is the last non-zero remainder
    printf("GCD is %d\n", r1[i - 1]);

    return 0;
}
