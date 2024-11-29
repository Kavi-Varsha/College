# include <iostream>
 using namespace std;
 class base
 {
 
   public:
   virtual void display()
   { cout<<"In base\n"; }
};

 class derived : public base
 {
   public:
   void display()
   { cout<<"In dervied\n"; }
 };

 int main() {
   base *ptr;
   derived obj;
   ptr = &obj;
   ptr->display();
   ((derived *)ptr)->display();
   return 0; 
}