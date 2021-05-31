#include <iostream>

int main() {

    int square[16];

    for(int i = 0; i < 16; i++) {
        std::cin >> square[i];
    }

    int row1 = square[0] + square[1] + square[2] + square[3];
    int row2 = square[4] + square[5] + square[6] + square[7];
    int row3 = square[8] + square[9] + square[10] + square[11];
    int row4 = square[12] + square[13] + square[14] + square[15];

    int col1 = square[0] + square[4] + square[8] + square[12];
    int col2 = square[1] + square[5] + square[9] + square[13];
    int col3 = square[2] + square[6] + square[10] + square[14];
    int col4 = square[3] + square[7] + square[11] + square[15];

    if(row1 == row2 && row2 == row3 && row3 == row4 && col1 == col2 && col2 == col3 && col3 == col4) {
        std::cout << "magic" << std::endl;
    }else {
        std::cout << "not magic" << std::endl;
    }

    return 0;
}