//friend function.
# include <iostream>
using namespace std;
class complex
{
private: int r, i;
public:
 void accept();
void display() const;
friend void add( complex &, complex &, complex &);
};
void complex :: accept()                  //if refernce is used then (complex (&p))      p.display();
{
cout<<"Enter r and i value\n";
cin>>r>>i;
//p->display();
}

void add( complex &c1, complex &c2, complex &c3){
    c1.accept();
    c2.accept();
    c3.r=c1.r+c2.r;
    c3.i=c1.i+c2.i;
    c3.display();
}
void complex:: display()const 
{
cout<<r<<"+i"<<i<<endl;
}
int main( ) {


complex c1,c2,c3;
//accept(c1);
//accept(c2);
add(c1,c2,c3);
//c1.display();
return 0;
}