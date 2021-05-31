#include <iostream>

int main() {

    int quarters;
    int a;
    int b;
    int c;

    std::cin >> quarters >> a >> b >> c;

    int plays = 0;

    while(true) {

        if(quarters > 0) {
            quarters--;
            plays++;
            a++;
            if(a == 35) {
                quarters += 30;
                a = 0;
            }
        }else {
            break;
        }

        if(quarters > 0) {
            quarters--;
            plays++;
            b++;
            if(b == 100) {
                quarters += 60;
                b = 0;
            }
        }else {
            break;
        }

        if(quarters > 0) {
            quarters--;
            plays++;
            c++;
            if(c == 10) {
                quarters += 9;
                c = 0;
            }
        }else {
            break;
        }

    }

    std::cout << "Martha plays " << plays << " times before going broke." << std::endl;

    return 0;
}