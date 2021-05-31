#include <iostream>

int main() {

    int month;
    int day;

    std::cin >> month >> day;

    if(month > 2 || (month == 2 && day > 18)) {
        std::cout << "After" << std::endl;
    }else if(month < 2 || (month == 2 && day < 18)) {
        std::cout << "Before" << std::endl;
    }else {
        std::cout << "Special" << std::endl;
    }

    return 0;
}