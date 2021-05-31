#include <iostream>

int main() {

  int t;
  std::cin >> t;

  int c;
  std::cin >> c;

  int chores[100];
  for(int i = 0; i < c; i++) {
    std::cin >> chores[i];
  }

  int total = 0;
  for(int i = 0; i < c; i++) {

    int minimum_index = 0;
    for(int j = 0; j < c; j++) {
      if(chores[j] < chores[minimum_index]) {
        minimum_index = j;
      }
    }

    if(chores[minimum_index] == 100001) {
      break;
    }

    if(t - chores[minimum_index] < 0) {
      break;
    }

    total++;
    t -= chores[minimum_index];
    chores[minimum_index] = 100001;

  }

  std::cout << total << std::endl;

  return 0;
}