#include <iostream>

int main() {

    int d[4];

    for(int i = 0; i < 4; i++) {
        std::cin >> d[i];
    }

    std::cout << 0 << " " << d[0] << " " << d[0]+d[1] << " " << d[0]+d[1]+d[2] << " " << d[0]+d[1]+d[2]+d[3] << std::endl;
    std::cout << d[0] << " " << 0 << " " << d[1] << " " << d[1]+d[2] << " " << d[1]+d[2]+d[3] << std::endl;
    std::cout << d[0]+d[1] << " " << d[1] << " " << 0 << " " << d[2] << " " << d[2]+d[3] << std::endl;
    std::cout << d[0]+d[1]+d[2] << " " << d[1]+d[2] << " " << d[2] << " " << 0 << " " << d[3] << std::endl;
    std::cout << d[0]+d[1]+d[2]+d[3] << " " << d[1]+d[2]+d[3] << " " << d[2]+d[3] << " " << d[3] << " " << 0 << std::endl;


    return 0;
}