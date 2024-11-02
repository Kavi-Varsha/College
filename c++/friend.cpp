 #include <iostream>
 using namespace std;
 class loc {
    int longitude, latitude;
    public:
    loc() {}
    loc(int lg, int lt) : longitude (lg), latitude (lt) {};
    void show() {
        cout << longitude << " ";
        cout << latitude << "\n";
    }
    friend loc operator+(const loc &, const loc &) ;
    friend loc operator+=(loc &, const loc &) ;
    friend loc operator-(const loc &, const loc &) ;
    loc &operator=(const loc & );
    
 };
 
// Overload += for loc, shorthand operator
 loc operator+=(loc &op1,const loc & op2)
 {
    op1.longitude = op2.longitude + op1.longitude;
    op1.latitude = op2.latitude + op1.latitude;
    return op1;
 }


 // Overload + for loc.
 loc operator+(const loc & op1,const loc &op2)
 {
    loc temp;
    temp.longitude = op2.longitude + op1.longitude;
    temp.latitude = op2.latitude + op1.latitude;
    return temp;
 }


 // Overload- for loc.
loc operator-(const loc & op1,const loc &op2)
 {
    loc temp;
    temp.longitude = op1.longitude - op2.longitude;
    temp.latitude = op1.latitude - op2.latitude;
    return temp;
 }


 //Overload assignment for loc.
 loc & loc :: operator=(const loc &op2) //return by refernce. *this will be directly sent to invoking obj
 {
    longitude = op2.longitude;
    latitude = op2.latitude;
    return *(this);
 }
 
 int main() {
    loc ob1(10, 20), ob2( 5, 30), ob3(90, 90);
    cout<<"ob1 value "; ob1.show();
    cout<<"ob2 value "; ob2.show();

    cout<<"Multiple assignment...\n";
    ob1 = ob2 = ob3; // multiple assignment
    cout<<"ob1 value "; ob1.show(); // displays 90 90
    cout<<"ob2 value "; ob2.show(); // displays 90 90

    cout<<"Calling += operator function\n";
    ob3 += ob1;
    cout<<"ob1 value "; ob1.show();
    cout<<"ob3 value "; ob3.show();

    cout<<"Calling + operator function\n";
    ob3 = ob1 + ob2;
    cout<<"ob3 value ";
    ob3.show();

    cout<<"Calling- operator function\n";
    ob3 = ob1- ob2;
    cout<<"ob3 value "; 
    ob3.show();
    return 0; 
 }