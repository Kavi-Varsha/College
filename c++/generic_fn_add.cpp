#include <iostream>
using namespace std;

class cmp
{
    int r,i;
    public: void accept(){ cout<<"Enter r and i:"<<endl; cin>>r>>i;}
    void display(){cout<<"r : "<<r<<"i : "<<i<<endl;}
    friend ostream& operator<<(ostream &out, const cmp &x);
    friend cmp operator+(const cmp&,const cmp&);

};

cmp operator+(const cmp &a, const cmp &b)
{
    cmp t;
    t.r=a.r+b.r;
    t.i=a.i+b.i;
    return t;
}

ostream& operator<<(ostream &out, const cmp &x){
    out<<"Addition of class objects"<<endl<<x.r<<"i+"<<x.i;
    return out;
}

template <class gt>
void add(gt a,gt b){
    gt t;
    t=a+b;
    cout<<t<<endl;
}

int main(){
    class cmp c1,c2;
    c1.accept(); c2.accept();
    //c1.display(); c2.dsiplay();
    add(c1,c2);
    int a=10,b=20;
    add(a,b);
    return 0;
}