#include <iostream>

int main() {

    int bowls[3];

    for(int i = 0; i < 3; i++) {
        std::cin >> bowls[i];
    }

    if(bowls[0] > bowls[1]) {
        int temp = bowls[0];
        bowls[0] = bowls[1];
        bowls[1] = temp;
    }

    if(bowls[1] > bowls[2]) {
        int temp = bowls[1];
        bowls[1] = bowls[2];
        bowls[2] = temp;
    }

    if(bowls[0] > bowls[1]) {
        int temp = bowls[0];
        bowls[0] = bowls[1];
        bowls[1] = temp;
    }

    std::cout << bowls[1] << std::endl;

    return 0;
}