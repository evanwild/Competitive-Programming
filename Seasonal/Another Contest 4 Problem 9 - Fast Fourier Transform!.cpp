#include <bits/stdc++.h>
using namespace std;

vector<int> f(int n) {

  vector<int> answer;

  // 1!
  answer.push_back(1);
  
  for(int i = 2; i <= n; i++)
    answer.push_back( (answer[i - 1] * i) % 998244353);

  return answer;
}