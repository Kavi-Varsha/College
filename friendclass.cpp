#include <iostream>
using namespace std;
class complex
{
private: int r, i;
public:
//complex ( )
//{ cout<<"*** ZPC called ***\n"; r=0; i=0; }
};

int main( ) {
cout<<"Object created:\n"; complex p1; // ZPC called
cout<<"Pointer created\n";
complex *p=NULL; // ZPC not called
cout<<"Address of an object is placed in a pointer\n";
p = &p1; // ZPC not called
cout<<"Memory for an object is acquired dynamically: ";
p = new complex( ); // ZPC called
delete p;
cout<<"Array of 3 objects created (automatic memory allocation)\n";
complex ar[3]; // ZPC called 3 times
cout<<"Array of 3 objects created (DMA)\n";
p = new complex[3]; // ZPC called 3 times
delete []p; return 0; }