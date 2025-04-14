#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph(n);

void dfs() {

}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    dfs()



}