#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee{
    char name[20];
    int eid;
    float sal;
};
typedef struct employee emp;
void accept(emp *p, int n){
    printf("Employee details : \n\n");
    for(int i=0;i<n;i++){
        printf("Enter name employee_id and salary of employee %d : ",i+1);
        scanf("%s%d%f",p[i].name,&p[i].eid,&p[i].sal);
    }
}
void display(emp *p, int n){
    printf("Employee details : \n");
    for(int i=0;i<n;i++){
        printf("Name : %s Employee_id : %d Salary of employee : %f : ",p[i].name,p[i].eid,p[i].sal);
        printf("\n");
    }
}
void search (emp *p,int n, char *key){
    for(int i=0;i<n;i++){
        if(strcmp(key,p[i].name)==0){
            printf("Name %s found\n",p[i].name);
            exit(0);
        }
        
    }
    printf("Name not found");
}
int main(){
    int n;
    char key[20];
    
    printf("Enter number of employees : ");
    scanf("%d",&n);
    struct employee *p=NULL;
    p=(emp *) malloc (sizeof (emp)*n);
    accept(p,n);
    display(p,n);
    printf("Enter name to be searched : ");
    scanf("%s",key);
    search(p,n,key);
    free (p);
    return 0;
}