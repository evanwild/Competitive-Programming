#include <iostream>
#include <math.h>

int main() {

    int tiles;
    std::cin >> tiles;

    std::cout << "The largest square has side length " << floor(sqrt(tiles)) << "." << std::endl;

    return 0;
}