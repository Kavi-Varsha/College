#include <stdio.h>
int sum_of_natural_numbers (int n){
    if (n==1){
        return 1;
    }
    else{
        return n+sum_of_natural_numbers(n-1);
    }
}
int main(){
    int n;
    printf("Enter a value : ");
    scanf("%d",&n);
    printf("Sum of %d natural numbers : %d",n,sum_of_natural_numbers(n));
    return 0;
}