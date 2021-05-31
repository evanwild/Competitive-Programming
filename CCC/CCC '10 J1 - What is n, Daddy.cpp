#include <iostream>

int main() {

    int n;
    std::cin >> n;

    if(n == 1 || n == 9 || n == 10) {
        std::cout << 1 << std::endl;
    }else if(n == 2 || n == 3 || n == 7 || n == 8) {
        std::cout << 2 << std::endl;
    }else {
        std::cout << 3 << std::endl;
    }

    return 0;
}