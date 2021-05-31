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
#define DEBUG(x) cout << #x << ": " << x << endl
#define GRAPH unordered_map<int, VI>
#define WEIGHTED_GRAPH map<int, VPII> // First is node, second is weight
#define INF 2147483647
#define endl '\n'

GRAPH graph;

int dist_to_c[100005];

void bfs(int start) {
    queue<int> to_visit;
    bool visited[100005] = {false};

    visited[start] = true;
    to_visit.push(start);
    dist_to_c[start] = 0;

    while(!to_visit.empty()) {
        int current = to_visit.front();
        to_visit.pop();

        for(const int &node : graph[current]) {
            if(!visited[node]) {
                dist_to_c[node] = dist_to_c[current] + 1;
                visited[node] = true;
                to_visit.push(node);
            }
        }
    }
}

int main() {

    memset(dist_to_c, -1, sizeof(dist_to_c));

    int n, m, q, c;
    scanf("%d%d%d%d", &n, &m, &q, &c);

    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        graph[u].PB(v);
        graph[v].PB(u);
    }

    bfs(c);

    int a, b;
    while(q--) {
        scanf("%d%d", &a, &b);
        if(dist_to_c[a] == -1 || dist_to_c[b] == -1) {
            printf("This is a scam!\n");
        }else {
            printf("%d\n", dist_to_c[a] + dist_to_c[b]);
        }
    }

    return 0;
}