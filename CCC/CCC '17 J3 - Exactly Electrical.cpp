#include <iostream>

int main() {

  int start_x;
  int start_y;

  std::cin >> start_x >> start_y;

  int end_x;
  int end_y;

  std::cin >> end_x >> end_y;

  int charge;
  std::cin >> charge;

  int total_distance = 0;

  total_distance += start_x > end_x ? start_x - end_x : end_x - start_x;
  total_distance += start_y > end_y ? start_y - end_y : end_y - start_y;

  if(charge < total_distance) {
    std::cout << "N" << std::endl;
  }else {
    if(total_distance % 2 == charge % 2) {
      std::cout << "Y" << std::endl;
    }else {
      std::cout << "N" << std::endl;
    }
  }

  return 0;
}