#include <iostream>
#include <string>

int main() {

  int n;
  std::cin >> n;

  while(std::to_string(++n).find('0') != std::string::npos);

  std::cout << n << std::endl;

  return 0;
}