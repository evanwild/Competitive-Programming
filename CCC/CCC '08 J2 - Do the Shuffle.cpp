#include <iostream>

int main() {
    
    char playlist[] = {'A', 'B', 'C', 'D', 'E'};
    
    while(true) {
     
        int b;
        int n;
        
        std::cin >> b >> n;
        
        if(b == 4 && n == 1) {
            break;    
        }
        
        while(n--) {
            
            if(b == 1) {
                for(int i = 0; i < 4; i++) {
                    int temp = playlist[i];
                    playlist[i] = playlist[i+1];
                    playlist[i+1] = temp;
                }
            }else if(b == 2) {
                for(int i = 4; i > 0; i--) {
                    int temp = playlist[i];
                    playlist[i] = playlist[i-1];
                    playlist[i-1] = temp;
                }
            }else if(b == 3) {
                 int temp = playlist[0];
                 playlist[0] = playlist[1];
                 playlist[1] = temp;
            }
        }    
    }
    
    for(int i = 0; i < 5; i++) {
        std::cout << playlist[i] << " ";    
    }
    
    return 0;
}