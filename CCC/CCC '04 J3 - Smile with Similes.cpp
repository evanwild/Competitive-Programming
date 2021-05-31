#include <iostream>
#include <string>

int main() {

    int n;
    int m;

    std::cin >> n >> m;

    std::string adjectives[5];
    std::string nouns[5];

    for(int i = 0; i < n; i++) {
        std::cin >> adjectives[i];
    }

    for(int i = 0; i < m; i++) {
        std::cin >> nouns[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << adjectives[i] << " as " << nouns[j] << std::endl;
        }
    }

    return 0;
}