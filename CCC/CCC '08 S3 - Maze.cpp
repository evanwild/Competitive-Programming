#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int r, c;

int bfs(map<int, vector<int>> graph) {
    bool visited[401] = {false, true}; // Set first element to visited (w/ garbage at 0).
    queue<int> q;
    q.push(1);
    map<int, int> layer;
    layer[1] = 1;
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        for(int adjacent : graph[s]) {
            if(adjacent == r*c) {
                return layer[s]+1;
            }
            if(!visited[adjacent]) {
                visited[adjacent] = true;
                q.push(adjacent);
                layer[adjacent] = layer[s]+1;
            }
        }
    }
    return -1;
}

int main() {

    int t;
    cin >> t;

    while(t--) {

        cin >> r >> c;
        char city[21][21];

        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cin >> city[i][j];
            }
        }

        map<int, vector<int>> graph;
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(city[i][j] == '*') continue;
                int num = (i-1)*c + j;
                graph[num] = vector<int>{};
                if(city[i][j] == '+') {
                    if(i != 1 && city[i-1][j] != '*') graph[num].push_back(num-c); // up
                    if(i != r && city[i+1][j] != '*') graph[num].push_back(num+c); // down
                    if(j != 1 && city[i][j-1] != '*') graph[num].push_back(num-1); // left
                    if(j != c && city[i][j+1] != '*') graph[num].push_back(num+1); // right
                }else if(city[i][j] == '-') {
                    if(j != 1 && city[i][j-1] != '*') graph[num].push_back(num-1); // left
                    if(j != c && city[i][j+1] != '*') graph[num].push_back(num+1); // right
                }else {
                    if(i != 1 && city[i-1][j] != '*') graph[num].push_back(num-c); // up
                    if(i != r && city[i+1][j] != '*') graph[num].push_back(num+c); // down
                }
            }
        }

        if(r == 1 && c == 1) cout << 1 << endl;
        else cout << bfs(graph) << endl;
    }

    return 0;
}