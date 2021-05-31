#include <iostream>
#include <string>

char closest_vowel(char c) {
    if(c == 'b' || c == 'c') {
        return 'a';
    }
    if(c == 'd' || c == 'f' || c == 'g') {
        return 'e';
    }
    if(c == 'h' || c == 'j' || c == 'k' || c == 'l') {
        return 'i';
    }
    if(c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r') {
        return 'o';
    }else {
        return 'u';
    }
}

char next_consonant(char c) {
    std::string consonants = "bcdfghjklmnpqrstvwxyzz";
    return consonants.at(consonants.find(c) + 1);
}

int main() {

    std::string input;
    std::cin >> input;

    std::string vowels = "aeiou";

    for(std::size_t i = 0; i < input.size(); i++) {
        std::cout << input.at(i);
        if(vowels.find(input.at(i)) == std::string::npos) {
            std::cout << closest_vowel(input.at(i));
            std::cout << next_consonant(input.at(i));
        }
    }

    return 0;
}