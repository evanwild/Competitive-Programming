#include <iostream>

int main() {

    int n;
    std::cin >> n;

    bool opened[10] = {false};
    int values[10] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};

    for(int i = 0; i < n; i++) {
        int open;
        std::cin >> open;

        opened[open - 1] = true;
    }

    int offer;
    std::cin >> offer;

    int average = 0;

    for(int i = 0; i < 10; i++) {
        if(!opened[i]) {
            average += values[i];
        }
    }

    average /= (10 - n);

    if(offer > average) {
        std::cout << "deal" << std::endl;
    }else {
        std::cout << "no deal" << std::endl;
    }


    return 0;
}