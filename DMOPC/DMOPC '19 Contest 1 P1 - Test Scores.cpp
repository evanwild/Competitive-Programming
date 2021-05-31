#include <iostream>
#include <math.h>

int main() {

  int N;
  std::cin >> N;

  while(N--) {

    long long n, a, b, t;
    std::cin >> n >> a >> b >> t;

    long long max_score = n * a;
    if(max_score < t) {
      std::cout << -1 << "\n";
      continue;
    }

    int correct = ceil((t + (b*n)) / (a+b))+1;

    std::cout << correct << std::endl;

  }

  return 0;
}