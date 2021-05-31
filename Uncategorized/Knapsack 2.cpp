#include <iostream>
#include <algorithm>

using namespace std;

int weight[101];
int value[101];

long long max_sum(int n, int w) {
  if(n == 0 || w == 0) return 0;
  if(weight[n] > w) return max_sum(n-1, w);
  return max(value[n]+max_sum(n-1, w-weight[n]), max_sum(n-1, w));
}

int main() {

  int n, w;
  cin >> n >> w;

  for(int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
  }

  cout << max_sum(n, w) << endl;

  return 0;
}