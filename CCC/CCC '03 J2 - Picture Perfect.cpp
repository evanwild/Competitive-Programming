#include <iostream>

int main() {

    while(true) {
        int c;
        std::cin >> c;

        if(c == 0) {
            break;
        }

        int best_factor = 1;
        for(int i = 1; i <= c; i++) {
            if(c % i == 0) {
                int j = c / i;
                int perimeter = 2 * i + 2 * j;
                if(perimeter < (2 * best_factor + 2 * (c / best_factor))) {
                    best_factor = i;
                }
            }
        }

        std::cout << "Minimum perimeter is " << 2 * best_factor + 2 * (c / best_factor) << " with dimensions " << best_factor << " x " << c / best_factor << std::endl; 
    }

    return 0;
}