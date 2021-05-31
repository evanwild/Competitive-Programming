#include <iostream>

int main() {

    int burgers[4] = {461, 431, 420, 0};
    int sides[4] = {100, 57, 70, 0};
    int drinks[4] = {130, 160, 118, 0};
    int desserts[4] = {167, 266, 75, 0};

    int burger, side, drink, dessert;
    std::cin >> burger >> side >> drink >> dessert;

    int total = burgers[burger-1] + sides[side-1] + drinks[drink-1] + desserts[dessert-1];

    std::cout << "Your total Calorie count is " << total << "." << std::endl;

    return 0;
}