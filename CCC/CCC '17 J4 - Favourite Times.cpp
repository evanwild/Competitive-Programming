#include <iostream>

int main() {

    int d;
    std::cin >> d;

    int hours = 12;
    int minutes = 0;

    int total = 0;

    while(d >= 720) {
        total += 31;
        d -= 720;
    }

    for(int i = 0; i < d; i++) {
        minutes++;

        if(minutes == 60) {
            minutes = 0;
            hours++;
        }

        if(hours == 13) {
            hours = 1;
        }

        int time = (hours * 100) + minutes;
        if(time > 999) {
            int a = time % 10;
            int b = (time / 10) % 10;
            int c = (time / 100) % 10;
            int d = (time / 1000) % 10;
            if(d-c == c-b && c-b == b-a) {
                total++;
            }
        }else {
            int a = time % 10;
            int b = (time / 10) % 10;
            int c = (time / 100) % 10;
            if(c-b == b-a) {
                total++;
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}