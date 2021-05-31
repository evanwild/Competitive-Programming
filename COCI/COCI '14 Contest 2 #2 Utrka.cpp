#include <iostream>
#include <algorithm>

using namespace std;

string names[100005];
string names2[100005];

int main() {

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> names[i];
    }

    for(int i = 0; i < n-1; i++) {
        cin >> names2[i];
    }

    sort(names, names+n);
    sort(names2, names2+n-1);

    if(names[n-1] != names2[n-2]) {
        cout << names[n-1] << endl;
    }else {
        for(int i = 0; i < n-1; i++) {
            if(names2[i] != names[i]) {
                cout << names[i] << endl;
                break;
            }
        }
    }

    return 0;
}