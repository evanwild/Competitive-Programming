#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll p[100005], d[100005];
ll savings[100005];

int main()
{
    
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> p[i] >> d[i];
        savings[i] = p[i] - d[i];
        ans += p[i];
    }

    sort(savings, savings+n, greater<ll>());

    for(int i = 0; i < k; i++) {
        ans -= savings[i];
    }

    cout << ans << endl;

    return 0;
}