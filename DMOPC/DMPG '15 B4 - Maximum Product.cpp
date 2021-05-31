#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> positive;
  vector<int> zeros;
  vector<int> negative;

  for(int i = 0; i < n; i++) {
    int c;
    cin >> c;
    if(c > 0) {
      positive.push_back(c);
    }else if(c == 0) {
      zeros.push_back(c);
    }else {
      negative.push_back(c);
    }
  }

  if(negative.size() == 1 && positive.size() == 0 && zeros.size() > 0) {
    cout << 0 << endl;
  }else if(negative.size() == 1 && zeros.size() == 0 && positive.size() == 0) {
      cout << negative.front() << endl;
  }else {
  
    int ans;
    if(positive.size() == 0 and negative.size() == 0) {
      ans = 0;
    }else {
      ans = 1;
    }


    for(int i = 0; i < positive.size(); i++) {
      ans *= positive.at(i);       
    }

    if(negative.size() > 0) {
      if(negative.size() % 2 == 0) {
        for(int i = 0; i < negative.size(); i++) {
          ans *= negative.at(i);       
        }
      }else {
        negative.erase(max_element(negative.begin(), negative.end()));
        for(int i = 0; i < negative.size(); i++) {
          ans *= negative.at(i);       
        }
      }
    }

    if(ans < 0 && zeros.size() > 0) {
      ans = 0;
    }
    
    cout << ans << endl;
  }

  return 0;
}