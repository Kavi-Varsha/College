//friend function.
# include <iostream>
using namespace std;
class complex
{
private: int r, i;
public:
friend void accept(complex * );
void display() const;
};
void accept(complex *p )                  //if refernce is used then (complex (&p))      p.display();
{
cout<<"Enter r and i value\n";
cin>>p->r>>p->i;
p->display();
}
void complex:: display()const 
{
cout<<r<<"+i"<<i<<endl;
}
int main( ) {


complex c1;
accept(&c1);
//c1.display();
return 0;
}