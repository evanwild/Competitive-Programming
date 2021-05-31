#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n*5; j++) {
            cout << "G";
        }
        cout << "\n";
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n*5; j++) {
            if(j < n) cout << "G";
            else cout << ".";
        }
        cout << "\n";
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n*5; j++) {
            if(j < n || j >= n*3) cout << "G";
            else cout << ".";
        }
        cout << "\n";
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n*5; j++) {
            if(j < n || j >= n*4) cout << "G";
            else cout << ".";
        }
        cout << "\n";
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n*5; j++) {
            cout << "G";
        }
        cout << "\n";
    }
    return 0;
}