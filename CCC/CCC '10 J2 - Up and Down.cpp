#include <iostream>

int main() {
    
    int a;
    int b;
    int c;
    int d;
    int s;
    
    std::cin >> a >> b >> c >> d >> s;
    
    int b_dist = 0;
    int n_dist = 0;
    
    int b_count = 0;
    int n_count = 0;
    
    bool b_back = false;
    bool n_back = false;
    
    while(s--) {
        
        if(b_back) {
            b_dist--;    
        }else {
            b_dist++;   
        }
        
        if(n_back) {
            n_dist--;
        }else {
            n_dist++;   
        }
        
        b_count++;
        n_count++;
        
        if((b_back == true && b_count == d) || (b_back == false && b_count == c)) {
            b_back = !b_back;
            b_count = 0;
        }
        
        if((n_back == true && n_count == b) || (n_back == false && n_count == a)) {
            n_back = !n_back;
            n_count = 0;
        }
         
    }
    
    if(b_dist > n_dist) {
        std::cout << "Byron" << std::endl;    
    }else if(n_dist > b_dist) {
        std::cout << "Nikky" << std::endl;
    }else {
        std::cout << "Tied" << std::endl;    
    }
    
    return 0;
}