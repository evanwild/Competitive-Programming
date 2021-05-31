#include <iostream>
#include <string>

using namespace std;

int main() {

  while(true) {

    int n;
    cin >> n;

    if(n == 0) {
      break;
    }

    int *temps = new int[n];
    for(int i = 0; i < n; i++) {
      cin >> temps[i];
    }

    if(n == 1) {
      cout << 0 << endl;
      continue;
    }

    int *diffs = new int[n-1];
    for(int i = 0; i < n-1; i++) {
      diffs[i] = temps[i+1]-temps[i];
    }

    delete [] temps;

    string full_cycle = "";
    for(int i = 0; i < n-1; i++) {
      full_cycle += to_string(diffs[i]) + ",";
    }

    for(int length = 1; length < n; length++) {

      string substring = "";
      int substring_length = 0;
      for(int i = 0; i < length; i++) {
        substring += to_string(diffs[i]) + ",";
        substring_length++;
      }

      while(substring.length() < full_cycle.length()) {
        substring += substring;
      }
      substring = substring.substr(0, full_cycle.length());

      if(substring == full_cycle) {
        cout << substring_length << endl;
        break;
      }

    }

    delete [] diffs;

  }

  return 0;
}