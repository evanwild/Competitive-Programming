#include <iostream>

int main() {

    int n;
    std::cin >> n;
    
    while(n--) {
     
        long long a, b;
        std::cin >> a >> b;
        
        long long p;
        std::cin >> p;
        
        if(a * b == p) {
            std::cout << "POSSIBLE DOUBLE SIGMA" << std::endl;
        }else {
            std::cout << "16 BIT S/W ONLY" << std::endl;
        }
        
    }

    return 0;
}