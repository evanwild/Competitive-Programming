#include <bits/stdc++.h>
using namespace std;
#define LL long long

double average(double x, double y)
{
  return (x + y) / 2.0;
}

double average(double x, double y, double z)
{
  return (x + y + z) / 3.0;
}

double average(double x, double y, double z, double a)
{
  return (x + y + z + a) / 4.0;
}

int main() {

  double A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << fixed << setprecision(6) << average(A, B) << "\n";
  cout << fixed << setprecision(6) << average(A, C) << "\n";
  cout << fixed << setprecision(6) << average(A, D) << "\n";
  cout << fixed << setprecision(6) << average(B, C) << "\n";
  cout << fixed << setprecision(6) << average(B, D) << "\n";
  cout << fixed << setprecision(6) << average(C, D) << "\n";
  cout << fixed << setprecision(6) << average(A, B, C) << "\n";
  cout << fixed << setprecision(6) << average(A, B, D) << "\n";
  cout << fixed << setprecision(6) << average(A, C, D) << "\n";
  cout << fixed << setprecision(6) << average(B, C, D) << "\n";
  cout << fixed << setprecision(6) << average(A, B, C, D) << "\n";

  return 0;
}