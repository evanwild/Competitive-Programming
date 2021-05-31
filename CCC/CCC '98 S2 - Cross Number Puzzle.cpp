#include <bits/stdc++.h>

using namespace std;

bool solve1(int i) {
    int sum = 0;
    for(int j = 1; j < i; j++)
        if(i % j == 0)
            sum += j;
    return (sum == i);
}

bool solve2(int i) {
    int sum = 0, i2=i;
    while(i) {
        sum += (i%10)*(i%10)*(i%10);
        i /= 10;
    }
    return (sum == i2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for(int i = 1000; i <= 9999; i++)
        if(solve1(i))
            cout << i << " ";
    cout << '\n';

    for(int i = 100; i <= 999; i++)
        if(solve2(i))
            cout << i << " ";
    cout << '\n';
}