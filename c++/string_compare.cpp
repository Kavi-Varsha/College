#include <iostream>
#include <cstring>
using namespace std;

class strings {
    char s[20];
public:
    // Default constructor
    strings() {}
    
    // Function to accept input for the string
    void accept() {
        cin >> s;
    }
    
    // Function to display the string
    void show()const {
        cout << "String value is " << s << endl;
    }
    
    // Overloading the equality operator to compare two strings
    int operator==(const strings &s2)const {
        return strcmp(s, s2.s);
    }
};

int main() {
    strings s1, s2;
    
    // Accept input for both string objects
    s1.accept();
    s2.accept();
    
    // Display both strings
    s1.show();
    s2.show();
    
    // Compare the two strings using the overloaded == operator
    int res = (s1 == s2);
    
    // Check the result and print if strings are equal or not
    if (res == 0) {
        cout << "Strings are equal\n";
    } else {
        cout << "Strings are not equal\n";
    }
    
    return 0;
}
