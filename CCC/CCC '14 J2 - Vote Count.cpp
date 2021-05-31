#include <iostream>

int main() {

    int v;
    std::cin >> v;

    int a_votes = 0;
    int b_votes = 0;

    for(int i = 0; i < v; i++) {
        char input;
        std::cin >> input;

        if(input == 'A') {
            a_votes++;
        }else {
            b_votes++;
        }

    }

    if(a_votes > b_votes) {
        std::cout << "A" << std::endl;
    }else if(b_votes > a_votes) {
        std::cout << "B" << std::endl;
    }else {
        std::cout << "Tie" << std::endl;
    }

    return 0;
}