#include <iostream>

int main() {

    int n;
    std::cin >> n;

    char first_day[100];
    char second_day[100];

    for(int i = 0; i < n; i++) {
        std::cin >> first_day[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> second_day[i];
    }

    int same = 0;

    for(int i = 0; i < n; i++) {
        if(first_day[i] == 'C' && second_day[i] == 'C') {
            same++;
        }
    }

    std::cout << same << std::endl;

    return 0;
}