#include <iostream>
 using namespace std;
 class number {
 protected: int val;
 public:
 void setval(int i) { val = i; }
 // show() is a pure virtual function
 virtual void show() = 0;
 };
 
class hextype : public number {
 public:
 void show()
 { cout << hex << val << "\n"; }
 //hex is a manipulator that converts the next numerical value to hexadecimal value.
 };
 class dectype : public number {
 public:
 void show()
 { cout << val << "\n"; }
 };
 class octtype : public number {
 public:
 void show()
 { cout << oct << val << "\n"; }
 //oct is a manipulator that converts the next numerical value to octal value.
 };
 int main( ) {
 dectype d; hextype h; octtype o;
 d.setval(20);
 d.show();
 // displays 20- decimal
 h.setval(20);
 h.show();
 o.setval(20);
 o.show();
 return 0;
 }