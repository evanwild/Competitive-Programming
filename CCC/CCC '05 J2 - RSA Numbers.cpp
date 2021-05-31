#include <iostream>

int main() {

    int min;
    int max;

    std::cin >> min >> max;

    int total = 0;

    for(int i = min; i <= max; i++) {

        int divisors = 2;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                divisors++;
            }
        }

        if(divisors == 4) {
            total++;
        }

    }

    std::cout << "The number of RSA numbers between " << min << " and " << max << " is " << total << std::endl;

    return 0;
}