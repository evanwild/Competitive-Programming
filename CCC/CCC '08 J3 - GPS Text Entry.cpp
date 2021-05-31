#include <iostream>
#include <string>

char grid[5][6] = {{'A', 'B', 'C', 'D', 'E', 'F'},
                   {'G', 'H', 'I', 'J', 'K', 'L'},
                   {'M', 'N', 'O', 'P', 'Q', 'R'},
                   {'S', 'T', 'U', 'V', 'W', 'X'},
                   {'Y', 'Z', ' ', '-', '.', '*'}};

int row_of_letter(char c) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 6; j++) {
      if(grid[i][j] == c) {
        return i;
      }
    }
  }
  return -1;
}

int col_of_letter(char c, int row) {
  for(int i = 0; i < 6; i++) {
    if(grid[row][i] == c) {
      return i;
    }
  }
  return -1;
}

int main() {

  std::string input;
  getline(std::cin, input);

  input += '*';

  char current_letter = 'A';
  int movements = 0;

  for(char c : input) {

    int current_row = row_of_letter(current_letter);
    int other_row = row_of_letter(c);

    movements += other_row > current_row ? other_row - current_row : current_row - other_row;

    int current_col = col_of_letter(current_letter, current_row);
    int other_col = col_of_letter(c, other_row);

    movements += other_col > current_col ? other_col - current_col : current_col - other_col;

    current_letter = c;

  }

  std::cout << movements << std::endl;

  return 0;
}