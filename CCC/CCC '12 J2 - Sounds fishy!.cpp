#include <iostream>

int main() {

    int a;
    int b;
    int c;
    int d;

    std::cin >> a >> b >> c >> d;

    if(a == b && b == c && c == d) {
        std::cout << "Fish At Constant Depth" << std::endl;
    }else if(a > b && b > c && c > d) {
        std::cout << "Fish Diving" << std::endl;
    }else if(d > c && c > b && b > a) {
        std::cout << "Fish Rising" << std::endl;
    }else {
        std::cout << "No Fish" << std::endl;
    }

    return 0;
}