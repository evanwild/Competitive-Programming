#include <iostream>

int main() {

    int num = 91;

    int first;
    int second;
    int third;

    std::cin >> first >> second >> third;

    num += first + (second * 3) + third;

    std::cout << "The 1-3-sum is " << num << std::endl;

    return 0;
}