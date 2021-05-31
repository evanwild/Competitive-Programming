#include <iostream>
#include <cctype>
#include <string>

bool is_number(std::string s) {

  if(s.at(0) == '-') {
    return true;
  }

  for(char c : s) {
    if(!isdigit(c)) {
      return false;
    }
  }
  return true;
}

int main() {

  int a = 0;
  int b = 0;

  while(true) {

    int instruction;
    std::cin >> instruction;

    if(instruction == 7) {
      break;
    }

    char x;
    std::cin >> x;

    if(instruction == 1) {
      std::string y;
      std::cin >> y;

      if(is_number(y)) {
        if(x == 'A') {
          a = std::stoi(y);
        }else {
          b = std::stoi(y);
        }
      }else {
        if(y == "A") {
          if(x == 'A') {
            a = a;
          }else {
            b = a;
          }
        }else {
          if(x == 'A') {
            a = b;
          }else {
            b = b;
          }
        }
      }

    }else if(instruction == 2) {
      if(x == 'A') {
        std::cout << a << std::endl;
      }else {
        std::cout << b << std::endl;
      }

    }else if(instruction == 3) {
      std::string y;
      std::cin >> y;

      if(is_number(y)) {
        if(x == 'A') {
          a += std::stoi(y);
        }else {
          b += std::stoi(y);
        }
      }else {
        if(y == "A") {
          if(x == 'A') {
            a += a;
          }else {
            b += a;
          }
        }else {
          if(x == 'A') {
            a += b;
          }else {
            b += b;
          }
        }
      }

    }else if(instruction == 4) {
      std::string y;
      std::cin >> y;

      if(is_number(y)) {
        if(x == 'A') {
          a *= std::stoi(y);
        }else {
          b *= std::stoi(y);
        }
      }else {
        if(y == "A") {
          if(x == 'A') {
            a *= a;
          }else {
            b *= a;
          }
        }else {
          if(x == 'A') {
            a *= b;
          }else {
            b *= b;
          }
        }
      }

    }else if(instruction == 5) {
      std::string y;
      std::cin >> y;

      if(is_number(y)) {
        if(x == 'A') {
          a -= std::stoi(y);
        }else {
          b -= std::stoi(y);
        }
      }else {
        if(y == "A") {
          if(x == 'A') {
            a -= a;
          }else {
            b -= a;
          }
        }else {
          if(x == 'A') {
            a -= b;
          }else {
            b -= b;
          }
        }
      }

    }else if(instruction == 6) {
      std::string y;
      std::cin >> y;

      if(is_number(y)) {
        if(x == 'A') {
          a /= std::stoi(y);
        }else {
          b /= std::stoi(y);
        }
      }else {
        if(y == "A") {
          if(x == 'A') {
            a /= a;
          }else {
            b /= a;
          }
        }else {
          if(x == 'A') {
            a /= b;
          }else {
            b /= b;
          }
        }
      }

    }
  }

  return 0;
}