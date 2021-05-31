#include <iostream>

int main() {

  int scorer;
  std::cin >> scorer;

  int possible_combos = 0;

  for(int first_touch = 1; first_touch < scorer; first_touch++) {
    for(int second_touch = first_touch+1; second_touch < scorer; second_touch++) {
      for(int third_touch = second_touch+1; third_touch < scorer; third_touch++) {
        possible_combos++;
      }
    }
  }

  std::cout << possible_combos << std::endl;

  return 0;
}