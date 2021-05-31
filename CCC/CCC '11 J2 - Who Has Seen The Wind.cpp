#include <iostream>
#include <math.h>

int main() {
    
    int h;
    int m;
    
    std::cin >> h >> m;
    
    int t = 1;
    
    for(t = 1; t <= m; t++) {
        int a = -6 * pow(t, 4.0) + h * pow(t, 3.0) + 2 * pow(t, 2.0) + t;         
        if(a <= 0) {
            std::cout << "The balloon first touches ground at hour: \n"<< t << std::endl;
            break;
        }
    }
    
    if(t > m) {
        std::cout << "The balloon does not touch ground in the given time." << std::endl;
    }
    
    return 0;
}