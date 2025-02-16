#include <iostream>
using namespace std;
int main(){
    void *p;
    int a=10;
    p=&a;
    cout<<*((int*)p)<<endl;  //typecasting the address
    char s[]={"Virtural functions"};
    p=s;
    cout<<((char *)p);
    return 0;
}