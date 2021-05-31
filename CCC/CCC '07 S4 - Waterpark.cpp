#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
map<int, vector<int> > graph;
bool dp[10000] = {false};
int dp_val[10000];

int ways(int point) {

    if(dp[point]) return dp_val[point];

    int result = 0;

    if(point == n) {
        result = 1;
    }else 
    if(graph[point].size() == 0) {
        result = 0;
    }else {
        for(size_t i = 0; i < graph[point].size(); i++) {
            result += ways(graph[point][i]);
        }
    }

    dp[point] = true;
    dp_val[point] = result;

    return result;
}

int main() {

    cin >> n;

    while(true) {
        int start, end;
        cin >> start >> end;

        if(start == 0 && end == 0) {
            break;
        }
        else if(graph.count(start) > 0) {
            graph[start].push_back(end);
        }else {
            graph[start] = vector<int>{end};
        }
    }

    cout << ways(1) << endl;

    return 0;
}