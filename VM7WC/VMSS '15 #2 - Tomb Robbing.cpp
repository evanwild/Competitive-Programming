#include <iostream>

using namespace std;

int r, c;
char tomb[100][100] = {false};

void fill_room(int i, int j) {
    tomb[i][j] = 'X';
    if(i!=0&&tomb[i-1][j]=='.') {
        fill_room(i-1, j);
    }
    if(i!=r-1&&tomb[i+1][j]=='.') {
        fill_room(i+1, j);
    }
    if(j!=0&&tomb[i][j-1]=='.') {
        fill_room(i, j-1);
    }
    if(j!=c-1&&tomb[i][j+1]=='.') {
        fill_room(i, j+1);
    }
}

int main() {

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> tomb[i][j];
        }
    }

    int ans=0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(tomb[i][j] == '.') {
                fill_room(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}