#include <iostream>
#include <string>
#include <deque>

using namespace std;

int location(deque<string> d, string s) {
  for(int i = 0; i < d.size(); i++) {
    if(d.at(i) == s) {
      return i;
    }
  }
  return -1;
}

int main() {

  int n;
  cin >> n;
  cin.ignore();
  
  while(n--) {

    string question;
    getline(cin, question);

    deque<string> equation;
    while(true) {
        size_t space_loc = question.find(' ');
        if(space_loc == string::npos) {
          equation.push_back(question);
          break;
        }
        equation.push_back(question.substr(0, space_loc));
        question = question.substr(space_loc+1, question.length()-space_loc-1);
    }

    while(true) {
      int times_loc = location(equation, "X");
      int plus_loc = location(equation, "+");
      int minus_loc = location(equation, "-");

      if(times_loc != -1) {
        string in_parens = "(" + equation.at(times_loc-1) + " X " + equation.at(times_loc+1) + ")";
        equation.erase(equation.begin()+times_loc-1,equation.begin()+times_loc+2);
        equation.insert(equation.begin()+times_loc-1, in_parens);
      }else {

        if(plus_loc != -1 && minus_loc != -1) {
           if(plus_loc < minus_loc) {
             string in_parens = "(" + equation.at(plus_loc-1) + " + " + equation.at(plus_loc+1) + ")";
             equation.erase(equation.begin()+plus_loc-1,equation.begin()+plus_loc+2);
             equation.insert(equation.begin()+plus_loc-1, in_parens);
           }else {
             string in_parens = "(" + equation.at(minus_loc-1) + " - " + equation.at(minus_loc+1) + ")";
             equation.erase(equation.begin()+minus_loc-1,equation.begin()+minus_loc+2);
             equation.insert(equation.begin()+minus_loc-1, in_parens);
           }
        }else {
          if(plus_loc != -1) {
            string in_parens = "(" + equation.at(plus_loc-1) + " + " + equation.at(plus_loc+1) + ")";
            equation.erase(equation.begin()+plus_loc-1,equation.begin()+plus_loc+2);
            equation.insert(equation.begin()+plus_loc-1, in_parens);
          }else if(minus_loc != -1) {
            string in_parens = "(" + equation.at(minus_loc-1) + " - " + equation.at(minus_loc+1) + ")";
            equation.erase(equation.begin()+minus_loc-1,equation.begin()+minus_loc+2);
            equation.insert(equation.begin()+minus_loc-1, in_parens);
          }else {
            break;
          }
        }

      }

    }
    equation.at(0).erase(0,1);
    equation.at(equation.size()-1).pop_back();
    for (size_t i = 0; i < equation.size(); i++) {
      cout << equation.at(i) << " ";
    }
    cout << endl;

  }

  return 0;
}