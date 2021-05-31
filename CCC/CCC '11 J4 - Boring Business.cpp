#include <iostream>

using namespace std;

int main() {
    
    int ground[300][800];
    
    ground[1][200] = true;
    ground[2][200] = true;
    ground[3][200] = true;
    ground[3][201] = true;
    ground[3][202] = true;
    ground[3][203] = true;
    ground[4][203] = true;
    ground[5][203] = true;
    ground[5][204] = true;
    ground[5][205] = true;
    ground[4][205] = true;
    ground[3][205] = true;
    ground[3][206] = true;
    ground[3][207] = true;
    ground[4][207] = true;
    ground[5][207] = true;
    ground[6][207] = true;
    ground[7][207] = true;
    ground[7][206] = true;
    ground[7][205] = true;
    ground[7][204] = true;
    ground[7][203] = true;
    ground[7][202] = true;
    ground[7][201] = true;
    ground[7][200] = true;
    ground[7][199] = true;
    ground[6][199] = true;
    ground[5][199] = true;
    
    int my_row = 5;
    int my_col = 199;
    
    bool do_output = true;
    
    while(true) {
        char command;
        cin >> command;
        
        if(command == 'q')
            break;
            
        int dist;
        cin >> dist;
        
        bool danger = false;
        if(command == 'l') {
            for(int i = 0; i < dist; i++) {
                my_col -= 1;
                if(ground[my_row][my_col]) {
                    danger = true;
                }
                ground[my_row][my_col] = true;
            }
        }
        if(command == 'd') {
            for(int i = 0; i < dist; i++) {
                my_row += 1;
                if(ground[my_row][my_col]) {
                    danger = true;
                }
                ground[my_row][my_col] = true;
            }
        }
        if(command == 'r') {
            for(int i = 0; i < dist; i++) {
                my_col += 1;
                if(ground[my_row][my_col]) {
                    danger = true;
                }
                ground[my_row][my_col] = true;
            }
        }
        if(command == 'u') {
            for(int i = 0; i < dist; i++) {
                my_row -= 1;
                if(ground[my_row][my_col]) {
                    danger = true;
                }
                ground[my_row][my_col] = true;
            }
        }
        
        if(danger && do_output) {
            cout << my_col-200 << " -" << my_row << " DANGER" << endl;
            do_output = false;
        }else if(do_output) {
            cout << my_col-200 << " -" << my_row << " safe" << endl;
        }
    }

    return 0;
}