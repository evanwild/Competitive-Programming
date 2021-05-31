#include <bits/stdc++.h>
using namespace std;

int N;
int nums[3005];

bool f(int l, int r, int x)
{
  if(r >= l)
  {
    int m = l + (r - l) / 2;
    if (nums[m] == x)
      return true;
    if (nums[m] > x)
      return f(l, m - 1, x);
    return f(m + 1, r, x);
  }
  return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> N;
    
    for (int i = 0; i < N; i++)
      cin >> nums[i];

    sort(nums, nums + N);

    int ans = 0;

    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        if(f(j + 1, N - 1, 2 * nums[j] - nums[i]))
          ans = max(ans, 3 * nums[j]);

    cout << ans << "\n";

    return 0;
}