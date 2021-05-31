#include <iostream>

int main() {

    int a3;
    int a2;
    int a1;
    int b3;
    int b2;
    int b1;

    std::cin >> a3 >> a2 >> a1;
    std::cin >> b3 >> b2 >> b1;

    int a_score = a3 * 3 + a2 * 2 + a1;
    int b_score = b3 * 3 + b2 * 2 + b1;

    if(a_score > b_score) {
        std::cout << 'A' << std::endl;
    }else if(b_score > a_score) {
        std::cout << 'B' << std::endl;
    }else {
        std::cout << 'T' << std::endl;
    }

    return 0;
}