#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long
#define VI vector<int>
#define VLL vector<LL>
#define PII pair<int, int>
#define VPII vector<PII>
#define VS vector<string>
#define DEBUG(x) cout << #x << ": " << x << endl
#define GRAPH map<string, VS>
#define WEIGHTED_GRAPH map<int, VPII> // First is node, second is weight
#define INF 2147483647
#define endl '\n'

GRAPH graph;

string bfs(string start, string end) {
    queue<string> to_visit;
    unordered_set<string> visited;
    unordered_map<string, string> directions;

    visited.insert(start);
    to_visit.push(start);

    while(!to_visit.empty()) {
        string current = to_visit.front();
        to_visit.pop();

        for(const string &node : graph[current]) {
            if(visited.find(node) == visited.end()) {
                directions[node] = directions[current] + node[0];
                visited.insert(node);
                to_visit.push(node);
            }
        }
    }

    return start[0] + directions[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    string first, second;
    while(m--) {
        cin >> first >> second;
        graph[first].PB(second);
        graph[second].PB(first);
    }

    while(n--) {
        cin >> first >> second;
        cout << bfs(first, second) << endl;
    }

    return 0;
}