#include <bits/stdc++.h>

using namespace std;

int TC;
string S;
deque<int> num;

void subtract() {
    int x = num.back();
    num.pop_back();

    num.back() -= x;

    auto ptr = num.end() - 1;
    while(*ptr < 0) {
        *ptr += 10;
        ptr -= 1;
        *ptr -= 1;
    }

    while(num.front() == 0)
        num.pop_front();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> TC;
    while(TC--) {
        cin >> S;

        num.clear();
        for(char c : S)
            num.push_back(c-'0');

        while(1) {
            for(auto d : num)
                cout << d;
            cout << '\n';

            if(num.size() <= 2)
                break;

            subtract();
        }

        if(num.size() > 1 && num[0] == num[1])
            cout << "The number " << S << " is divisible by 11.\n";
        else
            cout << "The number " << S << " is not divisible by 11.\n";

        if(TC != 0)
            cout << '\n';
    }
}