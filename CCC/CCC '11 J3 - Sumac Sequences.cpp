#include <iostream>

int main() {

    int t1;
    int t2;

    std::cin >> t1 >> t2;

    int length = 2;

    while(true) {

        if(t1 < t2) {
            break;
        }

        int next = t1 - t2;

        t1 = t2;
        t2 = next;

        length++;
    }

    std::cout << length << std::endl;

    return 0;
}