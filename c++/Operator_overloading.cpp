#include <iostream>
 using namespace std;
 class loc {
    int longitude, latitude;
    public:
        loc() {}  //ZPC
 
        loc(int lg, int lt) {longitude = lg; latitude = lt;}  //PC

        void show() 
        {
            cout << longitude << " ";
            cout << latitude << "\n";
        }

        loc operator+(const loc &) const;  //Overloading function (add two class objects)
        loc operator+(const int &) const;  //Overloading function (add one integer to class object)
 };


loc loc::operator+(const loc & op2) const        //Overloading function (add two class objects)
{       
    loc temp;
    temp.longitude = op2.longitude + longitude;
    temp.latitude = op2.latitude + latitude;
    return temp;
 }

loc loc::operator+(const int & op) const        //Overloading function (add one integer to class object)
{
    loc temp;
    temp.longitude = this->longitude + op;
    temp.latitude = this->latitude;
    return temp;
 }

 int main()
 {
    loc ob1(10, 20), ob2(5, 30), ob3, ob4(10,10);
    //ob1.show(); 
    //ob2.show();

    ob3 = ob1 + ob2;
    //ob3.show();

    ob3=ob1+10;
    //ob3.show();

    ob3=ob1+ob2+ob4;
    ob3.show();

    return 0;
 }