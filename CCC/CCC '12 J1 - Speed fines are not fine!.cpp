#include <iostream>

int main() {

    int limit;
    int speed;

    std::cin >> limit >> speed;

    int over = speed - limit;

    if(over >= 1 && over <= 20) {
        std::cout << "You are speeding and your fine is $100." << std::endl;
    }else if(over >= 21 && over <= 30) {
        std::cout << "You are speeding and your fine is $270." << std::endl;
    }else if(over >= 31) {
        std::cout << "You are speeding and your fine is $500." << std::endl;
    }else {
        std::cout << "Congratulations, you are within the speed limit!" << std::endl;
    }

    return 0;
}