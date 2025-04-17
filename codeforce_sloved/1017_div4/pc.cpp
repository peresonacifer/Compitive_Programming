#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    int grid[n][n];
    bool vis[2 * n + 1];
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            vis[grid[i][j]] = true;
        }
    }
    for(int i = 1; i <= 2 * n ;i++) {
        if(!vis[i]) cout << i << " ";
    }
    for(int j = 0; j < n; j++) cout << grid[0][j] << " ";
    for(int i = 1; i < n; i++) cout << grid[i][n - 1] << (i == n - 1 ? "" : " ");
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}