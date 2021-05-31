#include <bits/stdc++.h>

using namespace std;

int N;
double Ax, Ay, Bx, By, Cx, Cy;

double dist(double Ax, double Bx, double Ay, double By) {
    return sqrt((By-Ay)*(By-Ay) + (Bx-Ax)*(Bx-Ax));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    while(N--) {
        cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

        double a = dist(Bx, Cx, By, Cy);
        double b = dist(Ax, Cx, Ay, Cy);
        double c = dist(Ax, Bx, Ay, By);

        double angleA = acos((b*b + c*c - a*a) / (2.0 * b * c));
        double h = b * sin(angleA);

        cout << fixed << setprecision(3);
        cout << c*h/2.0 << ' ' << a+b+c << '\n';
    }
}