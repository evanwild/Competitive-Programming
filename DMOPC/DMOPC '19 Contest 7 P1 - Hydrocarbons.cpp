#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    int carbon = a + b + c + 1;
    int spots = carbon*4 - a*2 - b*4 - c*6 - d;
    if(spots == 0)
        printf("C%dH%d\n", carbon, d);
    else
        printf("invalid\n");
}