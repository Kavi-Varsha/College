#include <iostream>
using namespace std;
class complex {
        int *r,*i;
    public:
        complex()
        {
            r=new int (0);
            i=new int (0);
            cout<<"ZPC called \n";
        }

        complex(int a, int b)
        {
            r=new int (a); //zpc will not to called if we are passing parametrs in object
            i=new int (b);
            cout<<"In parameter constructor\n";
        }

        complex (const complex &s)
        {
            this->r=new int(*(s.r));
            (*this).i=new int(*(s.i));
            cout<<"Copy constructor called\n";

        }

        void display()
        {
            cout<<r<<"\t"<<(*r)<<"\n";
            cout<<i<<"\t"<<(*i)<<endl;
        }

        ~complex(){
            cout<<"In destructor \n";
            cout<<"Address of object \t"<<this<<endl;   //CC will be deleted first, then PC, then ZPC
            delete this->r;
            delete i;
        }
        
};
int main() {
    complex c1; //Zpc is called
    complex c2(10,20); //pc is called
    complex c3(c1); //cc is called
    cout<<"Address of object c1\t"<<&c1<<endl;
    cout<<"Address of object c2\t"<<&c2<<endl;
    cout<<"Address of object c3\t"<<&c3<<endl;
    c1.display();
    c2.display();
    c3.display();
    return 0;
}
