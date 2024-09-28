#include <iostream>
//#include <cstring>
using namespace std;
struct student{
    char n[20];
    int age;
    float marks[4];
};
void accept(student *r){
    cin>>r->n>>r->age>>r->marks[0]>>r->marks[1]>>r->marks[2]>>r->marks[3];
}

void display(student *r){
    cout<<endl<<r->n<<endl<<r->age<<endl<<r->marks[0]<<endl<<r->marks[1]<<endl<<r->marks[2]<<endl<<r->marks[3];
}

int main(){
    student *p=NULL,*q=NULL,*t;
    p=new student;
    q=new student;
    accept(p);
    accept(q);
    t=p;
    p=q;
    q=t;
    display(p);
    display(q);
    
    return 0;

}