#include <iostream>

int main() {

    int width;
    int height;

    std::cin >> width >> height;

    int x = 0;
    int y = 0;

    while(true) {

        int x_move;
        int y_move;

        std::cin >> x_move >> y_move;

        if(x_move == 0 && y_move == 0) {
            break;
        }

        x += x_move;
        y += y_move;

        if(x > width) {
            x = width;
        }else if(x < 0) {
            x = 0;
        }

        if(y > height) {
            y = height;
        }else if(y < 0) {
            y = 0;
        }

        std::cout << x << " " << y << std::endl;
    }

    return 0;
}