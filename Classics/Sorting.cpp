#include <bits/stdc++.h>

using namespace std;

int n, nums[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    sort(nums, nums + n);

    for (int i = 0; i < n; ++i)
        cout << nums[i] << '\n';

    return 0;
}