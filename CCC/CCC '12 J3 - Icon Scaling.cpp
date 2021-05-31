#include <iostream>

int main() {

    int k;
    std::cin >> k;

    for(int row = 0; row < k; row++) {

        for(int col = 0; col < k; col++) {
            std::cout << '*';
        }

        for(int col = 0; col < k; col++) {
            std::cout << 'x';
        }

        for(int col = 0; col < k; col++) {
            std::cout << '*';
        }

        std::cout << std::endl;

    }

    for(int row = 0; row < k; row++) {

        for(int col = 0; col < k; col++) {
            std::cout << ' ';
        }

        for(int col = 0; col < k; col++) {
            std::cout << 'x';
        }

        for(int col = 0; col < k; col++) {
            std::cout << 'x';
        }

        std::cout << std::endl;

    }

    for(int row = 0; row < k; row++) {

        for(int col = 0; col < k; col++) {
            std::cout << '*';
        }

        for(int col = 0; col < k; col++) {
            std::cout << ' ';
        }

        for(int col = 0; col < k; col++) {
            std::cout << '*';
        }

        std::cout << std::endl;

    }

    return 0;
}