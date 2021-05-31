#include <iostream>
#include <string>

int main() {

  int n;
  std::cin >> n;

  std::string options[100];

  for(int i = 0; i < n; i++) {
    std::cin >> options[i];
  }

  std::string original_word;
  std::cin >> original_word;

  for(int i = 0; i < n; i++) {
    for(int j = 1; j < n; j++) {
      if(options[j].length() < options[j-1].length()) {
        std::string temp = options[j];
        options[j] = options[j-1];
        options[j-1] = temp;
      }
    }
  }

  for(int i = n-1; i >= 0; i--) {
    if(options[i].length() <= original_word.length()) {
      std::cout << options[i] << std::endl;
      break;
    }
  }

  return 0;
}