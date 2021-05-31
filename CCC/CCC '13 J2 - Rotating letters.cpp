#include <iostream>
#include <string>

int main() {

    std::string input;
    std::cin >> input;

    std::string allowed = "IOSHZXN";

    std::string answer = "YES";

    for(size_t i = 0; i < input.size(); i++) {
        if(allowed.find(input.at(i)) == std::string::npos) {
            answer = "NO";
            break;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}