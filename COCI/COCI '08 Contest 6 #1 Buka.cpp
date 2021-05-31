#include <iostream>
#include <string>

using namespace std;

int main() {

    string num1, num2;
    char operation;
    
    cin >> num1;
    cin >> operation;
    cin >> num2;
    
    if(operation == '*') {
        if(num1.length() > num2.length()) {
            cout << num1 << num2.substr(1, num1.length()-1) << endl; 
        }else {
            cout << num2 << num1.substr(1, num2.length()-1) << endl; 
        }
    }else { 
        if(num1 == num2) {
            cout << 2 << num1.substr(1, num1.length()-1) << endl;    
        }else if(num1.length() > num2.length()) {
            cout << num1.substr(0, num1.length()-num2.length()) << num2 <<endl;
        }else {
            cout << num2.substr(0, num2.length()-num1.length()) << num1 << endl;
        }    
    }

    return 0;
}