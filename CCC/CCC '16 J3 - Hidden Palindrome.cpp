#include <iostream>
#include <string>

bool is_palindrome(std::string word) {

    std::string reversed;

    for(int i = word.size() - 1; i >= 0; i--) {
        reversed += word.at(i);
    }

    if(word == reversed) {
        return true;
    }else {
        return false;
    }

}

int main() {

    std::string input;
    std::cin >> input;

    int largest = 1;

    for(int i = 0; i < input.size(); i++) {
        for(int j = i + 1; j < input.size(); j++) {

            std::string check = input.substr(i, j - i + 1);

            if(is_palindrome(check) && check.size() > largest) {
                largest = check.size();
            }

        }
    }

    std::cout << largest << std::endl;

    return 0;
}