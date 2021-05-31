#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int N, L;

struct Light {
  int D, R, G;
} lights[101];

int time_until_green(int time, Light light) {
  int x = time % (light.R + light.G);
  return max(light.R - x, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> L;

  for(int i = 0; i < N; i++)
    cin >> lights[i].D >> lights[i].R >> lights[i].G;

  int idx, dist, time;
  idx = dist = time = 0;

  while(true) {
    if(dist == L) break;

    if(lights[idx].D == dist) {
      int wait = time_until_green(time, lights[idx]);
      time += wait;
      idx++;
      continue;
    }

    time++;
    dist++;
  }

  cout << time << endl;

  return 0;
}