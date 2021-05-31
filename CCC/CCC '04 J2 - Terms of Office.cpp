#include <iostream>

int main() {

    int x, y;
    std::cin >> x >> y;

    for(int curr_year = x; curr_year <= y; curr_year++) {
        if((curr_year-x) % 2 == 0 && (curr_year-x) % 4 == 0 && (curr_year-x) % 3 == 0 && (curr_year-x) % 5 == 0) {
            std::cout << "All positions change in year " << curr_year << std::endl;
        }
    }

    return 0;
}