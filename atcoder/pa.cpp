#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    vector<int> idx(m);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        idx[i] = x;
        for(int j = 0; j < x; j++) {
            int y;
            cin >> y;
            v[y].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < v[x].size(); j++) {
            idx[v[x][j]]--;
            if(idx[v[x][j]] == 0) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}