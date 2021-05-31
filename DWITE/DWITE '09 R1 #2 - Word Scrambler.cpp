#include <iostream>
#include <string>

using namespace std;

void print_combos(string s, string prefix) {
    if(s.length() == 1) {
        prefix=prefix+s;
        cout<<prefix<<endl;
    }else {
        for(int i = 0; i < s.length(); i++) {
            string s_copy = s;
            string prefix_copy=prefix;
            prefix_copy=prefix_copy+s_copy.at(i);
            s_copy.erase(i, 1);
            print_combos(s_copy,prefix_copy);
        }
    }
}

int main() {

    int n = 5;
    string s;
    while(n--) {
        cin >> s;
        string prefix("");
        print_combos(s,prefix);
    }

    return 0;
}