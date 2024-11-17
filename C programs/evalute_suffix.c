#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>
double compute(double op1,double op2, char symbol){
    switch(symbol){
        case '+':return op1+op2;
        case'-':return op1-op2;
        case'*':return op1*op2;
        case'/':return op1/op2;
        case'^':
        case'$':return pow(op1,op2);
    } 
}

int main(){
    char symbol,suffix[30];
    int n,i;
    double s[78];
    double op1,op2,res;
    int top=-1;
    printf("Enter suffix expression : ");
    scanf("%s",suffix);
    for(i=0;i<strlen(suffix);i++){
        symbol=suffix[i];
        if(isdigit(symbol)){
            s[++top]=symbol-'0';
        }
        else{
            op2=s[top--];
            op1=s[top--];
            res=compute(op1,op2,symbol);
            s[++top]=res;

        }
        
    }
    res=s[top--];
    printf("Result : %lf",res);
    return 0;
}