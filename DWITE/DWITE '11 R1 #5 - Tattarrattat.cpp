#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dp;

int longest_palindrome(string s) {

    if(dp.count(s) > 0) return dp.at(s);

    int result = 0;

    if(s.size() == 1) result = 1;
    else if(s.size() == 2 && s.front() == s.back()) result = 2;
    else {
        if(s.front() == s.back()) {
            result = 2 + longest_palindrome(s.substr(1, s.length()-2));
        }else {
            result = max(longest_palindrome(s.substr(1, s.length()-1)), longest_palindrome(s.substr(0, s.length()-1)));
        }
    }
    dp.emplace(s, result);
    return result;
}

int main() {

    int test_cases = 5;
    while(test_cases--) {
        string s;
        cin >> s;
        cout << longest_palindrome(s) << endl;
    }

    return 0;
}