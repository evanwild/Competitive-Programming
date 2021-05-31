#include <iostream>
#include <string>

using namespace std;

string last_k = "";
int freq[123] = {0};

char most_frequent_char() {
  int max_index = 97;
  for(int i = 0; i < 123; i++) {
      if(freq[i] == freq[max_index] && i < max_index) {
          max_index = i;
      }else if(freq[i] > freq[max_index]) {
          max_index = i;
      }
  }
  return (char)max_index;
}

char shifted_char(char c1, char c2) {
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int res = (alphabet.find(c1)+alphabet.find(c2) + 1) % 26;
    return alphabet.at(res);
}

int main() {

    int k;
    cin >> k;

    string message;
    cin >> message;

    last_k = message.substr(0, k);
    cout << last_k;

    for(int i = 0; i < last_k.length(); i++) {
      freq[int(last_k.at(i))]++;
    }

    for(int i = k; i < message.length(); i++) {
        char shift_char = most_frequent_char();
        cout << shifted_char(message.at(i), shift_char);
        freq[int(last_k.at(0))]--;
        last_k = last_k.substr(1, last_k.length()-1);
        freq[int(message.at(i))]++;
        last_k += message.at(i);
    }

    return 0;
}