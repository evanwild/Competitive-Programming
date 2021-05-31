#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
public:
    vector<int> d;
    bool sign;

    BigInteger() {
        d.clear();
        sign = true;
    }

    BigInteger(string& s) {
        d.clear();
        sign = true;
        if(s.front() == '-') {
            sign = false;
            s.erase(0, 1);
        }
        for(int i = s.size()-1; i >= 0; i--) {
            d.push_back(s[i]-'0');
        }
    }

    BigInteger complement(int size) {
        BigInteger result;
        for(int i = 0; i < d.size(); i++) {
            result.d.push_back(9-d[i]);
        }
        int gap_to_fill = size - d.size();
        while(gap_to_fill > 0) {
            result.d.push_back(9);
            gap_to_fill--;
        }
        result.d[0]++;
        return result;
    }

    void print() {
        if(!sign) {
            cout << "-";
        }
        for(int i = d.size()-1; i >= 0; i--) {
            printf("%d", d[i]);
        }
        cout << endl;
    }

    void add(BigInteger& other) {
        if(other.d.size() > d.size()) {
            swap(*this, other);
        }
        for(int i = 0; i < other.d.size(); i++) {
            d[i] += other.d[i];
            int j = i;
            while(d[j] >= 10) {
                d[j] -= 10;
                if(j < d.size()-1) {
                    d[j+1]++;
                }else {
                    d.push_back(1);
                    break;
                }
                j++;
            }
        }
    }

    void subtract(BigInteger& other) {
        other = other.complement(d.size());
        this->add(other);
        d.pop_back();
        this->cut_zeroes();
    }

    void cut_zeroes() {
        while(d.back() == 0 && d.size() > 1) {
            d.pop_back();
        }
    }

    bool abs_greater_than(const BigInteger& other) {
        if(d.size() > other.d.size()) {
            return true;
        }
        if(other.d.size() > d.size()) {
            return false;
        }
        for(int i = d.size()-1; i >= 0; i--) {
            if(d[i] > other.d[i]) {
                return true;
            }else if(other.d[i] > d[i]) {
                return false;
            }
        }
        return false;
    }
};

int main() {

    int n;
    cin >> n;

    string s, s2;
    while(n--) {
        cin >> s >> s2;
        BigInteger b(s);
        BigInteger b2(s2);

        if(b.sign == b2.sign) {
            b.add(b2);
        }else {
            if(!b.sign && b2.sign) {
                swap(b, b2);
            }
            if(b2.abs_greater_than(b)) {
                swap(b, b2);
                b.sign = true;
                b2.sign = false;
                b.subtract(b2);
                b.sign = false;
            }else {
                b.subtract(b2);
            }
        }

        b.print();
    }

    return 0;
}