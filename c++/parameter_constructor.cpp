
#include <iostream>
using namespace std;
class complex {
    int *r,*i;
    public:
    complex(int , int );
    void display( );
};
complex::complex(int p, int q) //Parametrized Constructor
{
    r = new int(p);
    i = new int(q);
    
}
void complex::display( ) {
    cout<<"Content of r is "<<r<<endl;
    cout<<"Content of i is "<<i<<endl;
    cout<<"Value pointed by r is "<<*r<<endl;
    cout<<"Value pointed by i is "<<*i<<endl;
    delete r;
    delete i;
}

int main() {
    complex c1(10,20);
    complex c2 = c1;
    cout<<"**** Object c1 ****\n"; c1.display();
    cout<<"**** Object c2 ****\n"; c2.display();
    cout<<"hello";
    return 0;
}
