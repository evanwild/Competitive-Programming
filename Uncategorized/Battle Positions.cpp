#include <iostream>

using namespace std;

int main() {

    int num_stations, min_troops, num_waves;
    cin >> num_stations >> min_troops >> num_waves;

    int *diff = new int[num_stations]();

    for(int i = 0; i < num_waves; i++) {
        int xi, xf, k;
        cin >> xi >> xf >> k;
        diff[xi-1] += k;
        diff[xf] -= k;
    }

    int *stations = new int[num_stations];
    for(int i = 0; i < num_stations; i++) {
        if(i == 0) stations[i] = diff[i];
        else stations[i] = diff[i] + stations[i-1];
    }
    delete [] diff;

    int total = 0;
    for(int i = 0; i < num_stations; i++) {
        if(stations[i] < min_troops) total++;
    }

    cout << total << endl;

    delete [] stations;

    return 0;
}