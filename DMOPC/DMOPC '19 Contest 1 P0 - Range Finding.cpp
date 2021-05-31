#include <iostream>

int main() {

  int n;
  std::cin >> n;

  long long max = -1000000001;
  long long min = 1000000001;

  while(n--) {
    long long a;
    std::cin >> a;
    if(a > max) {
      max = a;
    }
    if(a < min) {
      min = a;
    }
  }

  std::cout << max - min << std::endl;

  return 0;
}