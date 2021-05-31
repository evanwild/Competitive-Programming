#include <bits/stdc++.h>

using namespace std;

int N, A[5005];
unordered_map<int, bool> exists;
unordered_set<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
        exists[A[i]] = 1;
    }

    sort(A, A+N);
    
    for(int i = 0; i < N; ++i)
        for(int j = i+1; j < N; ++j)
            if(exists.count(A[i] + A[j]))
                ans.insert(A[i]*961 + A[j]*31 + A[i]+A[j]);
            
    if(ans.size() > 0)
        cout << ans.size() << '\n';
    else
        cout << -1 << '\n';
}