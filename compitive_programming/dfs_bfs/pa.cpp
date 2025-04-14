#include <bits/stdc++.h>
using namespace std;

const int Max = 10005;
vector<int> graph[Max];

int cnt = 0;
bool vis[Max];

void dfs(int z) {
	vis[z] = true;
	cnt++;
	for(int i = 0; i < graph[z].size(); i++) {
		if(!vis[graph[z][i]]) dfs(graph[z][i]);
	}
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
	int t, n, m, l, x, y, z;
	cin >> t;
	while(t--) {
		cnt = 0;
		cin >> n >> m >> l;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
		}
		
		for(int i = 0; i < l; i++) {
			cin >> z;
			if(!vis[z]) dfs(z);
		}
		cout << cnt << '\n';
		fill(vis, vis + n + 1, false);
		for(int i = 0; i < n; i++) graph[i].clear();
	
	}
	return 0;
}