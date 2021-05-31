#include <iostream>

int main() {

    int one;
    int two;
    int three;
    int four;

    std::cin >> one >> two >> three >> four;

    if((one == 8 || one == 9) && (four == 8 || four == 9) && (two == three)) {
        std::cout << "ignore" << std::endl;
    }else {
        std::cout << "answer" << std::endl;
    }

    return 0;
}