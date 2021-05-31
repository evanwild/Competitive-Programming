#include <bits/stdc++.h>
using namespace std;
int main() {
string s;
cin >> s;
unordered_map<char, int> freq;
for(char c : s) ++freq[c];
long long ans = 1;
for(auto f : freq) ans = ans * (f.second+1), ans %= 1000000007;
cout<<ans<<'\n';
}