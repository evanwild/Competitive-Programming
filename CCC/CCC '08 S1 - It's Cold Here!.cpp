#include <iostream>
#include <string>

using namespace std;

int main() {

  string city;
  int temp;

  string coldest_city;
  int coldest_temp = 201;

  do {
    cin >> city >> temp;
    if(temp < coldest_temp) {
      coldest_temp = temp;
      coldest_city = city;
    }
  }while(city != "Waterloo");

  cout << coldest_city << endl;

  return 0;
}