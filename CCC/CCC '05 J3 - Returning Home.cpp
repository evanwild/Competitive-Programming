#include <iostream>
#include <vector>
#include <string>

int main() {

  std::vector<char> turns;
  std::vector<std::string> streets;

  while(true) {
    char turn;
    std::cin >> turn;

    turns.push_back(turn);

    std::string street;
    std::cin >> street;

    if(street == "SCHOOL") {
      break;
    }else {
      streets.push_back(street);
    }
  }
  
  for(int i = turns.size() - 1; i > 0; i--) {
    if(turns.at(i) == 'R') {
      std::cout << "Turn LEFT onto " << streets.at(i-1) << " street." << std::endl;
    }else {
      std::cout << "Turn RIGHT onto " << streets.at(i-1) << " street." << std::endl;
    }
  }

  if(turns.at(0) == 'R') {
    std::cout << "Turn LEFT into your HOME." << std::endl;
  }else {
    std::cout << "Turn RIGHT into your HOME." << std::endl;
  }

  return 0;
}