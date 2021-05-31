#include <iostream>
#include <string>

using namespace std;

bool is_monkey_word(string s) {
    bool ret_val = false;
  if(s == "A") {
    return true;
  }
  if(s.length() <= 2) {
    return false;
  }
  if(s.at(0) == 'B' && s.back() == 'S') {
     if(!ret_val)
        ret_val = is_monkey_word(s.substr(1, s.length()-2));
  }
  for(size_t i = 0; i < s.length(); i++) {
    if(s.at(i) == 'N') {
        string first_half = s.substr(0, i);
        string second_half = s.substr(i+1, s.length()-i);
        if(is_monkey_word(first_half) && is_monkey_word(second_half)) {
            ret_val = true;    
        }
    }
  }
  return ret_val;
}

int main() {

  string s;

  while(true) {
    cin >> s;
    
    if(s == "X")
        break;
    
    if(is_monkey_word(s)) {
      cout << "YES" << endl;
    }else {
      cout << "NO" << endl;
    }

  }

  return 0;
}