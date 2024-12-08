# include <iostream>
 using namespace std;
 //Template function
 template <class GT>
 void swapargs(GT &a, GT &b)
 {
    GT temp;
    temp = a;
    a = b;
    b = temp;
 }
 int main() 
 {
    int i=10, j=20;
    double x=10.1, y=23.3;
    char a='x', b='z';

    cout << "Original i, j: " << i << ' ' << j << '\n';
    cout << "Original x, y: " << x << ' ' << y << '\n';
    cout << "Original a, b: " << a << ' ' << b << '\n';

    swapargs(i, j); // swap integers
    swapargs(x, y); // swap floats
    swapargs(a, b); // swap chars

    cout << "Swapped i, j: " << i << ' ' << j << '\n';
    cout << "Swapped x, y: " << x << ' ' << y << '\n';
    cout << "Swapped a, b: " << a << ' ' << b << '\n';
    return 0;
 
}