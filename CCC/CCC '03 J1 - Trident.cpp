#include <iostream>

int main() {

    int t;
    int s;
    int h;

    std::cin >> t >> s >> h;

    for(int i = 0; i < t; i++) {
        std::cout << '*';
        for(int j = 0; j < s; j++) {
            std::cout << ' ';
        }
        std::cout << '*';
        for(int j = 0; j < s; j++) {
            std::cout << ' ';
        }
        std::cout << '*';
        std::cout << std::endl;
    }

    for(int i = 0; i < 3 + (s * 2); i++) {
        std::cout << '*';
    }

    std::cout << std::endl;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < 1 + s; j++) {
            std::cout << ' ';
        }
        std::cout << '*' << std::endl;
    }

    return 0;
}