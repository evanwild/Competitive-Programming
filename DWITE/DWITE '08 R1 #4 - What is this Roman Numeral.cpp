#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

unordered_map<char, int> values;

int roman_to_int(string &r) {
  int total = 0;
  for(char& c : r) total += values[c];
  for(int i = 0; i < r.length() - 1; i++)
    if(r.at(i) == 'I' && (r.at(i+1) == 'V' || r.at(i+1) == 'X'))
      total -= 2;
    else if(r.at(i) == 'X' && (r.at(i+1) == 'L' || r.at(i+1) == 'C'))
      total -= 20;
    else if(r.at(i) == 'C' && (r.at(i+1) == 'D' || r.at(i+1) == 'M'))
      total -= 200;
  return total;
}

int N = 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  values['I'] = 1;
  values['V'] = 5;
  values['X'] = 10;
  values['L'] = 50;
  values['C'] = 100;
  values['D'] = 500;
  values['M'] = 1000;
  
  while(N--) {
    string s;
    cin >> s;

    cout << roman_to_int(s) << endl;
  }

  return 0;
}