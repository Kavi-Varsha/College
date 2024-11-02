#include <iostream>
 using namespace std;
 class loc {
        int longitude, latitude;
    public:
        loc() {}  //ZPC
        loc(int lg, int lt) : longitude (lg), latitude (lt) {};   //PC
        void show() {
        cout << longitude << " ";
        cout << latitude << "\n";
        }
        loc operator+(const loc &) const;
        //loc operator-(const loc &) const;
        loc operator=(loc );
        loc operator++();
        loc operator++(int);
        //loc operator+=(const loc &);
 };

loc loc::operator=(loc op2)
{
    cout<< this<<endl;
    longitude = op2.longitude;
    latitude = op2.latitude;
    return *this; // i.e., return object that generated call
}

loc loc::operator+(const loc & op2) const
{
    loc temp;
    temp.longitude = op2.longitude + longitude;
    temp.latitude = op2.latitude + latitude;
    return temp;
}

 loc loc::operator++()
 {
    cout<< this<<endl;
    cout<<"In prefix ++\n" ;
    longitude++; latitude++;
    return *this;  //returns value like return temp
 
 }

 loc loc::operator++(int x)
 {
    cout<<"In postfix ++\n" ;
    loc t = (*this);
    longitude++; latitude++;
    return t; 
 }

int main() {
    loc ob1(10, 20), ob2( 5, 30), ob3(90, 90);

    cout<<"ob1 value "; ob1.show();
    cout<<"ob2 value "; ob2.show();

    ++ob1;   
    //cout<<"ob1 value "; ob1.show(); // displays 11 21 

    ob2 = ++ob1;
    //cout<<"ob1 value "; ob1.show(); // displays 12 22
    //cout<<"ob2 value "; ob2.show(); // displays 12 22

    ob3=(ob1++)+(++ob2);
    ob3.show();
    /*cout<<"Multiple assignment...\n";
    ob1 = ob2 = ob3; // multiple assignment
    cout<<"Address of o1 : "<<&ob1<<endl;
    cout<<"Address of o2 : "<<&ob2<<endl;
    cout<<"Address of o2 : "<<&ob3<<endl;
    cout<<"ob1 value "; ob1.show(); // displays 90 90
    cout<<"ob2 value "; ob2.show();*/

    return 0;
}