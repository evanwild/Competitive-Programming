#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;
  
  vector<int> streams;
  while(n--) {
    int input;
    cin >> input;
    streams.push_back(input);
  }
  
  while(true) {
    int type;
    cin >> type;
    
    if(type == 99) {
        // Split
        int split_num;
        int percentage;
        cin >> split_num >> percentage;
        streams.insert(streams.begin()+split_num-1, 0);
        int moved_amount = (percentage/100.0) * streams.at(split_num);
        streams.at(split_num-1) += moved_amount;
        streams.at(split_num) -= moved_amount;
    }else if(type == 88) {
        // Join
        int join_num;
        cin >> join_num;
        streams.at(join_num) += streams.at(join_num-1);
        streams.erase(streams.begin()+join_num-1);
    }else {
        // End
        break;
    }
  }
  
  for(size_t i = 0; i < streams.size(); i++) {
    cout << streams.at(i) << " ";    
  }
  cout << endl;

  return 0;
}