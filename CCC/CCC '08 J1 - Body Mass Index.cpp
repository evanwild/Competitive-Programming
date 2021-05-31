#include <iostream>

int main() {

    float weight;
    float height;

    std::cin >> weight >> height;

    float bmi = weight / (height * height);

    if(bmi > 25) {
        std::cout << "Overweight" << std::endl;
    }else if(bmi < 18.5) {
        std::cout << "Underweight" << std::endl;
    }else {
        std::cout << "Normal weight" << std::endl;
    }

    return 0;
}