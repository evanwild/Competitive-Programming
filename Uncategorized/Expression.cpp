#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int N;
string s, z;

bool op(char c) {
    return (c=='+' || c=='-' || c == '*' || c=='/');
}

int close(int l) {
    int open = 0, i;
    for(i = l; i < N; i++) {
        if(s[i] == '(')
            open++;
        else if(s[i] == ')')
            open--;
        if(!open)
            break;
    }
    return i;
}

int solve(int l, int r) {
    vector<int> vals;
    vector<char> ops;
    for(int i = l; i <= r; i++) {

        char c = s[i];
        char p = s[i-1];
        char p2 = s[i-2];

        if(isdigit(c)) {
            if(isdigit(p)) {
                vals.back() *= 10;
                vals.back() += (vals.back() < 0 ? -(c-'0') : c-'0');
            }else if( (i == l+1 && p == '-') || (p == '-' && op(p2))) {
                vals.PB(-(c-'0'));
            }else {
                vals.PB(c-'0');
            }
        }else if(op(c)) {
            if((i == l && c == '-') || (c == '-' && op(p)))
                continue;
            ops.PB(c);
        }else {
            int cl = close(i);
            vals.PB(solve(i+1, cl-1));
            i = cl;
        }
    }

    int ans = 0;

    ops.PB('+');
    int last_val = vals[0];
    char last_op = '+';

    for(int i = 0; i < ops.size(); i++) {
        if(ops[i] == '*') {
            last_val *= vals[i+1];
        }else if(ops[i] == '/') {
            last_val /= vals[i+1];
        }else {
            ans += (last_op == '+' ? last_val : -last_val);
            last_val = vals[i+1];
            last_op = ops[i];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> z;

    for(int i = 0; i < z.size(); i++) {
        if(i < z.size()-1 && z[i] == '-' && z[i+1] == '(')
            s += "-1*(", i++;
        else
            s += z[i];
    }

    N = s.size();
    cout << solve(0, N-1) << '\n';
}