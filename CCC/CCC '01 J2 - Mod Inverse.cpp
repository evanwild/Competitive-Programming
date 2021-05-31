#include <iostream>

int main() {
  
    int x;
    int m;
    
    std::cin >> x >> m;
    
    int correct_n = -1;
        
    for(int n = 0; n < m; n++) {
        if((x * n) % m == 1) {
            correct_n = n;
            break;
        }
    }
    
    if(correct_n == -1) {
        std::cout << "No such integer exists." << std::endl;   
    }else {
        std::cout << correct_n << std::endl;   
    }
  
    return 0;
}