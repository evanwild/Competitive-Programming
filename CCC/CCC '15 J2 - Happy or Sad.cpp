#include <iostream>
#include <string>

int main() {

    std::string input;
    getline(std::cin, input);

    int happy = 0;
    int sad = 0;

    while(input.find(":-)") != std::string::npos || input.find(":-(") != std::string::npos) {
        if(input.find(":-)") != std::string::npos) {
            input.erase(input.find(":-)"), 3);
            happy++;
        }
        if(input.find(":-(") != std::string::npos) {
            input.erase(input.find(":-("), 3);
            sad++;
        }
    }

    if(happy == 0 && sad == 0) {
        std::cout << "none" << std::endl;
    }else if(happy == sad) {
        std::cout << "unsure" << std::endl;
    }else if(happy > sad) {
        std::cout << "happy" << std::endl;
    }else {
        std::cout << "sad" << std::endl;
    }

    return 0;
}