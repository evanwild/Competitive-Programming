#include <bits/stdc++.h>

using namespace std;

int main() {

    int guess = 1;
    string line;

    while(true) {
        cout << guess << endl;
        cin >> line;

        if(line == "DONE")
            break;

        if(line == "YES")
            guess = 1;
        else
            guess++;
    }
}