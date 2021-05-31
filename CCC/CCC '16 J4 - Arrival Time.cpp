#include <iostream>
#include <iomanip>

int main() {

    int hour;
    char colon;
    int minute;

    std::cin >> hour >> colon >> minute;

    double minutes_left = 120;

    while(minutes_left > 0) {
        if( (hour >= 7 && hour <= 9) || (hour >= 15 && hour <= 18) ) {
            minutes_left -= 0.5;
        }else {
            minutes_left--;
        }

        minute++;
        if(minute == 60) {
            hour++;
            minute = 0;
        }

        if(hour == 24) {
            hour = 0;
        }
    }

    std::cout << std::setfill('0') << std::setw(2) << hour;
    std::cout << ':';
    std::cout << std::setfill('0') << std::setw(2) << minute << std::endl;

    return 0;
}