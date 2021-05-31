#include <bits/stdc++.h>
using namespace std;

int n;
int max_index = 0;
double d = 0;

double x[11], y[11];

double dist(int a, int b) {
    return (y[a]-y[b])*(y[a]-y[b]) + (x[a]-x[b])*(x[a]-x[b]);
}

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            d = max(d, dist(i, j));

    x[10] = x[0];
    y[10] = y[0];

    for (int T = 0; T < 700; ++T) {
        for (int i = 0; i < n; ++i)
            if (dist(10, i) > dist(10, max_index))
                max_index = i;

        double ratio = d/dist(10, max_index);
        x[10] = (1.00 - ratio)*x[10] + ratio*x[max_index];
        y[10] = (1.00 - ratio)*y[10] + ratio*y[max_index];

        d *= 0.98;
    }

    cout << fixed << setprecision(2);
    cout << sqrt(dist(10, max_index))*2 << '\n';

    return 0;
}