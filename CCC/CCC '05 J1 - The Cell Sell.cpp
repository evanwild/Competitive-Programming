#include <iostream>

int main() {

    int daytime;
    int evening;
    int weekend;

    std::cin >> daytime >> evening >> weekend;

    float a_cost = 0;
    float b_cost = 0;

    if(daytime >= 100) {
        a_cost += (daytime - 100) * 0.25;
    }
    a_cost += evening * 0.15;
    a_cost += weekend * 0.20;

    if(daytime >= 250) {
        b_cost += (daytime - 250) * 0.45;
    }

    b_cost += evening * 0.35;
    b_cost += weekend * 0.25;

    std::cout << "Plan A costs " << a_cost << std::endl;
    std::cout << "Plan B costs " << b_cost << std::endl;

    if(a_cost < b_cost) {
        std::cout << "Plan A is cheapest." << std::endl;
    }else if(b_cost < a_cost) {
        std::cout << "Plan B is cheapest." << std::endl;
    }else {
        std::cout << "Plan A and B are the same price." << std::endl;
    }

    return 0;
}