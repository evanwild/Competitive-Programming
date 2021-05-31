#include <iostream>
#include <string>

char shift(char c, int s) {
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::size_t pos = alphabet.find(c);

  while(s--) {
    if(pos == 25) {
      pos = 0;
    }else {
      pos++;
    }
  }

  return alphabet.at(pos);
}

int main() {

  std::string key;
  std::cin >> key;

  std::cin.ignore();

  std::string input;
  getline(std::cin, input);

  std::string removed;

  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(std::size_t i = 0; i < input.size(); i++) {
    if(alphabet.find(input.at(i)) != std::string::npos) {
      removed += input.at(i);
    }
  }

  std::size_t current_key_pos = 0;

  for(std::size_t i = 0; i < removed.size(); i++) {

    removed.at(i) = shift(removed.at(i), alphabet.find(key.at(current_key_pos)));
    current_key_pos++;

    if(current_key_pos == key.size()) {
      current_key_pos = 0;
    }

  }

  std::cout << removed << std::endl;

  return 0;
}