#include <iostream>
#include <algorithm>

using namespace std;

int nums[30000];

int main() {
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums+n);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] != nums[i+1]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}