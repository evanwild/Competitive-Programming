#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int> > graph;

int solve(int n) {
    if(graph[n].size() == 0) {
        return 1;
    }
    int ans = 1;
    for(int node : graph[n]) {
        ans *= solve(node) + 1;
    }
    return ans;
}

int main() {

    int n;
    cin >> n;

    int j;
    for(int i = 1; i < n; i++) {
        cin >> j;
        if(graph.count(j)) {
            graph[j].push_back(i);
        }else {
            graph[j] = vector<int>{i};
        }
    }

    cout << solve(n) << endl;
    
    return 0;
}