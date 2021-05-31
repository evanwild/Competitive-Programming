#include <iostream>

int main() {

    int n;
    int k;

    std::cin >> n >> k;

    int total = n;

    while(k--) {
        n *= 10;
        total += n;
    }

    std::cout << total << std::endl;

    return 0;
}