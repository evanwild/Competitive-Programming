#include <iostream>

int main() {

  int k;
  std::cin >> k;

  int* numbers = new int[k];

  for(int i = 0; i < k; i++) {
    std::cin >> numbers[i];
    if(numbers[i] == 0)
      numbers[i] = -1;
  }

  for(int i = k-1; i >= 0; i--) {
    if(numbers[i] == -1) {
      for(int j = i-1; j >= 0; j--) {
        if(numbers[j] != -1 && numbers[j] != 0) {
          numbers[j] = 0;
          break;
        }
      }
    }
  }

  int sum = 0;
  for(int i = 0; i < k; i++) {
    if(numbers[i] > 0) {
      sum += numbers[i];
    }
  }

  std::cout << sum << std::endl;

  delete [] numbers;

  return 0;
}