#include <iostream>
#include <string>

int main() {

  std::string first;
  getline(std::cin, first);

  std::string second;
  getline(std::cin, second);

  bool is_anagram = true;

  for(char c : first) {

      if(c == ' ') {
        continue;
      }

      std::size_t pos = second.find(c);

      if(pos != std::string::npos) {
        second.erase(pos, 1);
      }else {
        is_anagram = false;
        break;
      }

  }

  if(is_anagram) {
    std::cout << "Is an anagram." << std::endl;
  }else {
    std::cout << "Is not an anagram." << std::endl;
  }

  return 0;
}