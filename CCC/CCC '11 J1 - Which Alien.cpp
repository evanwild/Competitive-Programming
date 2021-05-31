#include <iostream>

int main() {

    int antenna;
    int eyes;

    std::cin >> antenna >> eyes;

    if(antenna >= 3 && eyes <= 4) {
        std::cout << "TroyMartian" << std::endl;
    }

    if(antenna <= 6 && eyes >= 2) {
        std::cout << "VladSaturnian" << std::endl;
    }

    if(antenna <= 2 && eyes <= 3) {
        std::cout << "GraemeMercurian" << std::endl;
    }

    return 0;
}