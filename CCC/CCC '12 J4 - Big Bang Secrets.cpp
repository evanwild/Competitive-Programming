#include <iostream>
#include <string>

char shift(char c, int p, int k) {
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  std::size_t pos = alphabet.find(c);

  for(int i = 0; i < 3 * p + k; i++) {
    if(pos == 0) {
      pos = 25;
    }else {
      pos--;
    }
  }

  return alphabet.at(pos);
}

int main() {

  int k;
  std::cin >> k;

  std::string word;
  std::cin >> word;

  for(std::size_t i = 1; i <= word.size(); i++) {
    word.at(i-1) = shift(word.at(i-1), i, k);
  }

  std::cout << word << std::endl;

  return 0;
}