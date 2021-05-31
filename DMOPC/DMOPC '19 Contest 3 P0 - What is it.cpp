#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    for(int loop = 0; loop < n; loop++) {

        int a[10];

        for(int i = 0; i < 10; i++) {
            cin >> a[i];
        }   

        bool is_ari = true;

        for(int i = 0; i < 8; i++) {
            if(a[i]+a[i+2] != 2*a[i+1]) {
                is_ari = false;
                break;
            }
        }

        bool is_geo = true;

        for(int i = 2; i < 8; i++) {
            if(a[i]*a[i+2] != a[i+1]*a[i+1]) {
                is_geo = false;
                break;
            }
        }
        
        if(is_ari && is_geo) {
            cout << "both" << endl;
        }else if(is_ari) {
            cout << "arithmetic" << endl;
        }else if(is_geo) { 
            cout << "geometric" << endl;
        }else {
            cout << "neither" << endl;
        }

    }

    return 0;
}