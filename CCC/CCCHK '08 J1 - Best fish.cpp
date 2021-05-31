#include <iostream>

int main() {

  int c;
  std::cin >> c;

  int c_record = -1;
  for(int i = 0; i < c; i++) {
    int weight;
    std::cin >> weight;

    int length;
    std::cin >> length;

    if(weight * length > c_record) {
      c_record = weight * length;
    }
  }

  int n;
  std::cin >> n;

  int n_record = -1;
  for(int i = 0; i < n; i++) {
    int weight;
    std::cin >> weight;

    int length;
    std::cin >> length;

    if(weight * length > n_record) {
      n_record = weight * length;
    }
  }

  if(c_record > n_record) {
    std::cout << "Casper" << std::endl;
  }else if(n_record > c_record) {
    std::cout << "Natalie" << std::endl;
  }else {
    std::cout << "Tie" << std::endl;
  }

  return 0;
}