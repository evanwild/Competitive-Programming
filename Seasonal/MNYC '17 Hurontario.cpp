#include <bits/stdc++.h>
using namespace std;
#define LL long long

string A, B;
LL Ahsh=0, Bhsh=0, ppow[1000000] = {1};

const LL p = 53;
const LL m = 10e9 + 9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for(int i = 1; i < 1000000; i++)
        ppow[i] = (p * ppow[i-1]) % m;

    cin >> A >> B;

    int i = A.size()-1, j = 0, ans=-1;

    while(1) {

        if(i < 0 || j >= B.size())
            break;

        Ahsh = (Ahsh * p + (A[i] - 'A' + 1)) % m;
        Bhsh = (Bhsh + (B[j] - 'A' + 1) * ppow[j]) % m;

        if(Ahsh == Bhsh)
            ans = j;
            
        i--;
        j++;
    }
    ans++;

    for(int i = 0; i < A.size()-ans; i++)
        cout << A[i];
    cout << B;
}