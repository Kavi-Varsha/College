#include <stdio.h>
int sum_of_array(int n, int a[]){
    sum[0]=a[0];
    if (n==0){
        return a[0];
    }
    else{
        return a[n]+sum_of_array(n-1,a[n-1]);
    }
}
int main(){
    int n, a[20];
    printf("Enter a value : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Sum of array elements : %d \n",n,sum_of_array(n,a));
    
    return 0;
}