#include <iostream>

int main() {

    int w_count = 0;

    for(int i = 0; i < 6; i++) {
        char result;
        std::cin >> result;
        if(result == 'W') {
            w_count++;
        }
    }

    if(w_count >= 5) {
        std::cout << 1 << std::endl;
    }else if(w_count >= 3) {
        std::cout << 2 << std::endl;
    }else if(w_count >= 1) {
        std::cout << 3 << std::endl;
    }else {
        std::cout << -1 << std::endl;
    }

    return 0;
}