#include <iostream>
#include <string>

bool same_key(char a, char b) {
    if((a == 'a' || a == 'b' || a == 'c') && (b == 'a' || b == 'b' || b == 'c')) {
        return true;
    }
    if((a == 'd' || a == 'e' || a == 'f') && (b == 'd' || b == 'e' || b == 'f')) {
        return true;
    }
    if((a == 'g' || a == 'h' || a == 'i') && (b == 'g' || b == 'h' || b == 'i')) {
        return true;
    }
    if((a == 'j' || a == 'k' || a == 'l') && (b == 'j' || b == 'k' || b == 'l')) {
        return true;
    }
    if((a == 'm' || a == 'n' || a == 'o') && (b == 'm' || b == 'n' || b == 'o')) {
        return true;
    }
    if((a == 'p' || a == 'q' || a == 'r' || a == 's') && (b == 'p' || b == 'q' || b == 'r' || b == 's')) {
        return true;
    }
    if((a == 't' || a == 'u' || a == 'v') && (b == 't' || b == 'u' || b == 'v')) {
        return true;
    }
    if((a == 'w' || a == 'x' || a == 'y' || a == 'z') && (b == 'w' || b == 'x' || b == 'y' || b == 'z')) {
        return true;
    }
    return false;
}

int main() {

    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    int seconds[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
                     1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};


    std::string input;

    while(true) {

        std::cin >> input;

        if(input == "halt") {
            break;
        }

        int s = 0;

        for(int i = 0; i < input.size(); i++) {
            int letter_loc = letters.find(input.at(i));
            s += seconds[letter_loc];
        }

        for(int i = 0; i < input.size() - 1; i++) {
            if(same_key(input.at(i), input.at(i+1))) {
                s += 2;
            }
        }

        std::cout << s << std::endl;

    }

    return 0;
}