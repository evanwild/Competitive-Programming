#include <iostream>

int main() {
  
    int m;
    int n;
    
    std::cin >> m >> n;
    
    int ways = 0;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(i + j == 10) {
                ways++;    
            }
        }
    }
    
    if(ways == 1) {
        std::cout << "There is 1 way to get the sum 10." << std::endl;
    }else {
        std::cout << "There are " << ways << " ways to get the sum 10." << std::endl;
    }
    
  
    return 0;
}