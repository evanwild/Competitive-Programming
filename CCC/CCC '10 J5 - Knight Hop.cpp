#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Knight {
public:
	int x;
	int y;
	Knight(int x_val, int y_val) {
		x = x_val;
		y = y_val;
	}
	vector<Knight> possible_moves() {

		vector<Knight> return_vector;

		for(int x_change = -2; x_change <= 2; x_change++) {
			for(int y_change = -2; y_change <= 2; y_change++) {

				// Ignore moves diagonally
				if(abs(x_change) == abs(y_change))
					continue;
                
				// Ignore moves horizontal or vertical
				if(x_change == 0 || y_change == 0)
					continue;

				if(x + x_change < 1 || x + x_change > 8 || y + y_change < 1 || y + y_change > 8)
					continue;
   
				return_vector.push_back(Knight(x+x_change, y+y_change));
                    
			}
		}
		return return_vector;
	}
};

int main() {
    
    int start_x, start_y;
    cin >> start_x >> start_y;
    
    int end_x, end_y;
    cin >> end_x >> end_y;
    
    vector<Knight> knights;
    
    knights.push_back(Knight(start_x, start_y));
    
    int moves = 0;
    while(true) {

		for(int i = 0; i < knights.size(); i++) {
			if(knights[i].x == end_x && knights[i].y == end_y) {
				cout << moves << endl;
				goto end;
			}
		}

		int knights_size = knights.size();

		for(int i = 0; i < knights_size; i++) {
			
			vector<Knight> possible_moves = knights[i].possible_moves();

			for(int j = 0; j < possible_moves.size(); j++) {
				knights.push_back(possible_moves[j]);
			}

		}
        
		moves++;
	}

	end:
           
    return 0;
}