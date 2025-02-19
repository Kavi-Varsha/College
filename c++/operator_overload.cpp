#include <iostream>
 using namespace std;
 class loc {
    int longitude, latitude;
    public:
        loc() {}
        loc(int lg, int lt) : longitude (lg), latitude (lt) {};
        void show() 
        {
        cout << longitude << " ";
        cout << latitude << "\n";
        }
        
        loc operator+(const loc &) const;
        loc operator-(const loc &) const;
        loc operator=(loc );
        loc operator++();
        loc operator++(int);
        loc operator+=(const loc &);
 };
 
// Overload += for loc, shorthand operator
 loc loc::operator+=(const loc & op2)
 {
    longitude = op2.longitude + longitude;
    latitude = op2.latitude + latitude;
    return *this;
 }

 // Overload + for loc.
 loc loc::operator+(const loc & op2) const
 {
    loc temp;
    temp.longitude = op2.longitude + longitude;
    temp.latitude = op2.latitude + latitude;
    return temp;
 }

 // Overload- for loc.
 loc loc::operator-(const loc & op2) const
 {
    loc temp;
    // notice order of operands
    temp.longitude = longitude- op2.longitude;
    temp.latitude = latitude- op2.latitude;
    return temp;
 }

 // Overload assignment for loc.
 loc loc::operator=(loc op2)
 {
    longitude = op2.longitude;
    latitude = op2.latitude;
    return *this; // i.e., return object that generated call
 }

 // Overload prefix ++ for loc.
 loc loc::operator++()
 {
    cout<<"In prefix ++\n" ;
    longitude++; latitude++;
    return *this;
 
 }

// Overload postfix ++ for loc.
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
    cout<<"ob1 value "; ob1.show(); // displays 11 21

    ob2 = ++ob1;
    cout<<"ob1 value "; ob1.show(); // displays 12 22
    cout<<"ob2 value "; ob2.show(); // displays 12 22

    cout<<"Multiple assignment...\n";
    ob1 = ob2 = ob3; // multiple assignment
    cout<<"ob1 value "; ob1.show(); // displays 90 90
    cout<<"ob2 value "; ob2.show(); // displays 90 90

    ob2 = ob1++;
    cout<<"ob1 value "; ob1.show();
    cout<<"ob2 value "; ob2.show();

    cout<<"Calling += operator function\n";
    ob3 += ob1;
    cout<<"ob1 value "; ob1.show();
    cout<<"ob3 value "; ob3.show();

    cout<<"Calling + operator function\n";
    ob3 = ob1 + ob2;
    cout<<"ob3 value "; ob3.show();

    cout<<"Calling- operator function\n";
    ob3 = ob1- ob2;
    cout<<"ob3 value "; ob3.show();

    return 0; 
 
}
