#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int chair_x[100000], chair_y[100000];

int main() {

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) cin >> chair_x[i] >> chair_y[i];
  sort(chair_x, chair_x+n);
  sort(chair_y, chair_y+n);

  int target_x = chair_x[(n-1)/2], target_y = chair_y[(n-1)/2];
  long seconds = 0;
  for(int i = 0; i < n; i++) {
    seconds += abs(target_y-chair_y[i]) + abs(target_x-chair_x[i]);
  }
  
  cout << seconds << endl;

  return 0;
}