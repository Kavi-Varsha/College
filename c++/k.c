#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct activity{
    char *day;
    int date;
    char *desc;
};
typedef struct activity plan;
plan * create(){
    plan *p=(plan *) malloc (sizeof(plan) *7);
    if (p==NULL){
        printf("no memory");
        exit(0);
    }
    return p;
}

void accept(plan *p, int n){
    for (int i=0;i<n;i++){
        p[i].day=(char *) malloc (10);
        printf("enter day\n");
        scanf("%s",p[i].day);
        printf("enter date\n");
        scanf("%d",&p[i].date);
        printf("enter disceription\n");
        p[i].desc=(char *) malloc (400);
        scanf("%s",p[i].desc);

        p[i].desc=(char *)realloc(p[i].desc,strlen(p[i].desc)+1);

    }
}

void display(plan *p, int n){
    for (int i=0;i<n;i++){
        //p[i].day=(char *) malloc (10);
        printf("day\n");
        printf("%s",p[i].day);
        printf("date\n");
        printf("%d",p[i].date);
        printf("disceription\n");
        //p[i].desc=(char *) malloc (400);
        printf("%s",p[i].desc);
}}
void main(){
    plan *a=NULL;
    int n;
    printf("enter value of n \n");
    scanf("%d",&n);
    a=create();
    accept(a,n);
    display(a,n);

}