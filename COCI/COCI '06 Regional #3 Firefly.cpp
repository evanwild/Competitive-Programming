#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, h;
    cin >> n >> h;

    int *diff = new int[h]();

    for(int i = 0; i < n/2; i++) {
        int height;
        cin >> height;
        diff[0] += 1;
        diff[height] -= 1;
        cin >> height;
        diff[h-height] += 1;
        diff[h] -= 1;
    }

    int *obstacles = new int[h];
    for(int i = 0; i < h; i++) {
        if(i == 0) obstacles[i] = diff[i];
        else obstacles[i] = diff[i] + obstacles[i-1];
    }
    delete [] diff;

    sort(obstacles, obstacles+h);

    cout << obstacles[0] << " ";

    int total = 1;
    for(int i = 1; i < h; i++) {
        if(obstacles[i] == obstacles[i-1]) total++;
        else break;
    }

    cout << total << endl;

    delete [] obstacles;

    return 0;
}