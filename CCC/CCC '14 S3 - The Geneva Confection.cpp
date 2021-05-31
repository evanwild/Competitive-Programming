#include <iostream>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--) {

	  int n;
	  cin >> n;
  
	  vector<int> top;
	  vector<int> branch;
  
	  for(int i = 0; i < n; i++) {
		int input;
		cin >> input;
		top.push_back(input);
	  }
  
	  int needed = 1;
  
	  while(top.size() > 0) {
    
		if(top.back() == needed) {
			// Car can slide to the lake directly.
			top.pop_back();
			needed++;
		}else if(branch.size() > 0 && branch.back() == needed) {
			// Car can go from branch to lake.
			branch.pop_back();
			needed++;
		}else {
			// Car goes from top to branch.
			int car = top.back();
			top.pop_back();
			branch.push_back(car);
			}
		}

		// Take the leftover cars at branch and add them to lake.
		while(branch.size() > 0) {
			if(branch.back() == needed) {
				branch.pop_back();
				needed++;
			}else {
				// The car at the branch is not the right one.
				break;
			}
		}

		if(branch.size() > 0) {
			cout << "N" << endl;
		}else {
			cout << "Y" << endl;
		}

	}

  return 0;
}