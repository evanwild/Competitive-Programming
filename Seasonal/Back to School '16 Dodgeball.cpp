#include <iostream>
#include <string>

int main() {

	int n;
	std::cin >> n;

	char* names = new char[n];

	for(int i = 0; i < n; i++) {
		std::string name;
		std::cin >> name;
		names[i] = name[0];
	}


	int choices = 0;

	for(int set_size = 1; set_size <= n; set_size++) {
		
		bool still_are_all_same = false;

		for(int i = 0; i < n; i+=1) {

			bool all_same = true;

			for(int j = i+1; j < i+set_size; j++) {
				if(names[j] != names[j-1]) {
					all_same = false;
					break;
				}
			}

			if(all_same) {
				still_are_all_same = true;
				choices++;
			}

		}

		if(!still_are_all_same) {
			break;
		}

	}

	std::cout << choices % 1000000007 << std::endl;

	delete [] names;

	return 0;
}