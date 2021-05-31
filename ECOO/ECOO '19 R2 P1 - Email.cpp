#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctype.h> // For tolower()

void make_lowercase(std::string &str) {
  for(std::size_t i = 0; i < str.length(); i++) {
    str.at(i) = tolower(str.at(i));
  }
}

void remove_dots_before_at(std::string &str) {
  std::size_t at_loc = str.find('@');
  std::string only_before_at = str.substr(0, at_loc);

  while(only_before_at.find('.') != std::string::npos) {
    only_before_at.erase(only_before_at.find('.'), 1);
    str.erase(str.find('.'), 1);
  }
}

void remove_plus_to_at(std::string &str) {
  std::size_t at_loc = str.find('@');
  std::size_t plus_loc = str.find('+');

  if(plus_loc != std::string::npos) {
    str.erase(plus_loc, at_loc - plus_loc);
  }
}

int main() {

  int datasets = 10;

  while(datasets--) {

    int n;
    std::cin >> n;

    std::vector<std::string> emails;

    for(int i = 0; i < n; i++) {
      std::string email;
      std::cin >> email;
      make_lowercase(email);
      remove_dots_before_at(email);
      remove_plus_to_at(email);
      emails.push_back(email);
    }

    std::set<std::string> unique_emails (emails.begin(), emails.end());

    std::cout << unique_emails.size() << std::endl;

  }

  return 0;
}