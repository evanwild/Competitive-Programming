#include <iostream>

int main() {

    int l;
    std::cin >> l;

    while(l--) {

        int n;
        std::cin >> n;

        char x;
        std::cin >> x;

        while(n--) {
            std::cout << x;
        }

        std::cout << std::endl;

    }

    return 0;
}