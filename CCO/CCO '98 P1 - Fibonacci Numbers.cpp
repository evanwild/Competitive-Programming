#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInteger {
public:
    vector<int> digits;

    BigInteger() {
        digits = vector<int>{};
    }
    
    BigInteger(vector<int> new_digits) {
        digits = new_digits;
    }

    void add(BigInteger other) {
        for(int i = 0; i < other.digits.size(); i++) {
            digits.at(i) += other.digits.at(i);
            if(digits.at(i) > 9) {
                int diff = digits.at(i) - 10;
                digits.at(i)-=10;
                if(i < digits.size()-1) {
                    digits.at(i+1)++;
                }else {
                    digits.push_back(1);
                }
            }
        }
    }

    void print() {
        for(int i = digits.size()-1; i >= 0; i--) {
            cout << digits.at(i);
        }
        cout << endl;
    }

};

bool dp[201] = {false};
BigInteger dp_val[201];

BigInteger fib(int n) {

    if(dp[n]) return dp_val[n];

    if(n == 1 || n == 2) {
        dp[n] = true;
        dp_val[n] = BigInteger(vector<int>{1});
        return BigInteger(vector<int>{1});
    }else {
        BigInteger first = fib(n-1);
        BigInteger second = fib(n-2);
        first.add(second);
        dp[n] = true;
        dp_val[n] = first;
        return first;
    }
}

int main() {

    int n;
    while(true) {
        cin >> n;

        if(n == 0) {
            break;
        }

        fib(n).print();    
    }

    return 0;
}