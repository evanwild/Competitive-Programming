#include <iostream>
#include <string>

bool is_rotatable(std::string num) {

    std::string allowed = "01869";

    for(std::size_t i = 0; i < num.size(); i++) {
        if(allowed.find(num.at(i)) == std::string::npos) {
            return false;
        }
    }

    std::string reversed;
    for(int i = num.size() - 1; i >= 0; i--) {
        reversed += num.at(i);
    }

    for(std::size_t i = 0; i < reversed.size(); i++) {
        if(reversed.at(i) == '6') {
            reversed.at(i) = '9';
        }else if(reversed.at(i) == '9') {
            reversed.at(i) = '6';
        }
    }

    if(num == reversed) {
        return true;
    }else {
        return false;
    }
}

int main() {

    int m;
    int n;

    std::cin >> m >> n;

    int total = 0;

    for(int i = m; i <= n; i++) {
        if(is_rotatable(std::to_string(i))) {
            total++;
        }
    }

    std::cout << total << std::endl;

    return 0;
}