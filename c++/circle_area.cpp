#include <iostream>
using namespace std;
class circle{
    float radius;
    public:
        void accept();
        void display()const;
        circle area()const;
};

void circle :: accept(){
    cout<<"enter radius:";
    cin>>radius;
}

void circle :: display()const{
    cout<<"radius : "<<radius<<endl;
}

circle circle :: area()const{
    circle area=radius*radius;
    //cout<<"area : "<<area<<endl;
    float cir=2*3.14*radius;
    //cout<<"cirumference : "<<cir<<endl;
    return area;
}
int main(){
    circle *c1=NULL;
    int n;
    cin>>n;
    c1=new circle [n];
    for (int i=0;i<n;c1[i].accept(),i++);
    for (int i=0;i<n;c1[i++].display());
    for (int i=0;i<n;(c1[i++].area()).display());
    //c1.accept();
    //c1.display();
    //c1.area();
    //c2.display();
    return 0;
}
