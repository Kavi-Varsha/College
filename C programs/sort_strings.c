#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct string{
    char str[20];
};
int compare(struct string *s1, struct string *s2){
    int res=strcmp(s1->str,s2->str);
    if(res>0){
        return 1;
    }
    return 0;
}
void main(){
    int n,i,j;
    struct string temp;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    struct string *s=NULL;
    s=(struct string*) malloc (sizeof (struct string)*n);
    for (i=0;i<n;i++){
        scanf("%s",s[i].str);
    }
    for (i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if (compare(&s[j],&s[j+1])){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%s\t",s[i].str);
    }
    free (s);
}