#include <iostream>

int main() {

    int trout;
    int pike;
    int pickerel;
    int allowed;

    std::cin >> trout >> pike >> pickerel >> allowed;

    int total = 0;

    for(int i = 0; i <= allowed; i++) {
        for(int j = 0; j <= allowed; j++) {
            for(int k = 0; k <= allowed; k++) {
                if(i > 0 || j > 0 || k > 0) {
                    if(i * trout + j * pike + k * pickerel <= allowed) {
                        std::cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel" << std::endl;
                        total++;
                    }
                }
            }
        }
    }

    std::cout << "Number of ways to catch fish: " << total << std::endl;

    return 0;
}