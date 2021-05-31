#include <iostream>
#include <string>

int main() {

    int n;
    std::cin >> n;

    std::string flat = " * * *";
    std::string left = "*\n*\n*";
    std::string right = "      *\n      *\n      *";
    std::string both = "*     *\n*     *\n*     *";

    switch(n) {
        case 0:
            std::cout << flat << std::endl;
            std::cout << both << std::endl;
            std::cout << std::endl;
            std::cout << both << std::endl;
            std::cout << flat << std::endl;
            break;
        case 1:
            std::cout << std::endl;
            std::cout << right << std::endl;
            std::cout << std::endl;
            std::cout << right << std::endl;
            std::cout << std::endl;
            break;
        case 2:
            std::cout << flat << std::endl;
            std::cout << right << std::endl;
            std::cout << flat << std::endl;
            std::cout << left << std::endl;
            std::cout << flat << std::endl;
            break;
        case 3:
            std::cout << flat << std::endl;
            std::cout << right << std::endl;
            std::cout << flat << std::endl;
            std::cout << right << std::endl;
            std::cout << flat << std::endl;
            break;
        case 4:
            std::cout << std::endl;
            std::cout << both << std::endl;
            std::cout << flat << std::endl;
            std::cout << right << std::endl;
            std::cout << std::endl;
            break;
        case 5:
            std::cout << flat << std::endl;
            std::cout << left << std::endl;
            std::cout << flat << std::endl;
            std::cout << right << std::endl;
            std::cout << flat << std::endl;
            break;
        case 6:
            std::cout << flat << std::endl;
            std::cout << left << std::endl;
            std::cout << flat << std::endl;
            std::cout << both << std::endl;
            std::cout << flat << std::endl;
            break;
        case 7:
            std::cout << flat << std::endl;
            std::cout << right << std::endl;
            std::cout << std::endl;
            std::cout << right << std::endl;
            std::cout << std::endl;
            break;
        case 8:
            std::cout << flat << std::endl;
            std::cout << both << std::endl;
            std::cout << flat << std::endl;
            std::cout << both << std::endl;
            std::cout << flat << std::endl;
            break;
        case 9:
            std::cout << flat << std::endl;
            std::cout << both << std::endl;
            std::cout << flat << std::endl;
            std::cout << right << std::endl;
            std::cout << flat << std::endl;
            break;
    }

    return 0;
}