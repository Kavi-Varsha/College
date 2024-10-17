#include <stdio.h>
#include <stdlib.h>
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

int main(){
    int n;
    printf("Enter number of employees : ");
    scanf("%d",&n);
    struct employee *p=NULL;
    accept(p,n);
    display(p,n);
    return 0;
}