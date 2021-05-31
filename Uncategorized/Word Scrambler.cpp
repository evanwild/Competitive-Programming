#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void scramble_words(string s, string output) {
    if(!s.length()) {
        cout << output << endl;
        return;
    }
    for(int i = 0; i < s.length(); i++) {
        string s_copy = s;
        s_copy.erase(i, 1);
        scramble_words(s_copy, output+s.at(i));
    }
}

int main() {

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    scramble_words(s, "");

    return 0;
}