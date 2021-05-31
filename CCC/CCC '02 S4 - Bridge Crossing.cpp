#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int m, q;
string names[101];
int times[101];
 
bool dp[101] = {false};
int dp_val[101];
int best_group_size[101];

void print_groups(int person) {
    if(person <= q) {
        for(int i = person; i <= person+best_group_size[person]-1; i++) {
            cout << names[i] << " ";
        }
        cout << endl;
        print_groups(person+best_group_size[person]);
    }
}

int min_time(int person) {
 
 if(dp[person]) return dp_val[person];
 
 int result;
 
 if(person > q) result = 0;
 else {
   result = 100000000;
 for(int g_size = 1; g_size <= m; g_size++) {
   if(person + g_size != q+2) {

       int new_time = *max_element(times+person, times+person+g_size)+min_time(person+g_size);

        if(new_time < result) {
            result = new_time;
            best_group_size[person] = g_size;
        }
   }
 }
 }
 
 dp[person] = true;
 dp_val[person] = result;
 
 return result;
}
 
int main() {
 
 cin >> m >> q;
 
 for(int i = 1; i <= q; i++) {
   cin >> names[i] >> times[i];
 }
 
 cout << "Total Time: " << min_time(1) << endl;

 print_groups(1);
 
 return 0;
}