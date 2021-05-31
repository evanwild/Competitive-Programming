#include <iostream>
#include <algorithm>

using namespace std;

int freq[200010] = {0};

int main() {

    int n;
    cin >> n;
    
    int input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        freq[input+100000]++;
    }

    int most = *max_element(freq, freq+200010);

    for(int i = 0; i < 200010; i++) {
        if(freq[i] == most) {
            cout << (i - 100000) << " ";
        }
    }

    cout << endl;

    return 0;
}