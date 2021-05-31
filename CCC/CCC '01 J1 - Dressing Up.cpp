#include <iostream>

int main() {

    int h;
    std::cin >> h;

    int stars = 1;
    int spaces = (2 * h) - 2;

    for(int i = 0; i < (h - 1) / 2; i++) {

        for(int i = 0; i < stars; i++) {
            std::cout << '*';
        }

        for(int i = 0; i < spaces; i++) {
            std::cout << ' ';
        }

        for(int i = 0; i < stars; i++) {
            std::cout << '*';
        }

        std::cout << std::endl;

        stars += 2;
        spaces -= 4;
    }

    for(int i = 0; i < h * 2; i++) {
        std::cout << '*';
    }

    std::cout << std::endl;

    for(int i = 0; i < (h - 1) / 2; i++) {

        stars -= 2;
        spaces += 4;

        for(int i = 0; i < stars; i++) {
            std::cout << '*';
        }

        for(int i = 0; i < spaces; i++) {
            std::cout << ' ';
        }

        for(int i = 0; i < stars; i++) {
            std::cout << '*';
        }

        std::cout << std::endl;

    }

    return 0;
}