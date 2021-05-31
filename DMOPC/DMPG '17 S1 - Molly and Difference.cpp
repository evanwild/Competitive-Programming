#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int n;
    cin >> n;
    
    int *a = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];    
    }
    
    sort(a, a+n);
    
    int min_d = abs(a[0]-a[1]);
    
    for(int i = 0; i < n-1; i++)
        if(abs(a[i]-a[i+1]) < min_d)
            min_d = abs(a[i]-a[i+1]);
    
    cout << min_d << endl;
    
    return 0;
}