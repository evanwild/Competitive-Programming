#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

map<int, vector<int> > graph;

int distance(int s, int e) {
    bool visited[401] = {false};
    int layer[401];
    queue<int> q;
    q.push(s);
    visited[s] = true;
    layer[s] = 0;
    while(!q.empty()) {
        s = q.front();
        q.pop();
        for(auto node : graph[s]) {
            if(node == e) {
                return layer[s]+1;
            }
            if(!visited[node]) {
                q.push(node);
                visited[node] = true;
                layer[node] = layer[s]+1;
            }
        }
    }
}

int main() {

    int n, m, t;
    cin >> n >> m >> t;

    char school[21][21];
    vector<int> hiders;
    int griffy_start;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> school[i][j];
            if(school[i][j] == 'H') {
                hiders.push_back((i-1)*m + j);
            }else if(school[i][j] == 'G') {
                griffy_start = (i-1)*m + j;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(school[i][j] == 'X') continue;
            int num = (i-1)*m + j;
            graph[num] = vector<int>();
            if(i != 1 && school[i-1][j] != 'X') graph[num].push_back(num-m); // up
            if(i != n && school[i+1][j] != 'X') graph[num].push_back(num+m); // down
            if(j != 1 && school[i][j-1] != 'X') graph[num].push_back(num-1); // left
            if(j != m && school[i][j+1] != 'X') graph[num].push_back(num+1); // right
        }
    }

    int best_time = 1000000;

    do {

        int time = distance(griffy_start, hiders.at(0));
        for(int i = 0; i < hiders.size()-1; i++) {
            time += distance(hiders[i], hiders[i+1]);
        }

        // for(auto person : hiders) {
        //     cout << person << " ";
        // }
        // cout << endl;
        // cout << time << endl;

        if(time < best_time) {
            best_time = time;
        }

    }while(next_permutation(hiders.begin(), hiders.end()));

    cout << best_time << endl;

    return 0;
}