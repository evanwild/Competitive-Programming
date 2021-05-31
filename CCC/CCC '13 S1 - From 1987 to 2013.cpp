#include <iostream>
#include <string>

bool is_distinct(std::string year) {

    for(std::size_t i = 0; i < year.size(); i++) {
        if(year.find(year.at(i)) != i) {
            return false;
        }
    }

    return true;
}

int main() {

    int y;
    std::cin >> y;

    while(true) {
        if(is_distinct(std::to_string(++y))) {
            break;
        }
    }

    std::cout << y << std::endl;

    return 0;
}