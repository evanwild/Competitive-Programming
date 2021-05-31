#include <iostream>

bool is_correct(int** grid, int size) {

    for(int col = 0; col < size-1; col++) {
        if(grid[0][col] >= grid[0][col+1]) {
            return false;
        }
    }
    for(int row = 0; row < size-1; row++) {
        if(grid[row][0] >= grid[row+1][0]) {
            return false;
        }
    }
    return true;
}

void rotate_90(int** grid, int size) {

    int** new_grid = new int*[size];
    for(int i = 0; i < size; i++) {
        new_grid[i] = new int[size];
    }

    int place_row = 0;
    int place_col = 0;

    for(int col = 0; col < size; col++) {
        for(int row = size-1; row >= 0; row--) {
            new_grid[place_row][place_col] = grid[row][col];
            place_col++;
            if(place_col == size) {
                place_col = 0;
                place_row++;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }

    for(int i = 0; i < size; i++) {
        delete[] new_grid[i];
    }

    delete[] new_grid;

}

int main() {

    int n;
    std::cin >> n;

    int** grid = new int*[n];
    for(int i = 0; i < n; i++) {
        grid[i] = new int[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    while(!is_correct(grid, n)) {
        rotate_90(grid, n);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < n; i++) {
        delete[] grid[i];
    }

    delete[] grid;

    return 0;
}