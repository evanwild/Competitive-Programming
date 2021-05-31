#include <iostream>
#include <string>

int main() {

    std::string input;

    while(true) {

        std::cin >> input;

        if(input == "quit!") {
            break;
        }

        std::string vowels = "aeiouy";
        if(input.size() > 4 && input.at(input.size() - 1) == 'r' && input.at(input.size() - 2) == 'o' && vowels.find(input.at(input.size() - 3)) == std::string::npos) {
            input.insert(input.size() - 1 , "u");
        }

        std::cout << input << std::endl;

    }

    return 0;
}