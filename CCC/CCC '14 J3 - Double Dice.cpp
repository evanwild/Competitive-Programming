#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int antonia_score = 100;
    int david_score = 100;

    for(int i = 0; i < n; i++) {

        int a;
        int d;

        cin >> a >> d;

        if(a > d) {
            david_score -= a;
        }else if(d > a) {
            antonia_score -= d;
        }

    }

    cout << antonia_score << std::endl;
    cout << david_score << std::endl;

    return 0;
}