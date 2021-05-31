#include <iostream>
#include <string>

int main() {

	int n;
	std::cin >> n;

	while(n--) {
		std::string line;
		std::cin >> line;

		while(line != "") {
			char c = line.at(0);
			int i = 1;

			while(i < line.length() && line.at(i) == c)
				i++;
	
			std::cout << i << " " << c << " ";

			line.erase(0, i);	
		}
		std::cout << std::endl;
	}

	return 0;
}